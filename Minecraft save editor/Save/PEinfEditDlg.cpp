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
CString all;//ȫ���ı�ASCII
CString strEdit;//ȫ���ı�HEX
CString shengming;//����ֵ
CString timeinpe;//ʱ��
CString timezuo;//ʱ����
CString timeyou;//ʱ����
CString randomseed;//����
CString seedzuo;//������
CString seedyou;//������
CString seedzhongzuo;//��������
CString seedzhongyou;//��������
CString daynightshijian;//��ҹ����
CString mob;//����
CString nohurt;//���˺�
CString flying;//����
CString zuobiaoX;//����X
CString zuobiaoY;//����Y
CString zuobiaoZ;//����Z
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
	all.Empty();//ȫ���ı�ASCII
	final.Empty();
	shengming.Empty();//����ֵ
	timeinpe.Empty();//ʱ��
	timezuo.Empty();//ʱ����
	timeyou.Empty();//ʱ����
	randomseed.Empty();//����
	seedzuo.Empty();//������
	seedyou.Empty();//������
	seedzhongzuo.Empty();//��������
	seedzhongyou.Empty();//��������
	daynightshijian.Empty();//��ҹ����
	mob.Empty();//����
	nohurt.Empty();//���˺�
	flying.Empty();//����
	zuobiaoX.Empty();//����X
	zuobiaoY.Empty();//����Y
	zuobiaoZ.Empty();//����Z
	mapname.Empty();
	letter.Empty();
	quan.Empty();
	weizhi.Empty();
	all.Empty();
	strEdit.Empty();//ȫ���ı�HEX
	strnew.Empty();
	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrFilter=_T("Dat Files(*.dat)\0level.dat\0\0");
	fileDlg.m_ofn.lpstrTitle=_T("��Minecraft PE�浵");
	if (fileDlg.DoModal()==IDOK)
	{
		CFile file;
		file.Open(fileDlg.m_ofn.lpstrFile,CFile::modeRead|CFile::typeBinary);
		weizhi = file.GetFilePath();
		int len = file.GetLength();
		char* save = new char[len];
		file.ReadHuge(save,len);
		file.Close();
		for (int i = 0;i < len;i++)//��ʾ�����ı�
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
		for(int e = 0 ; e < all.GetLength(); e++)//ת��Ϊʮ������
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
	if(strEdit.Find(survial)>0)//����ģʽ
	{
		SetDlgItemText(IDC_mode,"����");
	}
	if(strEdit.Find(creative)>0)//����ģʽ
	{
		SetDlgItemText(IDC_mode,"����");
	}
	{
		//����ֵ
		int ming = strEdit.Find(health);
		shengming = strEdit.Mid(ming+20,6);
		shengming.Format("%d",strtoul(shengming, NULL, 16));
		SetDlgItemText(IDC_health,shengming);
	}
	{
		//��Ϸʱ��
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
		//��ͼ����
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
		//��ҹ����
		int daynightime = strEdit.Find(daynight);
		daynightshijian = strEdit.Mid(daynightime+50,24);
		daynightshijian.Remove(' ');
		if (daynightshijian.Find("FFFFFFFFFFFFFFFF")>0)
		{
			SetDlgItemText(IDC_daynight,"��");
		}
		else if (daynightshijian.Find("000000000000")>0)
		{
			SetDlgItemText(IDC_daynight,"��");
		}
	}
	{
		//����
		int mobs = strEdit.Find(spawn);
		mob = strEdit.Mid(mobs+29,3);
		if (mob.Find("00")>0)
		{
			SetDlgItemText(IDC_spawnmob,"��");
		}
		else if (mob.Find("01")>0)
		{
			SetDlgItemText(IDC_spawnmob,"��");
		}
	}
	{
		//���˺�
		int nohurting = strEdit.Find(hurt);
		nohurt = strEdit.Mid(nohurting+38,3);
		if (nohurt.Find("00")>0)
		{
			SetDlgItemText(IDC_hurt,"��");
		}
		else if (nohurt.Find("01")>0)
		{
			SetDlgItemText(IDC_hurt,"��");
		}
	}
	{
		//����
		int mayfly = strEdit.Find(fly);
		flying = strEdit.Mid(mayfly+20,3);
		if (flying.Find("00")>0)
		{
			SetDlgItemText(IDC_mayfly,"��");
		}
		else if (flying.Find("01")>0)
		{
			SetDlgItemText(IDC_mayfly,"��");
		}
	}
	{
		//����
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
		//����
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
	if(gamemode=="����")
	{
		SetDlgItemText(IDC_mode,"����");
		SetDlgItemText(IDC_spawnmob,"��");
		SetDlgItemText(IDC_daynight,"��");
		SetDlgItemText(IDC_hurt,"��");
		SetDlgItemText(IDC_mayfly,"��");
	}
	else if (gamemode=="����")
	{
		SetDlgItemText(IDC_mode,"����");
		SetDlgItemText(IDC_spawnmob,"��");
		SetDlgItemText(IDC_daynight,"��");
		SetDlgItemText(IDC_hurt,"��");
		SetDlgItemText(IDC_mayfly,"��");
	}
}

void CPEinfEditDlg::Onspawnmob() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_spawnmob,spawnmobs);
	if(spawnmobs=="��")
	{
		SetDlgItemText(IDC_spawnmob,"��");
	}
	else if (spawnmobs=="��")
	{
		SetDlgItemText(IDC_spawnmob,"��");
	}
}

