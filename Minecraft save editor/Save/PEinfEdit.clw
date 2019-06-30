; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPEinfEditDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PEinfEdit.h"

ClassCount=3
Class1=CPEinfEditApp
Class2=CPEinfEditDlg

ResourceCount=4
Resource2=IDR_OpenSave
Resource3=IDD_About
Resource1=IDR_MAINFRAME
Class3=CAbout
Resource4=IDD_PEINFEDIT_DIALOG

[CLS:CPEinfEditApp]
Type=0
HeaderFile=PEinfEdit.h
ImplementationFile=PEinfEdit.cpp
Filter=N

[CLS:CPEinfEditDlg]
Type=0
HeaderFile=PEinfEditDlg.h
ImplementationFile=PEinfEditDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CPEinfEditDlg



[DLG:IDD_PEINFEDIT_DIALOG]
Type=1
Class=CPEinfEditDlg
ControlCount=30
Control1=IDC_spawnmob,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,button,1342177287
Control13=IDC_name,edit,1350633601
Control14=IDC_mode,button,1342242816
Control15=IDC_time,edit,1350631553
Control16=IDC_STATIC,button,1342177287
Control17=IDC_daynight,button,1342242816
Control18=IDC_health,edit,1350631553
Control19=IDC_hurt,button,1342242816
Control20=IDC_mayfly,button,1342242816
Control21=IDC_save,button,1342242816
Control22=IDC_zuobiao,static,1342308353
Control23=IDC_seed,static,1342308353
Control24=IDC_time0,button,1342242816
Control25=IDC_time9600,button,1342242816
Control26=IDC_copyseed,button,1342242816
Control27=IDC_fullhealth,button,1342242816
Control28=IDC_infinityhealth,button,1342242816
Control29=IDC_STATIC,static,1342308352
Control30=IDC_TAB1,SysTabControl32,1342177280

[MNU:IDR_OpenSave]
Type=1
Class=CPEinfEditDlg
Command1=ID_leveldat
Command2=ID_Exit
Command3=ID_About
CommandCount=3

[DLG:IDD_About]
Type=1
Class=CAbout
ControlCount=5
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_BUTTON1,button,1342242816
Control5=IDC_STATIC,static,1342308352

[CLS:CAbout]
Type=0
HeaderFile=About.h
ImplementationFile=About.cpp
BaseClass=CDialog
Filter=D
LastObject=CAbout
VirtualFilter=dWC

