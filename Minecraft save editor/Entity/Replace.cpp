// Replace.cpp : implementation file
//

#include "stdafx.h"
#include "Entities.h"
#include "Replace.h"
#include "EntitiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString replace;
int yang;
int niu;
int zhu;
int ji;
int jiangshi;
int kulou;
int zhuren;
int zhizhu;
int kulipa;
CString a;
CString b;
/////////////////////////////////////////////////////////////////////////////
// CReplace dialog


CReplace::CReplace(CWnd* pParent /*=NULL*/)
	: CDialog(CReplace::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReplace)
	//}}AFX_DATA_INIT
}


void CReplace::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReplace)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReplace, CDialog)
	//{{AFX_MSG_MAP(CReplace)
	ON_BN_CLICKED(IDC_BUTTON1, OnOK)
	ON_BN_CLICKED(IDC_BUTTON2, Onenid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReplace message handlers

void CReplace::OnOK() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_a,a);
	GetDlgItemText(IDC_b,b);
	a.Format("%02X",strtoul(a,NULL,10));
	b.Format("%02X",strtoul(b,NULL,10));
	a = "69 64 "+a;
	b = "69 64 "+b;
	int r = replace.Replace(a,b);
	CEntitiesDlg *Dlg = (CEntitiesDlg*)GetParent();
    Dlg->strEdit=replace;
    CDialog::OnOK();
}

void CReplace::Onenid() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(this->m_hWnd,"open","res\\entities.JPG",NULL,NULL,SW_SHOWNORMAL);
}
