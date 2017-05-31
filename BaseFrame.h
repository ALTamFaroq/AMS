#if !defined(AFX_BASEFRAME_H__BC30ACC8_A0EB_4242_8A76_E5A4F8E38B62__INCLUDED_)
#define AFX_BASEFRAME_H__BC30ACC8_A0EB_4242_8A76_E5A4F8E38B62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BaseFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBaseFrame dialog

class CBaseFrame : public CDialog
{
// Construction
public:
	void ComputeDisplayRect();
	CBaseFrame(CWnd* pParent = NULL);   // standard constructor
    CRect m_ShowArea_rect;
	 HWND Showarea_Wnd;
// Dialog Data
	//{{AFX_DATA(CBaseFrame)
	enum { IDD = IDD_BASE_FRAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseFrame)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBaseFrame)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnCancel();
	afx_msg void OnOk();
	afx_msg void OnCreatebase();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEFRAME_H__BC30ACC8_A0EB_4242_8A76_E5A4F8E38B62__INCLUDED_)
