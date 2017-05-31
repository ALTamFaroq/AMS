// About.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "About.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAbout dialog


CAbout::CAbout(CWnd* pParent /*=NULL*/)
	: CDialog(CAbout::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAbout::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAbout)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAbout, CDialog)
	//{{AFX_MSG_MAP(CAbout)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAbout message handlers

BOOL CAbout::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
CBitmap b_bmp;
	    b_bmp.LoadBitmap(IDB_DIALOG);
	
	   CBrush backBrush;	  
	  backBrush.CreatePatternBrush(&b_bmp);

      // Save old brush
      CBrush* pOldBrush = pDC->SelectObject(&backBrush);

      CRect rect;
      pDC->GetClipBox(&rect);     // Erase the area needed

      pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),
          PATCOPY);
      pDC->SelectObject(pOldBrush);
      return TRUE;
}
