// User.h: interface for the User class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USER_H__9FF892E5_B4B9_4276_B38A_8DC9DD9A6F3D__INCLUDED_)
#define AFX_USER_H__9FF892E5_B4B9_4276_B38A_8DC9DD9A6F3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class User : public CObject  
{
public:
	bool LoadFromFile(CString);
	bool StoreToFile(CString csFile_Path);
		DECLARE_SERIAL( User )
	User(CString,CString,int);
             User();

	virtual ~User();
	void Serialize( CArchive& archive );
	void SetUsername(CString);
	void SetUserpassword(CString);
	CString GetUsername();
	CString GetUserpassword();
	CString Crypt_Password(CString Temp_pass);
	bool IsEqual(CString U_pass);
	void Backup(CString);


public :
	
	CFile User_file;
    int Is_Admin;
private :
	CString Username;
	CString Userpassword;
	


};

#endif // !defined(AFX_USER_H__9FF892E5_B4B9_4276_B38A_8DC9DD9A6F3D__INCLUDED_)
