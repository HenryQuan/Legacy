// EntitiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Entities.h"
#include "EntitiesDlg.h"
#include "Colour.h"
#include "Replace.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString weizhi;
CString all;
CString final;
CString strEdit;
CString number;
CString slotnum;
CString slotstart = "00 69 64";
CString slot = "00 69 64 ";
CString enid;
int chicken;
int cow;
int sheep;
int pig;
int zombie;
int skeleton;
int spider;
int creeper;
int pigzombie;
int drop;
int other;
CString chickens;
CString cows;
CString sheeps;
CString pigs;
CString zombies;
CString skeletons;
CString spiders;
CString creepers;
CString pigzombies;
CString drops;
CString others;
CString totalentities;
CString openornot = "";
CString age = "FF FF 02 03";
CString saveall;
CString saveline;
CString writefilename;
CString yes1 = "48 61 73 46 69 6E 69 73 68 65 64 01";
CString no1 = "48 61 73 46 69 6E 69 73 68 65 64 00";
CString yes2 = "49 73 49 6E 69 74 69 61 6C 69 7A 65 64 01";
CString no2 = "49 73 49 6E 69 74 69 61 6C 69 7A 65 64 00";
/////////////////////////////////////////////////////////////////////////////
// CEntitiesDlg dialog

CEntitiesDlg::CEntitiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEntitiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEntitiesDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEntitiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEntitiesDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEntitiesDlg, CDialog)
	//{{AFX_MSG_MAP(CEntitiesDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_openentitiesdat, Onopenentitiesdat)
	ON_BN_CLICKED(IDC_BUTTON4, Ondeleteentities)
	ON_BN_CLICKED(IDC_BUTTON8, Onnothing)
	ON_BN_CLICKED(IDC_BUTTON1, OnOld)
	ON_BN_CLICKED(IDC_BUTTON2, Onyoung)
	ON_BN_CLICKED(IDC_BUTTON3, Oncolour)
	ON_BN_CLICKED(IDC_BUTTON5, Onreplace)
	ON_BN_CLICKED(IDC_BUTTON7, Onsaveall)
	ON_COMMAND(ID_makepig, Onmakepig)
	ON_COMMAND(ID_cancelpig, Oncancelpig)
	ON_COMMAND(ID_MENUITEM32772, Onpage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEntitiesDlg message handlers

BOOL CEntitiesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEntitiesDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEntitiesDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEntitiesDlg::Onopenentitiesdat() 
{
	// TODO: Add your command handler code here
	weizhi.Empty();
	all.Empty();
	final.Empty();
	strEdit.Empty();
	number.Empty();
	slotnum.Empty();
	chickens.Empty();
    cows.Empty();
    sheeps.Empty();
    pigs.Empty();
    zombies.Empty();
    skeletons.Empty();
    spiders.Empty();
	creepers.Empty();
    pigzombies.Empty();
    drops.Empty();
    others.Empty();
    totalentities.Empty();
	chicken = 0;
    cow = 0;
    sheep = 0;
    pig = 0;
    zombie = 0;
    skeleton = 0;
    spider = 0;
    creeper = 0;
    pigzombie = 0;
    drop = 0;
    other = 0;
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter=_T("Dat Files(*.dat)\0entities.dat\0\0");
	fileDlg.m_ofn.lpstrTitle=_T("请选择Minecraft PE存档文件夹里的entities.dat文件");
	if (fileDlg.DoModal()==IDOK)
	{
		CFile file;
		file.Open(fileDlg.m_ofn.lpstrFile,CFile::modeRead|CFile::typeBinary);
		weizhi = file.GetFilePath();
		int len = file.GetLength();
		char* save = new char[len];
		file.ReadHuge(save,len);
		file.Close();
		for (int i = 0;i < len;i++)//显示所有文本
		{
			if(save[i]!='\0')
			{
				all+=save[i];
			}
			else if(save[i]=='\0')
			{
				save[i]=' ';
				all+=save[i];
			}
		}
		for(int e = 0 ; e < all.GetLength(); e++)//转化为十六进制
		{
			if(all[e]!=' ')
			{
               final.Format("%02X",all[e]);
		   	   final = final.Right(2);
			   strEdit += final+" ";
			}
			else if (all[e]==' ')
			{
                strEdit += "00 ";
			}
		}
		int n;
		int p=0;
		if (strEdit.Find(slotstart)==0)
		{
			MessageBox("没有发现实体");
		}
		else if (strEdit.Find(slotstart)>0)
		{
			int howmany = strEdit.GetLength();
			howmany = ((howmany - 147)/600);
			for (int s = 0 ; s < howmany ; s++)
			{
			   slotnum.Format("%d",s);
			   n = strEdit.Find(slotstart,p);
			   enid = strEdit.Mid(n+9,3);
			   enid.Remove(' ');
			   enid.Format("%d",strtoul(enid, NULL, 16));
			   if (enid=="13")
			   {
				   sheep = sheep + 1;
			   }
			   if (enid=="12")
			   {
				   pig = pig + 1;
			   }
			   if (enid=="11")
			   {
				   cow = cow + 1;
			   }
			   if (enid=="10")
			   {
				   chicken = chicken + 1;
			   }
			   if (enid=="32")
			   {
				   zombie = zombie + 1;
			   }
			   if (enid=="33")
			   {
				   creeper = creeper + 1;
			   }
			   if (enid=="34")
			   {
				   skeleton = skeleton + 1;
			   }
			   if (enid=="35")
			   {
				   spider = spider + 1;
			   }
			   if (enid=="36")
			   {
				   pigzombie = pigzombie + 1;
			   }
			   if (enid=="64")
			   {
				   drop = drop + 1;
			   }
			   if (enid=="65")
			   {
				   other = other + 1;
			   }
			   if (enid=="83")
			   {
				   other = other + 1;
			   }
			   if (enid=="80")
			   {
				   other = other + 1;
			   }
			   if (enid=="81")
			   {
				   other = other + 1;
			   }
			   if (enid=="82")
			   {
				   other = other + 1;
			   }
			   p = n + 12;
			} 
		}
		cows.Format("%d",cow);
		chickens.Format("%d",chicken);
		sheeps.Format("%d",sheep);
		pigs.Format("%d",pig);
		zombies.Format("%d",zombie);
		skeletons.Format("%d",skeleton);
		creepers.Format("%d",creeper);
		pigzombies.Format("%d",pigzombie);
		spiders.Format("%d",spider);
		drops.Format("%d",drop);
		others.Format("%d",other);
		totalentities = "实体统计:\r\n鸡:"+chickens+"\r\n"+"牛:"+cows+"\r\n"+"猪:"+pigs+"\r\n"+"羊:"+sheeps+"\r\n"+"僵尸:"+zombies+"\r\n"+"骷髅:"+skeletons+"\r\n"+"苦力怕:"+creepers+"\r\n"+"蜘蛛:"+spiders+"\r\n"+"猪人僵尸:"+pigzombies+"\r\n"+"掉落物品:"+drops+"\r\n"+"其他:"+others+"\r\n";
		SetDlgItemText(IDC_total,totalentities);
		SetDlgItemText(IDC_openornot,"已打开存档 ^_^");
	}
	else
	{
		return;
	}

}

void CEntitiesDlg::OnSelchangeentity() 
{
	// TODO: Add your control notification handler code here
	
}

void CEntitiesDlg::Ondeleteentities() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
		int choose = AfxMessageBox("真的要删除所有实体么 ^_^",MB_YESNO|MB_ICONQUESTION);
		if(choose==6)
		{
	   		strEdit = "45 4E 54 00 01 00 00 00 28 00 00 00 0A 00 00 09 08 00 45 6E 74 69 74 69 65 73 01 00 00 00 00 09 0C 00 54 69 6C 65 45 6E 74 69 74 69 65 73 01 00 00 00 00 00";
			MessageBox("删除成功!","^_^");
		}
		else
		{
			return;
		}
	}
}