void CPEinfEditDlg::Ondaynight() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_daynight,daynightcycle);
	if(daynightcycle=="��")
	{
		SetDlgItemText(IDC_daynight,"��");
	}
	else if (daynightcycle=="��")
	{
		SetDlgItemText(IDC_daynight,"��");
	}
}

void CPEinfEditDlg::Onhurt() 
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_hurt,canhurtornot);
	if(canhurtornot=="��")
	{
		SetDlgItemText(IDC_hurt,"��");
	}
	else if (canhurtornot=="��")
	{
		SetDlgItemText(IDC_hurt,"��");
	}
}

void CPEinfEditDlg::Onmayfly() 
{
	// TODO: Add your control notification handler code here
    GetDlgItemText(IDC_mayfly,canflyornot);
	if(canflyornot=="��")
	{
		SetDlgItemText(IDC_mayfly,"��");
	}
	else if (canflyornot=="��")
	{
		SetDlgItemText(IDC_mayfly,"��");
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
	if (seednameinmap=="����")
	{
		return;
	}
	else
	{
	if(OpenClipboard()) //���ȴ�һ�����а壬����ɹ��򷵻ط�0ֵ  
	{  
		HANDLE hClip;      //����һ�����  
		//CString str; 
		char *pBuf; 
		EmptyClipboard();  //�ÿ�������а壬�ҵõ����а������Ȩ  
		GetDlgItemText(IDC_seed,mapseed);//���ı����ֵ����str  
		hClip=GlobalAlloc(GMEM_MOVEABLE,mapseed.GetLength()+1); 
		pBuf=(char *)GlobalLock(hClip);//�õ�ָ���ڴ�����ĵ�һ���ֽ�ָ��  
		strcpy(pBuf,mapseed);//���ı����ֵ�������ڴ���  
		GlobalUnlock(hClip);//����ڴ�����  
		SetClipboardData(CF_TEXT,hClip);//�������ݵ����а���  
		CloseClipboard();//�رռ��а� 
		MessageBox("���Ӹ��Ƴɹ���");
	} 
	else
	{
		MessageBox("���Ӹ���ʧ�ܣ�");
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
	if (mapseed=="����")
	{
		MessageBox("û�д򿪴浵��");
	}
	else if(playerhealth>"32767")
	{
		MessageBox("����ֵ���Ϊ32767");
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
			//��Ϸģʽ
			if(gamemode=="����")
			{
				if(strEdit.Find(survial)>0)//����ģʽ
				{
			
				}
	    		if(strEdit.Find(creative)>0)//����ģʽ
				{
		    		int n = strEdit.Replace(creative,survial);
				}
			}
			if(gamemode=="����")
			{
				if(strEdit.Find(creative)>0)//����ģʽ
				{

				}
	    		if(strEdit.Find(survial)>0)//����ģʽ
				{
		    		int n = strEdit.Replace(survial,creative);
				}	
			}
		}
		{
			//ʱ��
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
			//����
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
			//����
			spawnkai = spawn+" 01";
			spawnguan = spawn+" 00";
			if (spawnmobs=="��")
			{
				int n = strEdit.Replace(spawnguan,spawnkai);
			}
			if (spawnmobs=="��")
			{
				int n = strEdit.Replace(spawnkai,spawnguan);
			}
		}
		{
			//��ҹ
			daynightkai = daynight+" 88 13 00 00 00 00 00 00";
			daynightguan = daynight+" FF FF FF FF FF FF FF FF";
			if (daynightcycle=="��")
			{
				int n = strEdit.Replace(daynightkai,daynightguan);
			}
			if (daynightcycle=="��")
			{
				int n = strEdit.Replace(daynightguan,daynightkai);
			}
		}
		{
			//�˺�
		    hurtkai = hurt+" 01";
			hurtguan = hurt+" 00";
			if (canhurtornot=="��")
			{
				int n = strEdit.Replace(hurtguan,hurtkai);
			}
			if (canhurtornot=="��")
			{
				int n = strEdit.Replace(hurtkai,hurtguan);
			}
		}
		{
			//����
			flykai = fly+" 01";
			flyguan = fly+" 00";
			if (canflyornot=="��")
			{
				int n = strEdit.Replace(flyguan,flykai);
			}
			if (canflyornot=="��")
			{
				int n = strEdit.Replace(flykai,flyguan);
			}
		}
		{
			//��ͼ����
			
		}
		//ת��
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
		MessageBox("�޸ĳɹ���");
	}
}

