// PEiTemEditorDlg.h : header file
//

#if !defined(AFX_PEITEMEDITORDLG_H__835E09C4_AEEF_4C25_8655_FC590DCFD2B4__INCLUDED_)
#define AFX_PEITEMEDITORDLG_H__835E09C4_AEEF_4C25_8655_FC590DCFD2B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorDlg dialog

class CPEiTemEditorDlg : public CDialog
{
// Construction
public:
	CPEiTemEditorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPEiTemEditorDlg)
	enum { IDD = IDD_PEITEMEDITOR_DIALOG };
	CComboBox	m_item;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPEiTemEditorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPEiTemEditorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onopenlevedat();
	afx_msg void OnSelchangeitem();
	afx_msg void Onsavechange();
	afx_msg void OnSaveAl();
	afx_msg void Onfullnum();
	afx_msg void Onfulldamage();
	afx_msg void OnMenuitem32774();
	afx_msg void OnID();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEITEMEDITORDLG_H__835E09C4_AEEF_4C25_8655_FC590DCFD2B4__INCLUDED_)
