// PEinfEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PEinfEdit.h"
#include "About.h"
#include "PEinfEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString survial = "00 47 61 6D 65 54 79 70 65 00";
CString creative = "00 47 61 6D 65 54 79 70 65 01";
CString seed = "00 52 61 6E 64 6F 6D 53 65 65 64";
CString shijian = "00 54 69 6D 65";
CString health = "00 48 65 61 6C 74 68";
CString spawn = "00 73 70 61 77 6E 4D 6F 62 73";
CString daynight = "00 64 61 79 43 79 63 6C 65 53 74 6F 70 54 69 6D 65";
CString fly = "00 6D 61 79 66 6C 79";
CString hurt = "00 69 6E 76 75 6C 6E 65 72 61 62 6C 65";
CString name = "00 4C 65 76 65 6C 4E 61 6D 65";
CString pos = "00 50 6F 73";
CString gamemode;
CString spawnmobs;
CString daynightcycle;;
CString canhurtornot;
CString canflyornot;
CString mapseed;
CString playerhealth;
CString weizhi;
CString gametime;
CString gamemapname;
CString final;
CString all;//全部文本ASCII
CString strEdit;//全部文本HEX
CString shengming;//生命值
CString timeinpe;//时间
CString timezuo;//时间左
CString timeyou;//时间右
CString randomseed;//种子
CString seedzuo;//种子左
CString seedyou;//种子右
CString seedzhongzuo;//种子中左
CString seedzhongyou;//种子中右
CString daynightshijian;//昼夜交替
CString mob;//生怪
CString nohurt;//无伤害
CString flying;//飞行
CString zuobiaoX;//坐标X
CString zuobiaoY;//坐标Y
CString zuobiaoZ;//坐标Z
CString mapname;
CString letter;
CString quan;
CString timeleft;
CString timeright;
CString healthleft;
CString healthright;
CString spawnkai;
CString spawnguan;
CString daynightkai;
CString daynightguan;
CString hurtkai;
CString hurtguan;
CString flykai;
CString flyguan;
CString nameline;
CString nameall;
CString saveline;
CString saveall;
CString strnew;
CString writefilename;
CString middlething;
/////////////////////////////////////////////////////////////////////////////
// CPEinfEditDlg dialog

CPEinfEditDlg::CPEinfEditDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPEinfEditDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPEinfEditDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPEinfEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPEinfEditDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPEinfEditDlg, CDialog)
	//{{AFX_MSG_MAP(CPEinfEditDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_About, OnAbout)
	ON_COMMAND(ID_leveldat, Onleveldat)
	ON_BN_CLICKED(IDC_mode, Onmode)
	ON_BN_CLICKED(IDC_spawnmob, Onspawnmob)
	ON_BN_CLICKED(IDC_daynight, Ondaynight)
	ON_BN_CLICKED(IDC_hurt, Onhurt)
	ON_BN_CLICKED(IDC_mayfly, Onmayfly)
	ON_BN_CLICKED(IDC_fullhealth, Onfullhealth)
	ON_BN_CLICKED(IDC_infinityhealth, Oninfinityhealth)
	ON_BN_CLICKED(IDC_time0, Ontime0)
	ON_BN_CLICKED(IDC_time9600, Ontime9600)
	ON_BN_CLICKED(IDC_copyseed, Oncopyseed)
	ON_BN_CLICKED(IDC_save, Onsave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPEinfEditDlg message handlers

BOOL CPEinfEditDlg::OnInitDialog()
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

void CPEinfEditDlg::OnPaint() 
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
HCURSOR CPEinfEditDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPEinfEditDlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAbout dlg;
	dlg.DoModal();
}

