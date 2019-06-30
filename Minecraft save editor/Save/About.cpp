// About.cpp : implementation file
//

#include "stdafx.h"
#include "PEinfEdit.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAbout dialog


CAbout::CAbout(CWnd* pParent /*=NULL*/)
	: CDialog(CAbout::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAbout)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAbout, CDialog)
	//{{AFX_MSG_MAP(CAbout)
	ON_BN_CLICKED(IDC_BUTTON1, OnPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAbout message handlers

void CAbout::OnPage() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,_T("open"),_T("http://tieba.baidu.com/home/main?id=475048656e72797175616e5fb213&fr=userbar"),NULL,NULL,SW_SHOWNORMAL);
}