void CEntitiesDlg::Onnothing() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
		MessageBox("说了不要点，你还是点了","^_^");
		OnOK();
	}
}

void CEntitiesDlg::OnOld() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
		CString ageyoung;
		CString ageold = "41 67 65 00 00 00 00 02 03";
		int animals = cow + sheep + pig + chicken;
		int z = 0;
		for (int i = 0; i < animals; i++)
		{
			int pos = strEdit.Find(age,z);
			ageyoung = strEdit.Mid(pos-15,26);
			int r = strEdit.Replace(ageyoung,ageold);
			z = pos + 15;
		}
	}
}

void CEntitiesDlg::Onyoung() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
		CString ageyoung = "41 67 65 00 00 FF FF 02 03 ";
		CString ageold = "41 67 65 00 00 00 00 02 03 ";
		int animals = cow + sheep + pig + chicken;
		int z = 0;
		for (int i = 0; i < animals; i++)
		{
			int pos = strEdit.Find(age,z);
			int r = strEdit.Replace(ageold,ageyoung);
			z = pos + 15;
		}
	}
}

void CEntitiesDlg::Oncolour() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
		CColour dlg;
		dlg.color = strEdit;
		dlg.sheepnum = sheep;
		dlg.DoModal();
	}
}

void CEntitiesDlg::Onreplace() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
		CReplace dlg;
		dlg.replace = strEdit;
		dlg.yang = sheep;
		dlg.niu = cow;
		dlg.zhu = pig;
		dlg.ji = chicken;
		dlg.jiangshi = zombie;
		dlg.kulou = skeleton;
		dlg.zhizhu = spider;
		dlg.zhuren = pigzombie;
		dlg.kulipa = creeper;
		dlg.DoModal();
	}
}

