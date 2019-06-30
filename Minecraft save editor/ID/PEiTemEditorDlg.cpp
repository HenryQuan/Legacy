// PEiTemEditorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PEiTemEditor.h"
#include "PEiTemEditorDlg.h"

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
CString slotstart = "53 6C 6F 74 09";
CString slot = "53 6C 6F 74 ";
CString idw ="69 64 ";
CString countw ="43 6F 75 6E 74 ";
CString damagew ="44 61 6D 61 67 65 ";
CString id;
CString count;
CString damage;
CString slotnumber;
CString idzuo;
CString idyou;
CString xiuid;
CString xiudamage;
CString xiucount;
CString xiuqian;
CString xiuzhong;
CString xiuidzuo;
CString xiuidyou;
CString saveline;
CString saveall;
CString writefilename;
/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorDlg dialog

CPEiTemEditorDlg::CPEiTemEditorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPEiTemEditorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPEiTemEditorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPEiTemEditorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPEiTemEditorDlg)
	DDX_Control(pDX, IDC_COMBO1, m_item);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPEiTemEditorDlg, CDialog)
	//{{AFX_MSG_MAP(CPEiTemEditorDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_openlevedat, Onopenlevedat)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeitem)
	ON_BN_CLICKED(IDC_BUTTON4, Onsavechange)
	ON_BN_CLICKED(IDC_BUTTON6, OnSaveAl)
	ON_BN_CLICKED(IDC_BUTTON2, Onfullnum)
	ON_BN_CLICKED(IDC_BUTTON3, Onfulldamage)
	ON_COMMAND(ID_MENUITEM32774, OnMenuitem32774)
	ON_BN_CLICKED(IDC_BUTTON1, OnID)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPEiTemEditorDlg message handlers

BOOL CPEiTemEditorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPEiTemEditorDlg::OnPaint() 
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

HCURSOR CPEiTemEditorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPEiTemEditorDlg::Onopenlevedat() 
{
	// TODO: Add your command handler code here
	weizhi.Empty();
	all.Empty();
	final.Empty();
	strEdit.Empty();
	number.Empty();
	slotnum.Empty();
	((CComboBox*)GetDlgItem(IDC_COMBO1))->ResetContent();
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter=_T("Dat Files(*.dat)\0level.dat\0\0");
	fileDlg.m_ofn.lpstrTitle=_T("请选择Minecraft PE存档文件夹里的level.dat文件");
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
		int num = 9;
		if (strEdit.Find(slotstart)==0)
		{
			MessageBox("没有发现物品");
		}
		else if (strEdit.Find(slotstart)>0)
		{
			for (int s = 0 ; s < 36 ; s++)
			{	
			    slotnum.Format("%d",s);
				number.Format("%02X",num);
				//MessageBox(number);
	     		n = strEdit.Find(slot+number);
	     		if (n > 0)
				{
		 	  	  	m_item.InsertString(s,"位置 "+slotnum);
				}
		 	   else
				{   
				   return;
				}
		  	  num = num + 1;
		}
	}
	}
	else
	{
		return;
	}
}

void CPEiTemEditorDlg::OnSelchangeitem() 
{
	// TODO: Add your control notification handler code here
    damage.Empty();
    id.Empty();
    count.Empty();
    idzuo.Empty();
    idyou.Empty();
	int b;
	int i = m_item.GetCurSel();
	i = i+9;
	slotnumber.Format("%02X",i);
	b = strEdit.Find(slot+slotnumber);
	id = strEdit.Mid(b+30,6);
	damage = strEdit.Mid(b-15,3);
	count = strEdit.Mid(b-45,3);
	id.Remove(' ');
	damage.Remove(' ');
	count.Remove(' ');
	idzuo = id.Left(2);
	idyou = id.Right(2);
	id = idyou + idzuo;
	damage.Format("%d",strtoul(damage, NULL, 16));
	count.Format("%d",strtoul(count, NULL, 16));
	id.Format("%d",strtoul(id, NULL, 16));
	SetDlgItemText(IDC_id,id);
	SetDlgItemText(IDC_damage,damage);
	SetDlgItemText(IDC_count,count);
}

