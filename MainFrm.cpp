// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ImageConvolution.h"

#include "MainFrm.h"
#include "convolvedlg.h"
#include "ImageConvolutionView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_CONVOLVEIMAGE, OnViewConvolveimage)
	ON_COMMAND(ID_VIEW_EDGEDETECT1, OnViewEdgedetect1)
	ON_COMMAND(ID_VIEW_EDGEDETECT2, OnViewEdgedetect2)
	ON_COMMAND(ID_VIEW_GAUSSIANBLUR, OnViewGaussianblur)
	ON_COMMAND(ID_VIEW_SHARPENIMAGE, OnViewSharpenimage)
	ON_COMMAND(ID_VIEW_SHARPNESSIMAGE, OnViewSharpnessimage)
	ON_COMMAND(ID_VIEW_TRIANGLEBLUR, OnViewTriangleblur)
	ON_COMMAND(ID_VIEW_UNSHARPENIMAGE, OnViewUnsharpenimage)
	ON_COMMAND(ID_VIEW_BOXBLUR, OnViewBoxblur)
	ON_COMMAND(ID_VIEW_GRAYSCALE, OnViewGrayscale)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewConvolveimage() 
{
	// TODO: Add your command handler code here
	CConvolveDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		float kernel[5][5];
		kernel[0][0] = atoi(dlg.m_r1c1);
		kernel[0][1] = atoi(dlg.m_r1c2);
		kernel[0][2] = atoi(dlg.m_r1c3);
		kernel[1][0] = atoi(dlg.m_r2c1);
		kernel[1][1] = atoi(dlg.m_r2c2);
		kernel[1][2] = atoi(dlg.m_r2c3);
		kernel[2][0] = atoi(dlg.m_r3c1);
		kernel[2][1] = atoi(dlg.m_r3c2);
		kernel[2][2] = atoi(dlg.m_r3c3);
		((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,dlg.m_bias);
	}
}

void CMainFrame::OnViewEdgedetect1() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};

	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewEdgedetect2() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};

	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewGaussianblur() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};
		
	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewSharpenimage() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};
	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewSharpnessimage() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};

	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewTriangleblur() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};

	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewUnsharpenimage() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};
	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewBoxblur() 
{
	// TODO: Add your command handler code here
	float kernel[5][5] = {
			1,	4,	6,	4,	1,
			4,	16,	24,	16,	4,
			6,	24,	36,	24,	6,
			4,	16,	24,	16,	4,
			1,	4,	6,	4,	1
	};
	((CImageConvolutionView*)GetActiveView())->ConvolveImage(kernel,0);
}

void CMainFrame::OnViewGrayscale() 
{
	// TODO: Add your command handler code here
	if (!(GetMenuState(GetMenu()->m_hMenu,ID_VIEW_GRAYSCALE,MF_BYCOMMAND) & MF_CHECKED))
	{
		((CImageConvolutionView*)GetActiveView())->GetDocument()->m_bGrayscale = TRUE;
		CheckMenuItem(GetMenu()->m_hMenu,ID_VIEW_GRAYSCALE,MF_BYCOMMAND|MF_CHECKED);
	}
	else
	{
		
		((CImageConvolutionView*)GetActiveView())->GetDocument()->m_bGrayscale = FALSE;
		CheckMenuItem(GetMenu()->m_hMenu,ID_VIEW_GRAYSCALE,MF_BYCOMMAND|MF_UNCHECKED);
	}
	((CImageConvolutionView*)GetActiveView())->Invalidate();
}
