#if !defined(AFX_LOGFILECLS_H__564B8896_1117_43F9_9937_5523B751EA5E__INCLUDED_)
#define AFX_LOGFILECLS_H__564B8896_1117_43F9_9937_5523B751EA5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogFilecls.h : header file
//

#include "User.h"
/////////////////////////////////////////////////////////////////////////////
// CLogFilecls dialog

class CLogFilecls : public CDialog
{
// Construction
public:
	CLogFilecls(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogFilecls)
	enum { IDD = IDD_LOGDIALOG };
	User * m_cu_user;

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogFilecls)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogFilecls)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnClear();
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGFILECLS_H__564B8896_1117_43F9_9937_5523B751EA5E__INCLUDED_)
