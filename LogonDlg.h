#if !defined(AFX_LOGONDLG_H__E6A0F4A4_B1E5_4F27_89BD_91075F1254BF__INCLUDED_)
#define AFX_LOGONDLG_H__E6A0F4A4_B1E5_4F27_89BD_91075F1254BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogonDlg.h : header file
//
#include "usersfile.h"



/////////////////////////////////////////////////////////////////////////////
// LogonDlg dialog

class LogonDlg : public CDialog
{
// Construction
public:
	LogonDlg(CWnd*  pParent = NULL);   // standard constructor
    
// Dialog Data
	//{{AFX_DATA(LogonDlg)
	enum { IDD = IDD_LOGON };
	UsersFile us_file;
	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LogonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LogonDlg)
	afx_msg void OnPaint();
	afx_msg void OnCancel();
	afx_msg void OnOK();
	afx_msg void OnOk();
	afx_msg void OnLogonFromFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGONDLG_H__E6A0F4A4_B1E5_4F27_89BD_91075F1254BF__INCLUDED_)
