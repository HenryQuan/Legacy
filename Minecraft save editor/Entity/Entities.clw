; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEntitiesDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Entities.h"

ClassCount=4
Class1=CEntitiesApp
Class2=CEntitiesDlg

ResourceCount=6
Resource2=IDD_ENTITIES_DIALOG
Resource3=IDD_ENTITIES_DIALOG (Chinese (中国))
Resource1=IDR_MAINFRAME
Resource4=IDD_replaceentities
Class3=CColour
Resource5=IDD_colour
Class4=CReplace
Resource6=IDR_MENU1

[CLS:CEntitiesApp]
Type=0
HeaderFile=Entities.h
ImplementationFile=Entities.cpp
Filter=N

[CLS:CEntitiesDlg]
Type=0
HeaderFile=EntitiesDlg.h
ImplementationFile=EntitiesDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MENUITEM32772



[DLG:IDD_ENTITIES_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CEntitiesDlg

[DLG:IDD_ENTITIES_DIALOG (Chinese (中国))]
Type=1
Class=CEntitiesDlg
ControlCount=11
Control1=IDC_STATIC,static,1342177294
Control2=IDC_STATIC,button,1342177287
Control3=IDC_BUTTON7,button,1342242816
Control4=IDC_total,static,1342308352
Control5=IDC_BUTTON1,button,1342242816
Control6=IDC_BUTTON2,button,1342242816
Control7=IDC_BUTTON3,button,1342242816
Control8=IDC_BUTTON4,button,1342242816
Control9=IDC_BUTTON5,button,1342242816
Control10=IDC_BUTTON8,button,1342242816
Control11=IDC_openornot,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=CEntitiesDlg
Command1=ID_openentitiesdat
Command2=ID_makepig
Command3=ID_cancelpig
Command4=ID_MENUITEM32772
CommandCount=4

[CLS:CColour]
Type=0
HeaderFile=Colour.h
ImplementationFile=Colour.cpp
BaseClass=CDialog
Filter=D
LastObject=CColour
VirtualFilter=dWC

[DLG:IDD_colour]
Type=1
Class=CColour
ControlCount=4
Control1=IDC_id,edit,1350639745
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816

[DLG:IDD_replaceentities]
Type=1
Class=CReplace
ControlCount=6
Control1=IDC_BUTTON1,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_a,edit,1350631553
Control5=IDC_b,edit,1350631553
Control6=IDC_BUTTON2,button,1342242816

[CLS:CReplace]
Type=0
HeaderFile=Replace.h
ImplementationFile=Replace.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO1
VirtualFilter=dWC