void CPEiTemEditorDlg::Onsavechange() 
{
	// TODO: Add your control notification handler code here
	xiuid.Empty();
    xiudamage.Empty();
    xiucount.Empty();
    xiuzhong.Empty();
	xiuqian.Empty();
	int i = m_item.GetCurSel();
	i = i+9;
	slotnumber.Format("%02X",i);
	int a = strEdit.Find(slot+slotnumber);
	GetDlgItemText(IDC_id,xiuid);
	GetDlgItemText(IDC_damage,xiudamage);
	GetDlgItemText(IDC_count,xiucount);	
	if (xiuid.IsEmpty()||xiudamage.IsEmpty()||xiucount.IsEmpty())
	{
		MessageBox("请先打开存档");
	}
	else
	{
//	int len = strEdit.GetLength();
	xiuqian = strEdit.Mid(a-60,107);
	xiuzhong = strEdit.Mid(a-60,107);
	{
		//id
		id = strEdit.Mid(a+30,6);
		//MessageBox(id);
		xiuid.Remove(' ');
		xiuid.Format("%04X",strtoul(xiuid,NULL,10));
		MessageBox(xiuid);
		if (xiuid.GetLength()==2)
		{
			xiuid = xiuid+" 00 ";
		}
		else
		{
		xiuidzuo =xiuid.Left(2);
		xiuidyou =xiuid.Right(2);
		xiuid =xiuidyou+" "+xiuidzuo+" ";
		}
		
		xiuzhong.Replace(idw+id,idw+xiuid);
		//MessageBox(idw+xiuid);
		//MessageBox(idw+id);
	}
	{
		//damage
		damage = strEdit.Mid(a-15,3);
		xiudamage.Remove(' ');
		xiudamage.Format("%02X",strtoul(xiudamage,NULL,10));
		MessageBox(xiudamage);
	//	MessageBox(xiudamage);
		xiudamage = xiudamage+" ";
		xiuzhong.Replace(damagew+damage,damagew+xiudamage);
		
	}
	{
		//count
		count = strEdit.Mid(a-45,3);
		xiucount.Remove(' ');
		xiucount.Format("%02X",strtoul(xiucount,NULL,10));
		MessageBox(xiucount);
	//	MessageBox(xiucount);
		xiucount = xiucount+" ";
		xiuzhong.Replace(countw+count,countw+xiucount);
		
	}
	strEdit.Replace(xiuqian,xiuzhong);
	//MessageBox(strEdit);
	}
}

void CPEiTemEditorDlg::OnSaveAl() 
{
	// TODO: Add your control notification handler code here
	saveline.Empty();
	saveall.Empty();
	writefilename.Empty();
	GetDlgItemText(IDC_id,xiuid);
	GetDlgItemText(IDC_damage,xiudamage);
	GetDlgItemText(IDC_count,xiucount);	
	if (xiuid.IsEmpty()||xiudamage.IsEmpty()||xiucount.IsEmpty())
	{
		MessageBox("请先打开存档");
	}
	else
	{
	strEdit.Remove(' ');
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
	rename("level.dat_backup",weizhi);
	writefilename = weizhi;
	CFile savefile(writefilename,CFile::modeCreate|CFile::modeReadWrite|CFile::typeBinary);
	savefile.WriteHuge(saveall,saveall.GetLength());
	savefile.Close();
	MessageBox("修改成功！");
	}
}

void CPEiTemEditorDlg::Onfullnum() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_count,"255");	
}

void CPEiTemEditorDlg::Onfulldamage() 
{
	// TODO: Add your control notification handler code here
	int choose = AfxMessageBox("如果本物品不是工具（例如：铲子），请不要修改本项 ^_^",MB_YESNO|MB_ICONQUESTION);
	if(choose==6)
	{
	    SetDlgItemText(IDC_damage,"255");
	}
	else
	{
		return;
	}
}

void CPEiTemEditorDlg::OnMenuitem32774() 
{
	// TODO: Add your command handler code here
	ShellExecute(NULL,_T("open"),_T("http://tieba.baidu.com/home/main?id=475048656e72797175616e5fb213&fr=userbar"),NULL,NULL,SW_SHOWNORMAL);
}

void CPEiTemEditorDlg::OnID() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL,_T("open"),_T("res\\ID.PNG"),NULL,NULL,SW_SHOWNORMAL);
}
