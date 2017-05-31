// hproDlg.h : header file
//

#if !defined(AFX_HPRODLG_H__1C136616_EC3B_42F6_8B23_AD3F8A004921__INCLUDED_)
#define AFX_HPRODLG_H__1C136616_EC3B_42F6_8B23_AD3F8A004921__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "user.h"
#include "nicehyber.h"
#include "nicehyberexx.h"
#include "LogonDlg.h"
#include "camerConnectionDlg.h"
#include "baseframe.h"
#include "Monitoring.h"
#include "User_account.h"
#include "Sytem_settingDlg.h"
#include "About.h"
#include "AMS_CMU.h"
#include "AdminAccount.h"





/////////////////////////////////////////////////////////////////////////////
// CHproDlg dialog

class CHproDlg : public CDialog
{
// Construction
public:
	CHproDlg(CWnd* pParent = NULL);	// standard constructor
	FACTION pFunction;
	camerConnectionDlg camerdlg; 
    CBaseFrame baseframedlg;
	Monitoring monitordlg;
	Transformer m_Tansformer;
	FrameDisplayer m_FrameDisplayer;
	AMS_CMU * m_CMU;
	HWND m_hMonitoring_Hyber_Window;
	User* m_cuurent_user;
	CObArray  Users_Array;
	SystemSetting m_Syssetting;
	


	



    /* Freind functions*/
	
	friend void OnCameraConnection(CHproDlg*);
	friend void OnBaseFrame(CHproDlg*);	
	friend void OnMontoring(CHproDlg*);	
	friend void OnUserAccount(CHproDlg*);
	friend void OnSystemSetting(CHproDlg*);
	friend void OnOpenHelp(CHproDlg*);
	friend void OnAbout(CHproDlg*);
	friend void OnExit(CHproDlg*);
	friend void OnReco(CHproDlg* pdlg);

	NiceHyber y[3];
	NiceHyberEX hEx[5];

// Dialog Data
	//{{AFX_DATA(CHproDlg)
	enum { IDD = IDD_HPRO_DIALOG };
	
	
    

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHproDlg)
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHproDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void OnCancel();
	afx_msg void OnOK();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
static CDialog * last_object;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HPRODLG_H__1C136616_EC3B_42F6_8B23_AD3F8A004921__INCLUDED_)
