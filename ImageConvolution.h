// ImageConvolution.h : main header file for the IMAGECONVOLUTION application
//

#if !defined(AFX_IMAGECONVOLUTION_H__381B8AE6_5423_43D8_BA05_A72CD07108C1__INCLUDED_)
#define AFX_IMAGECONVOLUTION_H__381B8AE6_5423_43D8_BA05_A72CD07108C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageConvolutionApp:
// See ImageConvolution.cpp for the implementation of this class
//

class CImageConvolutionApp : public CWinApp
{
public:
	CImageConvolutionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageConvolutionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CImageConvolutionApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGECONVOLUTION_H__381B8AE6_5423_43D8_BA05_A72CD07108C1__INCLUDED_)
