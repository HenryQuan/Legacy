#if !defined(AFX_REPLACE_H__87BF0DF3_2090_441D_8089_68026DD05DEB__INCLUDED_)
#define AFX_REPLACE_H__87BF0DF3_2090_441D_8089_68026DD05DEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Replace.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReplace dialog

class CReplace : public CDialog
{
// Construction
public:
	CReplace(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReplace)
	enum { IDD = IDD_replaceentities };
	CString replace;
	CString yang;
	CString niu;
	CString zhu;
	CString ji;
	CString jiangshi;
	CString kulou;
	CString zhuren;
	CString zhizhu;
	CString kulipa;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplace)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReplace)
	afx_msg void OnOK();
	afx_msg void Onenid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLACE_H__87BF0DF3_2090_441D_8089_68026DD05DEB__INCLUDED_)
