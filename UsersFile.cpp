// UsersFile.cpp: implementation of the UsersFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "UsersFile.h"
#include "hproDlg.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


UsersFile::UsersFile()
{
ret=0;
}

UsersFile::~UsersFile()
{

}

bool UsersFile::Load_Users(CString csFile_path)
{
	CFileStatus status;
	CFile u_file;
	CFileException ex;
	bool result=false;
	
	if(CFile::GetStatus( csFile_path, status ))
	{
		result=true;
		 
		 if(u_file.Open(csFile_path,CFile::modeRead,&ex))
		 {
         CArchive archive(&u_file, CArchive::load);
	     ((CHproDlg*)m_parent)->Users_Array.Serialize(archive);
		 archive.Close();
         u_file.Close();
		 }
		 else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			result=false;
		}
     

	}
	else
	{
		//goto to backup file and load 

		TCHAR windir[MAX_PATH];
		GetWindowsDirectory(windir,MAX_PATH);
	    csFile_path=windir;
		csFile_path+="\\tasks\\AMSUsersBackUp.AMS";

	if(CFile::GetStatus( csFile_path, status ))
	{
		
		 result=true;
		 if(u_file.Open(csFile_path,CFile::modeRead,&ex))
		 {
         
         CArchive archive(&u_file, CArchive::load);
	     ((CHproDlg*)m_parent)->Users_Array.Serialize(archive);
		 archive.Close();
         u_file.Close();
		 CreateDirectory("Users",0);
		 Store("Users\\AMSUSERS.ams");
		 }
		 else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			result=false;
		}


	}	

	}
	return result;

}

void UsersFile::ToBackup()
{
		CFileStatus status;
	    CFile u_file;
	    CFileException ex;

    	TCHAR windir[MAX_PATH];
		GetWindowsDirectory(windir,MAX_PATH);
	
		CString csFile_path=windir;
			csFile_path+="\\tasks\\AMSUsersBackUp.ams";	
		 
		 if(u_file.Open(csFile_path,CFile::modeWrite|CFile::modeCreate,&ex))
		 {
         
		 CArchive archive(&u_file, CArchive::store);
	     ((CHproDlg*)m_parent)->Users_Array.Serialize(archive);
		 archive.Close();
         u_file.Close();
		 
		 }
		 else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
		}


		


}

bool UsersFile::Store(CString csFile_path )
{
		CFileStatus status;
	    CFile u_file;
	    CFileException ex;
	    bool result=true;
	if(u_file.Open(csFile_path,CFile::modeWrite|CFile::modeCreate,&ex))
		 {
           CArchive archive(&u_file, CArchive::store);
	       ((CHproDlg*)m_parent)->Users_Array.Serialize(archive);
		   archive.Close();
           u_file.Close();
		   ToBackup();
		 }
		 else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			result=false;
		}

return result;
}

bool UsersFile::Is_U_Member(CString U_name, CString U_pass)
{

bool result=false;
User** u=(User**)(((CHproDlg*)m_parent)->Users_Array.GetData());
		for(int i=0;i<((CHproDlg*)m_parent)->Users_Array.GetSize();i++)
		{		
		
			
			if (U_name==u[i]->GetUsername())
			{	
				if(U_pass=="")
				{
					return true;
				}
				if(u[i]->IsEqual(U_pass) )
				{
					if(((CHproDlg*)m_parent)->m_cuurent_user==NULL)
				        ((CHproDlg*)m_parent)->m_cuurent_user=u[i];
				  return true;
				}
		        	
			
				else
                {
					AfxMessageBox("Invalid password !");
				return false;
				
				}
				}
			}	  
		
		
           if(U_pass!="")
		   {
			   AfxMessageBox("User account not found");
		   }
		   ret++;
		   if(ret==3)ExitProcess(0);

return result;
}

