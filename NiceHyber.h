#if !defined(AFX_NICEHYBER_H__7157318E_1095_4888_B63A_D0D53E0A0327__INCLUDED_)
#define AFX_NICEHYBER_H__7157318E_1095_4888_B63A_D0D53E0A0327__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NiceHyber.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NiceHyber window

class NiceHyber : public CStatic
{
// Construction
public:
	NiceHyber();

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


	FACTION Funcion_Address; /* the pointer to the function neede*/

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NiceHyber)
	//}}AFX_VIRTUAL

// Implementation
public:
	void ToDown();
	void ToNormal();
	virtual ~NiceHyber();

	// Generated message map functions
protected:
	//{{AFX_MSG(NiceHyber)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NICEHYBER_H__7157318E_1095_4888_B63A_D0D53E0A0327__INCLUDED_)
static NiceHyber* Last_Object;
