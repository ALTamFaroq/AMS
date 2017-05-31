// User.cpp: implementation of the User class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "User.h"




#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL( User, CObject, 1 )

User::User()
{
Is_Admin=false;
}

User::User(CString U_name,CString U_pass,int Is_admin)
{
  Username=U_name;
  Userpassword=Crypt_Password(U_pass);
  Is_Admin=Is_admin;
  
}


User::~User()
{

}

void User::Serialize(CArchive &archive)
{
    // call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );
   // now do the stuff for our specific class
    if( archive.IsStoring() )
	{
		archive << Username;
		archive << Userpassword;
		archive << Is_Admin;

	}
    else
	{
        archive >> Username;
		archive >> Userpassword;
		archive >> Is_Admin;
	
	}

}





void User::SetUsername(CString U_name)
{
	Username=U_name;


}

void User::SetUserpassword(CString U_pass)
{
	Userpassword= Crypt_Password(U_pass);

}

CString User::GetUsername()
{
return Username;

}

CString User::GetUserpassword()
{
	CString temp_pass=Crypt_Password(Userpassword);
	return temp_pass;

}

bool User::LoadFromFile(CString csFile_Path)

{
	
	CFileStatus status;
	

	CFileException ex;
	bool bOpenOK=false;
	if(CFile::GetStatus( csFile_Path, status ))
	{
		if( User_file.Open(csFile_Path,CFile::modeRead,&ex))
		{
        CArchive archive(&User_file, CArchive::load);
		Serialize(archive);
		archive.Close();
        User_file.Close();
		bOpenOK=true;
		}
		else
        { 
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			return false;
		}

	}
	
	return bOpenOK;

	


}

bool User::StoreToFile(CString csFile_Path)
{
	    CFileException ex;
		
	    if(User_file.Open(csFile_Path,CFile::modeCreate|CFile::modeWrite,&ex))
		{
        CArchive archive(&User_file, CArchive::store);
		Serialize(archive);
		archive.Close();
        User_file.Close();
		}
		else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			return false;
		}

		
	return true;

}

CString User::Crypt_Password(CString Temp_pass)
{
	CString tempP=Temp_pass;

          
		  for(int i=0;i<Temp_pass.GetLength();i++)
		  {
			 char c=Temp_pass.GetAt(i)^'¤';
			  tempP.SetAt(i,c);
		  }
		  return tempP;
}


bool User::IsEqual(CString U_pass)
{
	U_pass=Crypt_Password(U_pass);
	if (U_pass==Userpassword)
		return true;
	return false;


}
void User:: Backup(CString csBackup_path)
{
	
	StoreToFile(csBackup_path+"\\"+Username + ".ams");

}