bool UsersFile::AddUser(CString U_name, CString U_pass, int Is_admin)
{

if(Is_U_Member(U_name))
{
	AfxMessageBox("This name is registred for anthor user");
	return false;
}

((CHproDlg*)m_parent)->Users_Array.Add(new User(U_name,U_pass,Is_admin));

if(!Store("Users\\AMSUsers.ams"))
{
  AfxMessageBox("Unkown error occure\n try agine");
  return false;
}
//ToBackup();
return true;


}

void UsersFile::SetUser(User &m_user)
{
  User** u=(User**)(((CHproDlg*)m_parent)->Users_Array.GetData());
		for(int i=0;i<((CHproDlg*)m_parent)->Users_Array.GetSize();i++)
		{
			if (m_user.GetUsername()==u[i]->GetUsername())
			{
				m_user.Is_Admin=u[i]->Is_Admin;
				
				m_user.SetUserpassword(u[i]->GetUserpassword());
				
			}
		}
}

bool UsersFile::SetUserAccount(User *user,CString m_uName)
{
	int usern=0;
  User** u=(User**)(((CHproDlg*)m_parent)->Users_Array.GetData());
		for(int i=0;i<((CHproDlg*)m_parent)->Users_Array.GetSize();i++)
		{
			if (m_uName==u[i]->GetUsername())
			{   
                if(u[i]->Is_Admin && (user->Is_Admin==0))
				//get number of admins
					if(GetNumberOfAdmin(u,((CHproDlg*)m_parent)->Users_Array.GetSize())<=1)
                    {
                      AfxMessageBox("Account can not be changed, \n because it there is only one administrator ");
					  return false;
					}
				u[i]->SetUsername(user->GetUsername());
				u[i]->Is_Admin=user->Is_Admin;
				CString df=user->GetUserpassword();
				u[i]->SetUserpassword(df);
				usern=i;
				
				break;
			}
		}
	
		if(!Store("Users\\AMSUsers.ams"))
{
	
		AfxMessageBox("Unkown error occure\n try agine");
		return false;
	
  
}

if(m_uName==((CHproDlg*)m_parent)->m_cuurent_user->GetUsername())
{
((CHproDlg*)m_parent)->m_cuurent_user->SetUsername(u[usern]->GetUsername());
((CHproDlg*)m_parent)->m_cuurent_user->SetUserpassword(u[usern]->GetUserpassword());
((CHproDlg*)m_parent)->m_cuurent_user->Is_Admin=u[usern]->Is_Admin;

}
return true;
}

bool UsersFile::DeleteUser(CString m_User)
{
	bool delete_current_user;
	delete_current_user=false;

if(((CHproDlg*)m_parent)->m_cuurent_user->GetUsername()==m_User)
{
	
		if(::MessageBox(((CHproDlg*)m_parent)->m_hWnd,"Are you sure you want to delete your account ? \n if you choose yes ,AMS system must be closed . ","Delete Account",MB_YESNO|MB_ICONQUESTION)!=7/*No*/)
			delete_current_user=true;
} 
	User** u=(User**)(((CHproDlg*)m_parent)->Users_Array.GetData());
		for(int i=0;i<((CHproDlg*)m_parent)->Users_Array.GetSize();i++)
		{
			if (m_User==u[i]->GetUsername())
			{
				 
				
				if(u[i]->Is_Admin)
				{
                  //get number of admins
					if(GetNumberOfAdmin(u,((CHproDlg*)m_parent)->Users_Array.GetSize())<=1)
                    {
                      AfxMessageBox("Account can not be deleted, \n because it there is only one administrator ");
					  return false;
					}
				}
				//delete user
               ((CHproDlg*)m_parent)->Users_Array.RemoveAt(i);
				   
			}
		}

		Store("Users\\AMSUsers.ams");
		AfxMessageBox("Account Deleted ");
		if(delete_current_user)
		{
			ExitProcess(0);
		}
		return true;


}

int UsersFile::GetNumberOfAdmin( User ** u,int maxSize)
{
	int admins;
	admins=0;

for(int i=0;i<maxSize;i++)
{
	if(u[i]->Is_Admin)
		admins++;

}
return admins;
}