void CEntitiesDlg::Onsaveall() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{

		saveline.Empty();
	    saveall.Empty();
	    writefilename.Empty();
		strEdit.Remove(' ');
		strEdit.Delete(0,6);
		strEdit = "454E54" + strEdit;
		int lengthall = strEdit.GetLength();
		lengthall = (lengthall/2);
		for(int z = 0;z<lengthall;z++)
		{
			saveline = strEdit.Left(2);
			strEdit.Delete(0,2);
			if (saveline=="00")
			{
				saveline='\0';
			}
			else
			{
				saveline.Format("%c",strtoul(saveline,NULL,16));
			}
			saveall=saveall+saveline;
		}
		writefilename = weizhi;
		CFile savefile(writefilename,CFile::modeCreate|CFile::modeReadWrite|CFile::typeBinary);
		savefile.WriteHuge(saveall,saveall.GetLength());
		savefile.Close();
		MessageBox("修改成功！");
	}
}

void CEntitiesDlg::Onmakepig() 
{
	// TODO: Add your command handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
	int re = strEdit.Replace(no1,yes1);
	int ra = strEdit.Replace(no2,yes2);
	MessageBox("制作成功！");
	}
}

void CEntitiesDlg::Oncancelpig() 
{
	// TODO: Add your command handler code here
	GetDlgItemText(IDC_openornot,openornot);
	if (openornot=="请打开存档 ^_^")
	{
		MessageBox("请打开存档 ^_^","^_^");
	}
	else
	{
	int re = strEdit.Replace(yes1,no1);
	int ra = strEdit.Replace(yes2,no2);
	MessageBox("取消成功！");
	}
}

void CEntitiesDlg::Onpage() 
{
	// TODO: Add your command handler code here
	ShellExecute(NULL,_T("open"),_T("http://tieba.baidu.com/home/main?id=475048656e72797175616e5fb213&fr=userbar"),NULL,NULL,SW_SHOWNORMAL);
}
