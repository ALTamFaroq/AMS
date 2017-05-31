# Microsoft Developer Studio Project File - Name="hpro" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=hpro - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "hpro.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "hpro.mak" CFG="hpro - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "hpro - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "hpro - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "hpro - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x2401 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x2401 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "hpro - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x2401 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x2401 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"Debug/AMS.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "hpro - Win32 Release"
# Name "hpro - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\About.cpp
# End Source File
# Begin Source File

SOURCE=.\AdminAccount.cpp
# End Source File
# Begin Source File

SOURCE=.\AMS_AFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\AMS_CMU.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\BaseFrameAcquirer_Fragmentary.cpp
# End Source File
# Begin Source File

SOURCE=.\camerConnectionDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FrameDisplayer.cpp
# End Source File
# Begin Source File

SOURCE=.\FrameFragmentary.cpp
# End Source File
# Begin Source File

SOURCE=.\HistogramDislpayer.cpp
# End Source File
# Begin Source File

SOURCE=.\hpro.cpp
# End Source File
# Begin Source File

SOURCE=.\hpro.rc
# End Source File
# Begin Source File

SOURCE=.\hproDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LogFilecls.cpp
# End Source File
# Begin Source File

SOURCE=.\LogonDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Monitoring.cpp
# End Source File
# Begin Source File

SOURCE=.\NiceHyber.cpp
# End Source File
# Begin Source File

SOURCE=.\NiceHyberEXX.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SystemSetting.cpp
# End Source File
# Begin Source File

SOURCE=.\Sytem_settingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Transformer.cpp
# End Source File
# Begin Source File

SOURCE=.\User.cpp
# End Source File
# Begin Source File

SOURCE=.\User_account.cpp
# End Source File
# Begin Source File

SOURCE=.\UsersFile.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\About.h
# End Source File
# Begin Source File

SOURCE=.\AdminAccount.h
# End Source File
# Begin Source File

SOURCE=.\AMS_AFrame.h
# End Source File
# Begin Source File

SOURCE=.\AMS_CMU.h
# End Source File
# Begin Source File

SOURCE=.\BaseFrame.h
# End Source File
# Begin Source File

SOURCE=.\BaseFrameAcquirer_Fragmentary.h
# End Source File
# Begin Source File

SOURCE=.\camerConnectionDlg.h
# End Source File
# Begin Source File

SOURCE=.\FrameDisplayer.h
# End Source File
# Begin Source File

SOURCE=.\FrameFragmentary.h
# End Source File
# Begin Source File

SOURCE=.\HistogramDislpayer.h
# End Source File
# Begin Source File

SOURCE=.\hpro.h
# End Source File
# Begin Source File

SOURCE=.\hproDlg.h
# End Source File
# Begin Source File

SOURCE=.\logfile.h
# End Source File
# Begin Source File

SOURCE=.\LogFilecls.h
# End Source File
# Begin Source File

SOURCE=.\LogonDlg.h
# End Source File
# Begin Source File

SOURCE=.\Monitoring.h
# End Source File
# Begin Source File

SOURCE=.\NiceHyber.h
# End Source File
# Begin Source File

SOURCE=.\NiceHyberEXX.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SystemSetting.h
# End Source File
# Begin Source File

SOURCE=.\Sytem_settingDlg.h
# End Source File
# Begin Source File

SOURCE=.\Transformer.h
# End Source File
# Begin Source File

SOURCE=.\User.h
# End Source File
# Begin Source File

SOURCE=.\User_account.h
# End Source File
# Begin Source File

SOURCE=.\UsersFile.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\12.bmp
# End Source File
# Begin Source File

SOURCE=.\res\about.bmp
# End Source File
# Begin Source File

SOURCE=.\res\capwindow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\capwindow_mon.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dialogs.bmp
# End Source File
# Begin Source File

SOURCE=.\res\H_point.cur
# End Source File
# Begin Source File

SOURCE=.\res\hand.cur
# End Source File
# Begin Source File

SOURCE=.\res\hpro.ico
# End Source File
# Begin Source File

SOURCE=.\res\hpro.rc2
# End Source File
# Begin Source File

SOURCE=.\res\no.bin
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\111.wav
# End Source File
# Begin Source File

SOURCE=.\res\notify.wav
# End Source File
# End Target
# End Project
