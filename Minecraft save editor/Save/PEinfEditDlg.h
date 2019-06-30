// PEinfEditDlg.h : header file
//

#if !defined(AFX_PEINFEDITDLG_H__E4C33D09_409C_45AF_B14B_C2A103B9249C__INCLUDED_)
#define AFX_PEINFEDITDLG_H__E4C33D09_409C_45AF_B14B_C2A103B9249C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPEinfEditDlg dialog

class CPEinfEditDlg : public CDialog
{
// Construction
public:
	CPEinfEditDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPEinfEditDlg)
	enum { IDD = IDD_PEINFEDIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPEinfEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPEinfEditDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAbout();
	afx_msg void Onleveldat();
	afx_msg void Onmode();
	afx_msg void Onspawnmob();
	afx_msg void Ondaynight();
	afx_msg void Onhurt();
	afx_msg void Onmayfly();
	afx_msg void Onfullhealth();
	afx_msg void Oninfinityhealth();
	afx_msg void Ontime0();
	afx_msg void Ontime9600();
	afx_msg void Oncopyseed();
	afx_msg void Onsave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEINFEDITDLG_H__E4C33D09_409C_45AF_B14B_C2A103B9249C__INCLUDED_)
