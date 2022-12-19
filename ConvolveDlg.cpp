// ConvolveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageConvolution.h"
#include "ConvolveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConvolveDlg dialog


CConvolveDlg::CConvolveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvolveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConvolveDlg)
	m_r1c1 = "0.0f";
	m_r1c2 = "0.0f";
	m_r1c3 = "0.0f";
	m_r2c1 = "0.0f";
	m_r2c2 = "0.0f";
	m_r2c3 = "0.0f";
	m_r3c1 = "0.0f";
	m_r3c2 = "0.0f";
	m_r3c3 = "0.0f";
	m_bias = 0;
	//}}AFX_DATA_INIT
}


void CConvolveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConvolveDlg)
	DDX_Text(pDX, IDC_ROW1COL1, m_r1c1);
	DDX_Text(pDX, IDC_ROW1COL2, m_r1c2);
	DDX_Text(pDX, IDC_ROW1COL3, m_r1c3);
	DDX_Text(pDX, IDC_ROW2COL1, m_r2c1);
	DDX_Text(pDX, IDC_ROW2COL2, m_r2c2);
	DDX_Text(pDX, IDC_ROW2COL3, m_r2c3);
	DDX_Text(pDX, IDC_ROW3COL1, m_r3c1);
	DDX_Text(pDX, IDC_ROW3COL2, m_r3c2);
	DDX_Text(pDX, IDC_ROW3COL3, m_r3c3);
	DDX_Text(pDX, IDC_BIAS, m_bias);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConvolveDlg, CDialog)
	//{{AFX_MSG_MAP(CConvolveDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvolveDlg message handlers
