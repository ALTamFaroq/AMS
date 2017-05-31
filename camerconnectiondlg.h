#if !defined(AFX_CAMERCONNECTIONDLG_H__DC324D1E_3975_4515_9872_91A0DED15216__INCLUDED_)
#define AFX_CAMERCONNECTIONDLG_H__DC324D1E_3975_4515_9872_91A0DED15216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// camerConnectionDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// camerConnectionDlg dialog
#include "AMS_CMU.h"

class camerConnectionDlg : public CDialog
{
// Construction
public:
	camerConnectionDlg(CWnd* pParent = NULL);   // standard constructor
    CRect m_ShowArea_rect;
	HWND Showarea_Wnd;

	//AMS_AFrame * m_Next_AFrame;
// Dialog Data
	//{{AFX_DATA(camerConnectionDlg)
	enum { IDD = IDD_CAMERA_CONNECTION };
	AMS_CMU * m_CMU;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(camerConnectionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(camerConnectionDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnConnect();
	afx_msg void OnDestroy();
	afx_msg void OnCancel();
	afx_msg void OnOk();
	afx_msg void OnDisconnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMERCONNECTIONDLG_H__DC324D1E_3975_4515_9872_91A0DED15216__INCLUDED_)
