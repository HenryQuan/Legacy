; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPEiTemEditorDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PEiTemEditor.h"

ClassCount=2
Class1=CPEiTemEditorApp
Class2=CPEiTemEditorDlg

ResourceCount=5
Resource2=IDR_MAINFRAME
Resource3=IDD_PEITEMEDITOR_DIALOG
Resource4=IDD_PEITEMEDITOR_DIALOG (Chinese (中国))
Resource5=IDR_MENU1

[CLS:CPEiTemEditorApp]
Type=0
HeaderFile=PEiTemEditor.h
ImplementationFile=PEiTemEditor.cpp
Filter=N

[CLS:CPEiTemEditorDlg]
Type=0
HeaderFile=PEiTemEditorDlg.h
ImplementationFile=PEiTemEditorDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM32774



[DLG:IDD_PEITEMEDITOR_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CPEiTemEditorDlg

[DLG:IDD_PEITEMEDITOR_DIALOG (Chinese (中国))]
Type=1
Class=CPEiTemEditorDlg
ControlCount=15
Control1=IDC_STATIC,static,1342177294
Control2=IDC_COMBO1,combobox,1344340226
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_id,edit,1350639745
Control9=IDC_count,edit,1350639745
Control10=IDC_damage,edit,1350639745
Control11=IDC_BUTTON1,button,1342242816
Control12=IDC_BUTTON2,button,1342242816
Control13=IDC_BUTTON3,button,1342242816
Control14=IDC_BUTTON4,button,1342242816
Control15=IDC_BUTTON6,button,1342242816

[MNU:IDR_MENU1]
Type=1
Class=CPEiTemEditorDlg
Command1=ID_openlevedat
Command2=ID_MENUITEM32774
CommandCount=2

