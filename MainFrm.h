// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__90496B98_9E83_481E_89A4_7EF84AAC5E0D__INCLUDED_)
#define AFX_MAINFRM_H__90496B98_9E83_481E_89A4_7EF84AAC5E0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewConvolveimage();
	afx_msg void OnViewEdgedetect1();
	afx_msg void OnViewEdgedetect2();
	afx_msg void OnViewGaussianblur();
	afx_msg void OnViewSharpenimage();
	afx_msg void OnViewSharpnessimage();
	afx_msg void OnViewTriangleblur();
	afx_msg void OnViewUnsharpenimage();
	afx_msg void OnViewBoxblur();
	afx_msg void OnViewGrayscale();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__90496B98_9E83_481E_89A4_7EF84AAC5E0D__INCLUDED_)