void CPEinfEditDlg::Onleveldat() 
{
	// TODO: Add your command handler code here
	all.Empty();//全部文本ASCII
	final.Empty();
	shengming.Empty();//生命值
	timeinpe.Empty();//时间
	timezuo.Empty();//时间左
	timeyou.Empty();//时间右
	randomseed.Empty();//种子
	seedzuo.Empty();//种子左
	seedyou.Empty();//种子右
	seedzhongzuo.Empty();//种子中左
	seedzhongyou.Empty();//种子中右
	daynightshijian.Empty();//昼夜交替
	mob.Empty();//生怪
	nohurt.Empty();//无伤害
	flying.Empty();//飞行
	zuobiaoX.Empty();//坐标X
	zuobiaoY.Empty();//坐标Y
	zuobiaoZ.Empty();//坐标Z
	mapname.Empty();
	letter.Empty();
	quan.Empty();
	weizhi.Empty();
	all.Empty();
	strEdit.Empty();//全部文本HEX
	strnew.Empty();
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter=_T("Dat Files(*.dat)\0level.dat\0\0");
	fileDlg.m_ofn.lpstrTitle=_T("打开Minecraft PE存档");
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
	}
	else
		return;
	if(strEdit.Find(survial)>0)//生存模式
	{
		SetDlgItemText(IDC_mode,"生存");
	}
	if(strEdit.Find(creative)>0)//创造模式
	{
		SetDlgItemText(IDC_mode,"创造");
	}
	{
		//生命值
		int ming = strEdit.Find(health);
		shengming = strEdit.Mid(ming+20,6);
		shengming.Format("%d",strtoul(shengming, NULL, 16));
		SetDlgItemText(IDC_health,shengming);
	}
	{
		//游戏时间
		int timeingame = strEdit.Find(shijian);
		timeinpe = strEdit.Mid(timeingame+15,6);
		timezuo = timeinpe.Left(3);
		timeyou = timeinpe.Right(3);
		timeinpe = timeyou + timezuo;
		timeinpe.Remove(' ');
		timeinpe.Format("%d",strtoul(timeinpe, NULL, 16));
		SetDlgItemText(IDC_time,timeinpe);
	}
	{
		//地图种子
		int zhongzi = strEdit.Find(seed);
		randomseed = strEdit.Mid(zhongzi+32,12);
		seedzuo = randomseed.Left(3);
		seedzhongzuo = randomseed.Mid(3,3);
		seedzhongyou = randomseed.Mid(6,3);
		seedyou = randomseed.Right(3);
		randomseed = seedyou + seedzhongyou + seedzhongzuo + seedzuo;
		randomseed.Remove(' ');
		randomseed.Format("%d",strtoul(randomseed, NULL, 16));
		SetDlgItemText(IDC_seed,randomseed);
	}
	{
		//昼夜交替
		int daynightime = strEdit.Find(daynight);
		daynightshijian = strEdit.Mid(daynightime+50,24);
		daynightshijian.Remove(' ');
		if (daynightshijian.Find("FFFFFFFFFFFFFFFF")>0)
		{
			SetDlgItemText(IDC_daynight,"开");
		}
		else if (daynightshijian.Find("000000000000")>0)
		{
			SetDlgItemText(IDC_daynight,"关");
		}
	}
	{
		//生怪
		int mobs = strEdit.Find(spawn);
		mob = strEdit.Mid(mobs+29,3);
		if (mob.Find("00")>0)
		{
			SetDlgItemText(IDC_spawnmob,"关");
		}
		else if (mob.Find("01")>0)
		{
			SetDlgItemText(IDC_spawnmob,"开");
		}
	}
	{
		//无伤害
		int nohurting = strEdit.Find(hurt);
		nohurt = strEdit.Mid(nohurting+38,3);
		if (nohurt.Find("00")>0)
		{
			SetDlgItemText(IDC_hurt,"关");
		}
		else if (nohurt.Find("01")>0)
		{
			SetDlgItemText(IDC_hurt,"开");
		}
	}
	{
		//飞行
		int mayfly = strEdit.Find(fly);
		flying = strEdit.Mid(mayfly+20,3);
		if (flying.Find("00")>0)
		{
			SetDlgItemText(IDC_mayfly,"关");
		}
		else if (flying.Find("01")>0)
		{
			SetDlgItemText(IDC_mayfly,"开");
		}
	}
	{
		//坐标
		int pospoint = strEdit.Find(pos);
		zuobiaoX = strEdit.Mid(pospoint+32,3);
		zuobiaoY = strEdit.Mid(pospoint+44,3);
		zuobiaoZ = strEdit.Mid(pospoint+56,3);
		zuobiaoX.Format("%d",strtoul(zuobiaoX, NULL, 16));
		zuobiaoY.Format("%d",strtoul(zuobiaoY, NULL, 16));
		zuobiaoZ.Format("%d",strtoul(zuobiaoZ, NULL, 16));
		zuobiaoX = zuobiaoX +","+ zuobiaoY +","+ zuobiaoZ;
		SetDlgItemText(IDC_zuobiao,zuobiaoX);
	}
	{
		//名字
		int mapming = strEdit.Find(name);
		mapname = strEdit.Mid(mapming+35,50);
		int position = mapname.Find("03 08");
		mapname = mapname.Left(position);
		int g = mapname.Replace("00","20");
		mapname.Remove(' ');
		//MessageBox(mapname);
		int len = mapname.GetLength();
		len = (len/2);
		for(int e = 0;e<len;e++)
		{
			letter = mapname.Left(2);
			mapname.Delete(0,2);
			letter.Format("%c",strtoul(letter,NULL,16));
			quan=quan+letter;
		}
		SetDlgItemText(IDC_name,quan);
	}
	strnew = strEdit;
}
 

