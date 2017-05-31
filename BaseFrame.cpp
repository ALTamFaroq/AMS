// BaseFrame.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "BaseFrame.h"
#include "hproDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBaseFrame dialog


CBaseFrame::CBaseFrame(CWnd* pParent /*=NULL*/)
	: CDialog(CBaseFrame::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBaseFrame)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CBaseFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBaseFrame)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBaseFrame, CDialog)
	//{{AFX_MSG_MAP(CBaseFrame)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_CREATEBASE, OnCreatebase)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBaseFrame message handlers



BOOL CBaseFrame::OnEraseBkgnd(CDC* pDC) 
{
	
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





void CBaseFrame::OnCancel() 
{
	
}

void CBaseFrame::OnOk() 
{
	
}

void CBaseFrame::OnCreatebase() 
{
if(!(((CHproDlg*)GetParent())->m_CMU->Is_Connected))
{
	 //camera not connected
	 AfxMessageBox("You must connect to camera befor creatting base frame ");
	 return;
}
 
//ceate base frame

  ((CHproDlg*)GetParent())->m_Tansformer.SetPort(OPEN_PORT_3);
  

}

void CBaseFrame::ComputeDisplayRect()
{
	GetDlgItem(IDC_CAPWINDOW,&Showarea_Wnd);
   if(Showarea_Wnd!=NULL)
   {
	   ::GetWindowRect(Showarea_Wnd,&m_ShowArea_rect);
	    ScreenToClient(&m_ShowArea_rect);
	   m_ShowArea_rect.bottom-=10;
	   m_ShowArea_rect.right-=10;
	   m_ShowArea_rect.top+=10;
	   m_ShowArea_rect.left+=10;
}

}
