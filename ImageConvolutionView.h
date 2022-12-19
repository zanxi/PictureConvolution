// ImageConvolutionView.h : interface of the CImageConvolutionView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGECONVOLUTIONVIEW_H__4B554328_1B29_4E24_9A47_1497402C76A1__INCLUDED_)
#define AFX_IMAGECONVOLUTIONVIEW_H__4B554328_1B29_4E24_9A47_1497402C76A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImageConvolutionDoc.h"

class CImageConvolutionView : public CView
{
protected: // create from serialization only
	CImageConvolutionView();
	DECLARE_DYNCREATE(CImageConvolutionView)

// Attributes
public:
	CImageConvolutionDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageConvolutionView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	COLORREF Convolve(CDC* dc, int sourcex, int sourcey, float kernel[5][5], int nBias,BOOL bGrayscale=FALSE);
	void ConvolveImage(float kernel[5][5], int nBias);
	virtual ~CImageConvolutionView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	float m_kernel[5][5];
	int m_nBias;
	//{{AFX_MSG(CImageConvolutionView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImageConvolutionView.cpp
inline CImageConvolutionDoc* CImageConvolutionView::GetDocument()
   { return (CImageConvolutionDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGECONVOLUTIONVIEW_H__4B554328_1B29_4E24_9A47_1497402C76A1__INCLUDED_)
