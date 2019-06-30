// Entities.h : main header file for the ENTITIES application
//

#if !defined(AFX_ENTITIES_H__24B689B3_7DEF_44D9_92F3_9EA014A85852__INCLUDED_)
#define AFX_ENTITIES_H__24B689B3_7DEF_44D9_92F3_9EA014A85852__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEntitiesApp:
// See Entities.cpp for the implementation of this class
//

class CEntitiesApp : public CWinApp
{
public:
	CEntitiesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEntitiesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEntitiesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTITIES_H__24B689B3_7DEF_44D9_92F3_9EA014A85852__INCLUDED_)