void CPEinfEditDlg::Onmode() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_mode,gamemode);
	if(gamemode=="生存")
	{
		SetDlgItemText(IDC_mode,"创造");
		SetDlgItemText(IDC_spawnmob,"关");
		SetDlgItemText(IDC_daynight,"关");
		SetDlgItemText(IDC_hurt,"开");
		SetDlgItemText(IDC_mayfly,"开");
	}
	else if (gamemode=="创造")
	{
		SetDlgItemText(IDC_mode,"生存");
		SetDlgItemText(IDC_spawnmob,"开");
		SetDlgItemText(IDC_daynight,"开");
		SetDlgItemText(IDC_hurt,"关");
		SetDlgItemText(IDC_mayfly,"关");
	}
}

void CPEinfEditDlg::Onspawnmob() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_spawnmob,spawnmobs);
	if(spawnmobs=="开")
	{
		SetDlgItemText(IDC_spawnmob,"关");
	}
	else if (spawnmobs=="关")
	{
		SetDlgItemText(IDC_spawnmob,"开");
	}
}

void CPEinfEditDlg::Ondaynight() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_daynight,daynightcycle);
	if(daynightcycle=="开")
	{
		SetDlgItemText(IDC_daynight,"关");
	}
	else if (daynightcycle=="关")
	{
		SetDlgItemText(IDC_daynight,"开");
	}
}

void CPEinfEditDlg::Onhurt() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_hurt,canhurtornot);
	if(canhurtornot=="开")
	{
		SetDlgItemText(IDC_hurt,"关");
	}
	else if (canhurtornot=="关")
	{
		SetDlgItemText(IDC_hurt,"开");
	}
}

void CPEinfEditDlg::Onmayfly() 
{
	// TODO: Add your control notification handler code here
    GetDlgItemText(IDC_mayfly,canflyornot);
	if(canflyornot=="开")
	{
		SetDlgItemText(IDC_mayfly,"关");
	}
	else if (canflyornot=="关")
	{
		SetDlgItemText(IDC_mayfly,"开");
	}
}

void CPEinfEditDlg::Onfullhealth() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_health,"20");
	UpdateData(false);
}

void CPEinfEditDlg::Oninfinityhealth() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_health,"32767");
	UpdateData(false);
}

void CPEinfEditDlg::Ontime0() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_time,"0");
	UpdateData(false);
}

void CPEinfEditDlg::Ontime9600() 
{
	// TODO: Add your control notification handler code here
	SetDlgItemText(IDC_time,"9600");
	UpdateData(false);
}

