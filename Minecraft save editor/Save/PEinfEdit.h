// PEinfEdit.h : main header file for the PEINFEDIT application
//

#if !defined(AFX_PEINFEDIT_H__C50F3506_20CF_44E7_AD20_D2B43AA136A6__INCLUDED_)
#define AFX_PEINFEDIT_H__C50F3506_20CF_44E7_AD20_D2B43AA136A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPEinfEditApp:
// See PEinfEdit.cpp for the implementation of this class
//

class CPEinfEditApp : public CWinApp
{
public:
	CPEinfEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPEinfEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPEinfEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PEINFEDIT_H__C50F3506_20CF_44E7_AD20_D2B43AA136A6__INCLUDED_)
