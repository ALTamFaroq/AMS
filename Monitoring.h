#if !defined(AFX_MONITORING_H__5BE4BA4C_591F_40E3_9C20_E9423D364473__INCLUDED_)
#define AFX_MONITORING_H__5BE4BA4C_591F_40E3_9C20_E9423D364473__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Monitoring.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Monitoring dialog

class Monitoring : public CDialog
{
// Construction
public:
	void StartMonitoring();
	Monitoring(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Monitoring)
	enum { IDD = IDD_MONITORING };
	HWND  m_hWnd_Current_frame;
	HWND  m_hWnd_Base_Frame;
	HWND  m_hWnd_Filterd_Frame;
	HWND  m_hWnd_Histogram;
	HDC   m_hDC; 
	CRect m_rect_Current_frame;
	CRect m_rect_Base_Frame;
	CRect m_rect_Histogram;
	CRect m_rect_Filtered_Frame;
	bool Is_Monitored;
	HWND m_Start;
	HWND m_Stop;


	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Monitoring)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Monitoring)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCancel();
	afx_msg void OnStart();
	afx_msg void OnStop();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONITORING_H__5BE4BA4C_591F_40E3_9C20_E9423D364473__INCLUDED_)
