#if !defined(AFX_USER_ACCOUNT_H__47CBFB5A_C880_47E1_ACC3_FB412A101B53__INCLUDED_)
#define AFX_USER_ACCOUNT_H__47CBFB5A_C880_47E1_ACC3_FB412A101B53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// User_account.h : header file
//
#include "UsersFile.h"

/////////////////////////////////////////////////////////////////////////////
// CUser_account dialog

class CUser_account : public CDialog
{
// Construction
public:
	CUser_account(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUser_account)
	enum { IDD = IDD_USER_ACCOUNT_DLG };
	bool is_first;
	CComboBox	m_Cmb_MemberOf;
	UsersFile us_file;
	CString m_user_tochanged;
	User m_user;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUser_account)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUser_account)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBackup();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USER_ACCOUNT_H__47CBFB5A_C880_47E1_ACC3_FB412A101B53__INCLUDED_)
