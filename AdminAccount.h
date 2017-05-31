#if !defined(AFX_ADMINACCOUNT_H__2A5CC8BD_ED41_4DE6_801D_61E633643415__INCLUDED_)
#define AFX_ADMINACCOUNT_H__2A5CC8BD_ED41_4DE6_801D_61E633643415__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdminAccount.h : header file
#include "usersfile.h"

/////////////////////////////////////////////////////////////////////////////
// CAdminAccount dialog

class CAdminAccount : public CDialog
{
// Construction
public:
	void RefreshUsersLiset();
	CAdminAccount(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdminAccount)
	enum { IDD = IDD_DIALOG_ADMIN_ACOUNT };
	CComboBox	m_Cmb_Users;
	UsersFile us_file;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdminAccount)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAdminAccount)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnChangeuseraccount();
	afx_msg void OnAddnewuser();
	virtual BOOL OnInitDialog();
	afx_msg void OnDeleteUser();
	afx_msg void OnViewLog();
	afx_msg void OnBackup();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINACCOUNT_H__2A5CC8BD_ED41_4DE6_801D_61E633643415__INCLUDED_)
