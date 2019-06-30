// EntitiesDlg.h : header file
//

#if !defined(AFX_ENTITIESDLG_H__761C7B8F_1813_4F8E_BEF0_9784D9A105C7__INCLUDED_)
#define AFX_ENTITIESDLG_H__761C7B8F_1813_4F8E_BEF0_9784D9A105C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEntitiesDlg dialog

class CEntitiesDlg : public CDialog
{
// Construction
public:
	CEntitiesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEntitiesDlg)
	enum { IDD = IDD_ENTITIES_DIALOG };
	CString strEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEntitiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEntitiesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onopenentitiesdat();
	afx_msg void OnSelchangeentity();
	afx_msg void Ondeleteentities();
	afx_msg void Onnothing();
	afx_msg void OnOld();
	afx_msg void Onyoung();
	afx_msg void Oncolour();
	afx_msg void Onreplace();
	afx_msg void Onsaveall();
	afx_msg void Onmakepig();
	afx_msg void Oncancelpig();
	afx_msg void Onpage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTITIESDLG_H__761C7B8F_1813_4F8E_BEF0_9784D9A105C7__INCLUDED_)
