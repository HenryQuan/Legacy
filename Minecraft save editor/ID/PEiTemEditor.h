// PEiTemEditor.h : main header file for the PEITEMEDITOR application
//

#if !defined(AFX_PEITEMEDITOR_H__82145DAF_85FD_457E_97B7_2C4AA3966C1A__INCLUDED_)
#define AFX_PEITEMEDITOR_H__82145DAF_85FD_457E_97B7_2C4AA3966C1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorApp:
// See PEiTemEditor.cpp for the implementation of this class
//

class CPEiTemEditorApp : public CWinApp
{
public:
	CPEiTemEditorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPEiTemEditorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPEiTemEditorApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEITEMEDITOR_H__82145DAF_85FD_457E_97B7_2C4AA3966C1A__INCLUDED_)