void CPEinfEditDlg::Oncopyseed() 
{
	// TODO: Add your control notification handler code here
	CString seednameinmap;
	GetDlgItemText(IDC_seed,seednameinmap);
	if (seednameinmap=="种子")
	{
		return;
	}
	else
	{
	if(OpenClipboard()) //首先打开一个剪切板，如果成功则返回非0值  
	{  
		HANDLE hClip;      //声明一个句柄  
		//CString str; 
		char *pBuf; 
		EmptyClipboard();  //置空这个剪切板，且得到剪切板的所有权  
		GetDlgItemText(IDC_seed,mapseed);//将文本框的值赋给str  
		hClip=GlobalAlloc(GMEM_MOVEABLE,mapseed.GetLength()+1); 
		pBuf=(char *)GlobalLock(hClip);//得到指向内存区域的第一个字节指针  
		strcpy(pBuf,mapseed);//将文本框的值拷贝到内存中  
		GlobalUnlock(hClip);//解除内存锁定  
		SetClipboardData(CF_TEXT,hClip);//设置数据到剪切板中  
		CloseClipboard();//关闭剪切板 
		MessageBox("种子复制成功！");
	} 
	else
	{
		MessageBox("种子复制失败！");
	}
	}
}
void CPEinfEditDlg::Onsave() 
{
	// TODO: Add your control notification handler code here
	strEdit = strnew;
	 timeleft.Empty();
	 timeright.Empty();
	 healthleft.Empty();
	 healthright.Empty();
	 spawnkai.Empty();
	 spawnguan.Empty();
	 daynightkai.Empty();
	 daynightguan.Empty();
	 hurtkai.Empty();
	 hurtguan.Empty();
	 flykai.Empty();
	 flyguan.Empty();
	 nameline.Empty();
	 nameall.Empty();
	 saveline.Empty();
	 saveall.Empty();
	 writefilename.Empty();
	 middlething.Empty();
	GetDlgItemText(IDC_seed,mapseed);
	GetDlgItemText(IDC_health,playerhealth);
	if (mapseed=="种子")
	{
		MessageBox("没有打开存档！");
	}
	else if(playerhealth>"32767")
	{
		MessageBox("生命值最大为32767");
	}
	else
	{
		GetDlgItemText(IDC_mode,gamemode);
    	GetDlgItemText(IDC_spawnmob,spawnmobs);
    	GetDlgItemText(IDC_daynight,daynightcycle);
    	GetDlgItemText(IDC_hurt,canhurtornot);
    	GetDlgItemText(IDC_mayfly,canflyornot);
		GetDlgItemText(IDC_time,gametime);
		GetDlgItemText(IDC_name,gamemapname);
		{
			//游戏模式
			if(gamemode=="生存")
			{
				if(strEdit.Find(survial)>0)//生存模式
				{
			
				}
	    		if(strEdit.Find(creative)>0)//创造模式
				{
		    		int n = strEdit.Replace(creative,survial);
				}
			}
			if(gamemode=="创造")
			{
				if(strEdit.Find(creative)>0)//生存模式
				{

				}
	    		if(strEdit.Find(survial)>0)//创造模式
				{
		    		int n = strEdit.Replace(survial,creative);
				}	
			}
		}
		{
			//时间
			gametime.Format("%02X",strtoul(gametime,NULL,10));
			timeleft = gametime.Left(2);
			timeright = gametime.Right(2);
			gametime = timeright +' '+ timeleft;
			gametime = shijian+' '+gametime;
			int timeingame = strEdit.Find(shijian);
		    timeinpe = strEdit.Mid(timeingame+15,6);
			timeinpe = shijian+' '+timeinpe;
			int n = strEdit.Replace(timeinpe,gametime);
		}
		{
			//生命
			playerhealth.Format("%02X",strtoul(playerhealth,NULL,10));
			healthleft = playerhealth.Left(2);
			healthright = playerhealth.Right(2);
			playerhealth = healthright +' '+healthleft;
			playerhealth = health +' '+ playerhealth;
			int ming = strEdit.Find(health);
		    shengming = strEdit.Mid(ming+20,6);
			shengming = health + shengming;
			int n = strEdit.Replace(shengming,playerhealth);
		}
		{
			//生怪
			spawnkai = spawn+" 01";
			spawnguan = spawn+" 00";
			if (spawnmobs=="开")
			{
				int n = strEdit.Replace(spawnguan,spawnkai);
			}
			if (spawnmobs=="关")
			{
				int n = strEdit.Replace(spawnkai,spawnguan);
			}
		}
		{
			//日夜
			daynightkai = daynight+" 88 13 00 00 00 00 00 00";
			daynightguan = daynight+" FF FF FF FF FF FF FF FF";
			if (daynightcycle=="开")
			{
				int n = strEdit.Replace(daynightkai,daynightguan);
			}
			if (daynightcycle=="关")
			{
				int n = strEdit.Replace(daynightguan,daynightkai);
			}
		}
		{
			//伤害
		    hurtkai = hurt+" 01";
			hurtguan = hurt+" 00";
			if (canhurtornot=="开")
			{
				int n = strEdit.Replace(hurtguan,hurtkai);
			}
			if (canhurtornot=="关")
			{
				int n = strEdit.Replace(hurtkai,hurtguan);
			}
		}
		{
			//飞行
			flykai = fly+" 01";
			flyguan = fly+" 00";
			if (canflyornot=="开")
			{
				int n = strEdit.Replace(flyguan,flykai);
			}
			if (canflyornot=="关")
			{
				int n = strEdit.Replace(flykai,flyguan);
			}
		}
		{
			//地图名字
			
		}
		//转换
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

