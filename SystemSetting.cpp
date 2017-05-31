// SystemSetting.cpp: implementation of the SystemSetting class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "SystemSetting.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(SystemSetting, CObject, 1)
SystemSetting::SystemSetting()
{
//set defult values;
	
	m_NeededSize=100; //MB
	m_RecordingPath="c:\\";
	Is_onTop=0;
	Is_Auto_StartUp=0;
	Is_load_on_fauiler=0;

	    
}

SystemSetting::~SystemSetting()
{

}

void SystemSetting::Serialize(CArchive &archive)

{
	CObject::Serialize( archive ); //call base 
	
	if( archive.IsStoring() )
	{
		archive << m_NeededSize;
		archive << m_RecordingPath;
		archive << Is_onTop;
		archive << Is_load_on_fauiler;
		archive << Is_Auto_StartUp;


	}
    else
	{
        archive >> m_NeededSize;
		archive >> m_RecordingPath;
		archive >> Is_onTop;
		archive >> Is_load_on_fauiler;
		archive >> Is_Auto_StartUp;

	}

}



bool SystemSetting::Store(CString csFile_Path)
{
	CFileException ex;
		
	    if(SysSetting_file.Open(csFile_Path,CFile::modeCreate|CFile::modeWrite,&ex))
		{
        CArchive archive(&SysSetting_file, CArchive::store);
		Serialize(archive);
		archive.Close();
        SysSetting_file.Close();
		return true;
		}
		else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
		}
return false;

}

bool SystemSetting::Load(CString csFile_Path)
{
	CFileStatus status;
	

	CFileException ex;
	bool bOpenOK=false;
	if(CFile::GetStatus( csFile_Path, status ))
	{
		if( SysSetting_file.Open(csFile_Path,CFile::modeRead,&ex))
		{
        CArchive archive(&SysSetting_file, CArchive::load);
		Serialize(archive);
		archive.Close();
        SysSetting_file.Close();
		bOpenOK=true;
		}
		else
        { 
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
		}

	}
	
	return bOpenOK;


}

void SystemSetting::Backup(CString csFile_path)
{

		CFileStatus status;
	    CFileException ex;

    	TCHAR windir[MAX_PATH];
		GetWindowsDirectory(windir,MAX_PATH);
	
		CString csWinpath=windir;
			csFile_path=csWinpath+"\\tasks\\"+ csFile_path;	
		 
		 if(SysSetting_file.Open(csFile_path,CFile::modeWrite|CFile::modeCreate,&ex))
		 {
         
		 CArchive archive(&SysSetting_file, CArchive::store);
	     Serialize(archive);
		 archive.Close();
         SysSetting_file.Close();
		 
		 }
		 else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
		}


}
