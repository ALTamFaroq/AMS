#if !defined(AFX_NICEHYBEREXX_H__B6DE569B_2987_4B47_9635_66D626312985__INCLUDED_)
#define AFX_NICEHYBEREXX_H__B6DE569B_2987_4B47_9635_66D626312985__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NiceHyberEXX.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NiceHyberEX window

class NiceHyberEX : public CStatic
{
// Construction
public:
	NiceHyberEX();

// Attributes
public:
	int w,h,top,bottom; /* width , hieght,top and bottom of the hyber*/
	CRect h_rect;
	bool Is_First_Drown,Is_Down;   /* to first drown */
	CDC Normal_DC, Move_DC, Down_DC; /* CDCs  for the events */
	CBitmap Normal_bmp,Move_bmp, Down_bmp;;
	h_State Hyber_State;
	HCURSOR m_hC;  /* hyber cursor*/
	CFont font;    
    LOGFONT lf;
	COLORREF Normal_Color, Move_Color,Down_Color,Down_BK_Color;
	CString  h_Name;
	CDialog * h_parentDlg;
	FACTION Funcion_Address;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NiceHyberEX)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~NiceHyberEX();

	// Generated message map functions
protected:
	//{{AFX_MSG(NiceHyberEX)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NICEHYBEREXX_H__B6DE569B_2987_4B47_9635_66D626312985__INCLUDED_)
