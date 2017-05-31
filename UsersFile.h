// UsersFile.h: interface for the UsersFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERSFILE_H__B3B1ECB3_D46C_4974_98CD_214BC689AF40__INCLUDED_)
#define AFX_USERSFILE_H__B3B1ECB3_D46C_4974_98CD_214BC689AF40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "User.h"

class UsersFile  
{
public:
	int GetNumberOfAdmin( User ** u,int maxSize);
	bool DeleteUser(CString m_User);
	bool SetUserAccount(User *user,CString m_uName);
	void SetUser(User & m_user);
	bool AddUser(CString U_name,CString U_pass, int Is_Admin);
	short ret;
	CDialog * m_parent;
	 
	bool Is_U_Member(CString U_name,CString U_pass="");
	bool Store(CString);
	void ToBackup();
	bool Load_Users(CString csFile_path);
	UsersFile();
	virtual ~UsersFile();
	

};

#endif // !defined(AFX_USERSFILE_H__B3B1ECB3_D46C_4974_98CD_214BC689AF40__INCLUDED_)
