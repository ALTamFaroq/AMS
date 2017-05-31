#if !defined(AFX_SYTEM_SETTINGDLG_H__31ECCE1F_0AC4_4890_AED2_A4D9ADAD04CE__INCLUDED_)
#define AFX_SYTEM_SETTINGDLG_H__31ECCE1F_0AC4_4890_AED2_A4D9ADAD04CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Sytem_settingDlg.h : header file
//
#include "SystemSetting.h"

/////////////////////////////////////////////////////////////////////////////
// CSytem_settingDlg dialog

class CSytem_settingDlg : public CDialog
{
// Construction
public:
	void StoreCurrentSetting();
	bool LoadCurrentSetting();
	void ListDrivers();
	CSytem_settingDlg(CWnd* pParent = NULL);   // standard constructor
	SystemSetting *m_SysSetting;

// Dialog Data
	//{{AFX_DATA(CSytem_settingDlg)
	enum { IDD = IDD_SYTEM_SETTINGDLG_DIALOG };
	CComboBox	m_Cmb_Driver;
	int		m_Nedded_Size;
	DWORDLONG FreeBytes;
	CButton m_OnTop;
	CButton m_StartUp;
	CButton m_Lanch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSytem_settingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSytem_settingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCmbDriver();
	afx_msg void OnChangeESize();
	virtual void OnOK();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYTEM_SETTINGDLG_H__31ECCE1F_0AC4_4890_AED2_A4D9ADAD04CE__INCLUDED_)
