// ImageConvolutionDoc.cpp : implementation of the CImageConvolutionDoc class
//

#include "stdafx.h"
#include "ImageConvolution.h"

#include "ImageConvolutionDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionDoc

IMPLEMENT_DYNCREATE(CImageConvolutionDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageConvolutionDoc, CDocument)
	//{{AFX_MSG_MAP(CImageConvolutionDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionDoc construction/destruction

CImageConvolutionDoc::CImageConvolutionDoc()
{
	// TODO: add one-time construction code here

}

CImageConvolutionDoc::~CImageConvolutionDoc()
{
}

BOOL CImageConvolutionDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_szFilename = _T("");
	m_bGrayscale = TRUE;
	m_bKernelLoaded = FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionDoc serialization

void CImageConvolutionDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionDoc diagnostics

#ifdef _DEBUG
void CImageConvolutionDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageConvolutionDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionDoc commands

BOOL CImageConvolutionDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	m_szFilename  = lpszPathName;
	m_bKernelLoaded = FALSE;
	
	return TRUE;
}
