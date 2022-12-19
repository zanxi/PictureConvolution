#if !defined(AFX_CONVOLVEDLG_H__03FD4854_9CBA_409E_8451_A17AE9ABE2F4__INCLUDED_)
#define AFX_CONVOLVEDLG_H__03FD4854_9CBA_409E_8451_A17AE9ABE2F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConvolveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConvolveDlg dialog

class CConvolveDlg : public CDialog
{
// Construction
public:
	CConvolveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConvolveDlg)
	enum { IDD = IDD_DLGCONVOLVE };
	CString	m_r1c1;
	CString	m_r1c2;
	CString	m_r1c3;
	CString	m_r2c1;
	CString	m_r2c2;
	CString	m_r2c3;
	CString	m_r3c1;
	CString	m_r3c2;
	CString	m_r3c3;
	int		m_bias;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvolveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConvolveDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVOLVEDLG_H__03FD4854_9CBA_409E_8451_A17AE9ABE2F4__INCLUDED_)
