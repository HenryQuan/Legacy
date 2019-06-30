// PEiTemEditor.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PEiTemEditor.h"
#include "PEiTemEditorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorApp

BEGIN_MESSAGE_MAP(CPEiTemEditorApp, CWinApp)
	//{{AFX_MSG_MAP(CPEiTemEditorApp)
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorApp construction

CPEiTemEditorApp::CPEiTemEditorApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPEiTemEditorApp object

CPEiTemEditorApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorApp initialization

BOOL CPEiTemEditorApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

	CPEiTemEditorDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
