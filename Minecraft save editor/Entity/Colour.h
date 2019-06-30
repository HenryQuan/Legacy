#if !defined(AFX_COLOUR_H__919A23B7_3C5C_4CDC_BB96_FBA5570BFC1D__INCLUDED_)
#define AFX_COLOUR_H__919A23B7_3C5C_4CDC_BB96_FBA5570BFC1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Colour.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColour dialog

class CColour : public CDialog
{
// Construction
public:
	CColour(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CColour)
	enum { IDD = IDD_colour };
	CString color;
	int sheepnum;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColour)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColour)
	afx_msg void Onok();
	afx_msg void Onid();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOUR_H__919A23B7_3C5C_4CDC_BB96_FBA5570BFC1D__INCLUDED_)
