// ImageConvolutionView.cpp : implementation of the CImageConvolutionView class
//

#include "stdafx.h"
#include "ImageConvolution.h"

#include "ImageConvolutionDoc.h"
#include "ImageConvolutionView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionView

IMPLEMENT_DYNCREATE(CImageConvolutionView, CView)

BEGIN_MESSAGE_MAP(CImageConvolutionView, CView)
	//{{AFX_MSG_MAP(CImageConvolutionView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionView construction/destruction

CImageConvolutionView::CImageConvolutionView()
{
	// TODO: add construction code here
}

CImageConvolutionView::~CImageConvolutionView()
{
}

BOOL CImageConvolutionView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionView drawing

void CImageConvolutionView::OnDraw(CDC* pDC)
{
	CImageConvolutionDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	if (pDoc->m_szFilename != _T(""))
	{
		if (GetDocument()->m_bKernelLoaded == FALSE)
		{//code copied from Zafir Anjum article on loading bitmaps
			HBITMAP hBitmap = (HBITMAP)::LoadImage(NULL,pDoc->m_szFilename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);

			CBitmap bmp;
			bmp.Attach(hBitmap);

			CClientDC dc(this);
			CDC bmDC;
			bmDC.CreateCompatibleDC(&dc);
			CBitmap *pOldbmp = bmDC.SelectObject(&bmp);

			BITMAP  bi;
			bmp.GetBitmap(&bi);
			dc.BitBlt(0,0,bi.bmWidth,bi.bmHeight,&bmDC,0,0,SRCCOPY);
			bmDC.SelectObject(pOldbmp);
		}
		else
			ConvolveImage(m_kernel,m_nBias);
	
	}
	else
	{
		if (GetDocument()->m_bKernelLoaded == FALSE)
		{
			CBitmap bmp;
			bmp.LoadBitmap(IDB_BITMAP1);

			CClientDC dc(this);
			CDC bmDC;
			bmDC.CreateCompatibleDC(&dc);
			CBitmap *pOldbmp = bmDC.SelectObject(&bmp);

			BITMAP  bi;
			bmp.GetObject(sizeof(bi),&bi);
			dc.BitBlt(0,0,bi.bmWidth,bi.bmHeight,&bmDC,0,0,SRCCOPY);
			bmDC.SelectObject(pOldbmp);
		}
		else
			ConvolveImage(m_kernel,m_nBias);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionView diagnostics

#ifdef _DEBUG
void CImageConvolutionView::AssertValid() const
{
	CView::AssertValid();
}

void CImageConvolutionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageConvolutionDoc* CImageConvolutionView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageConvolutionDoc)));
	return (CImageConvolutionDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionView message handlers

void CImageConvolutionView::ConvolveImage(float kernel[5][5], int nBias)
{
	CWaitCursor wait;
	GetDocument()->m_bKernelLoaded = TRUE;
	m_nBias = nBias;
	memcpy(m_kernel,kernel,sizeof(float)*25);
	//code partially copied from Zafir Anjum article on rotating bitmaps
	//Load bitmap from file
	HBITMAP hBitmap;
	if (GetDocument()->m_szFilename == _T(""))//If no file loaded use bitmap resource
		hBitmap = (HBITMAP)::LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB_BITMAP1),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
	else//else use requested file
		hBitmap = (HBITMAP)::LoadImage(NULL,GetDocument()->m_szFilename,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);

	// Create a memory DC compatible with the display
	CDC sourceDC, destDC;
	sourceDC.CreateCompatibleDC( NULL );
	destDC.CreateCompatibleDC( NULL );

	// Get logical coordinates
	BITMAP bm;
	::GetObject( hBitmap, sizeof( bm ), &bm );


	// Create a bitmap to hold the result
	HBITMAP hbmResult = ::CreateCompatibleBitmap(CClientDC(NULL), bm.bmWidth, bm.bmHeight);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject( sourceDC.m_hDC, hBitmap );
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject( destDC.m_hDC, hbmResult );

	//loop through each pixel
	for( int y = 0; y < bm.bmHeight; y++ )
	{
		for( int x = 0; x < bm.bmWidth; x++ )
		{
			//set pixel to color returned by convolve
			destDC.SetPixel(x,y,Convolve(&sourceDC,x,y,kernel,nBias,GetDocument()->m_bGrayscale));
		}
	}

	// Restore DCs
	::SelectObject( sourceDC.m_hDC, hbmOldSource );
	::SelectObject( destDC.m_hDC, hbmOldDest );

	//make CBitmap from convolution result
	CBitmap bmp;
	bmp.Attach(hbmResult);

	CClientDC dc(this);
	CDC bmDC;
	bmDC.CreateCompatibleDC(&dc);
	CBitmap *pOldbmp = bmDC.SelectObject(&bmp);

	//display result
	BITMAP  bi;
	bmp.GetBitmap(&bi);
	dc.BitBlt(0,0,bi.bmWidth,bi.bmHeight,&bmDC,0,0,SRCCOPY);
	bmDC.SelectObject(pOldbmp);
}

COLORREF CImageConvolutionView::Convolve(CDC* pDC, int sourcex, int sourcey, float kernel[5][5], int nBias,BOOL bGrayscale)
{
	float rSum = 0, gSum = 0, bSum = 0, kSum = 0;
	COLORREF clrReturn = RGB(0,0,0);
	for (int i=0; i <= 4; i++)//loop through rows
	{
		for (int j=0; j <= 4; j++)//loop through columns
		{
			//get pixel near source pixel
			/*
			if x,y is source pixel then we loop through and get pixels at coordinates:
			x-1,y-1
			x-1,y
			x-1,y+1
			x,y-1
			x,y
			x,y+1
			x+1,y-1
			x+1,y
			x+1,y+1
			*/
			COLORREF tmpPixel = pDC->GetPixel(sourcex+(i-(2>>1)),sourcey+(j-(2>>1)));
			//get kernel value
			float fKernel = kernel[i][j];
			//multiply each channel by kernel value, and add to sum
			//notice how each channel is treated separately
			rSum += (GetRValue(tmpPixel)*fKernel);
			gSum += (GetGValue(tmpPixel)*fKernel);
			bSum += (GetBValue(tmpPixel)*fKernel);
			//add the kernel value to the kernel sum
			kSum += fKernel;
		}
	}
	//if kernel sum is less than 0, reset to 1 to avoid divide by zero
	if (kSum <= 0)
		kSum = 1;
	//divide each channel by kernel sum
	rSum/=kSum;
	gSum/=kSum;
	bSum/=kSum;
	//add bias if desired
	rSum += nBias;
	gSum += nBias;
	bSum += nBias;
	//prevent channel overflow by clamping to 0..255
	if (rSum > 255)
		rSum = 255;
	else if (rSum < 0)
		rSum = 0;
	if (gSum > 255)
		gSum = 255;
	else if (gSum < 0)
		gSum = 0;
	if (bSum > 255)
		bSum = 255;
	else if (bSum < 0)
		bSum = 0;
	//return new pixel value
	if (bGrayscale)
	{
		int grayscale=0.299*rSum + 0.587*gSum + 0.114*bSum;
		rSum=grayscale;
		gSum=grayscale;
		bSum=grayscale;
	}

	clrReturn = RGB(rSum,gSum,bSum);
	return clrReturn;
}