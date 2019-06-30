// Colour.cpp : implementation file
//

#include "stdafx.h"
#include "Entities.h"
#include "Colour.h"
#include "EntitiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString color;
CString colorid;
int real;
int sheepnum;
CString yanse = "43 6F 6C 6F 72 ";
CString yanseold;
CString yansenew;
/////////////////////////////////////////////////////////////////////////////
// CColour dialog


CColour::CColour(CWnd* pParent /*=NULL*/)
	: CDialog(CColour::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColour)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CColour::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColour)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColour, CDialog)
	//{{AFX_MSG_MAP(CColour)
	ON_BN_CLICKED(IDC_BUTTON1, Onok)
	ON_BN_CLICKED(IDC_BUTTON2, Onid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColour message handlers

void CColour::Onok() 
{
	// TODO: Add your control notification handler code here
	yanseold.Empty();
	yansenew.Empty();
	GetDlgItemText(IDC_id,colorid);
	real = _ttoi(colorid);
	real = real - 1;
	colorid.Format("%d",real);
	colorid.Format("%02X",strtoul(colorid,NULL,10));
	int z = 0;
	for (int i = 0 ; i < sheepnum ; i++)
	{	
	    int pos = color.Find(yanse,z);
		yanseold = color.Mid(pos,17);
		yansenew = "43 6F 6C 6F 72 "+colorid;
		int r = color.Replace(yanseold,yansenew);
		z = pos + 30;
	}
	CEntitiesDlg *Dlg = (CEntitiesDlg*)GetParent();
    Dlg->strEdit=color;
    CDialog::OnOK();	
}

void CColour::Onid() 
{
	// TODO: Add your control notification handler code here
	MessageBox("sdejiofhew");
	ShellExecute(this->m_hWnd,_T("open"),_T("res\\colour.png"),NULL,NULL,SW_SHOWNORMAL);
}
