// ImageConvolutionDoc.h : interface of the CImageConvolutionDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGECONVOLUTIONDOC_H__0BB66589_BA33_4085_9769_0C5154BF5720__INCLUDED_)
#define AFX_IMAGECONVOLUTIONDOC_H__0BB66589_BA33_4085_9769_0C5154BF5720__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImageConvolutionDoc : public CDocument
{
protected: // create from serialization only
	CImageConvolutionDoc();
	DECLARE_DYNCREATE(CImageConvolutionDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageConvolutionDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString m_szFilename;
	BOOL m_bKernelLoaded;
	BOOL m_bGrayscale;
	virtual ~CImageConvolutionDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImageConvolutionDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGECONVOLUTIONDOC_H__0BB66589_BA33_4085_9769_0C5154BF5720__INCLUDED_)
