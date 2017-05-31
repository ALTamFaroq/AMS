// camerConnectionDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "camerConnectionDlg.h"
#include "hproDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// camerConnectionDlg dialog


camerConnectionDlg::camerConnectionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(camerConnectionDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(camerConnectionDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void camerConnectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(camerConnectionDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(camerConnectionDlg, CDialog)
	//{{AFX_MSG_MAP(camerConnectionDlg)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_DISCONNECT, OnDisconnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// camerConnectionDlg message handlers



BOOL camerConnectionDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL camerConnectionDlg::OnEraseBkgnd(CDC* pDC) 
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



void camerConnectionDlg::OnConnect() 
{




//delete Showarea_Wnd;


if(m_CMU->Camera_Connect())
{
	 GetDlgItem(IDC_CAPWINDOW,&Showarea_Wnd);
   if(Showarea_Wnd!=NULL)
   
   {
	   //Showarea_Wnd->ScreenToClient(&m_ShowArea_rect);
	  
	  
	  ::GetWindowRect(Showarea_Wnd,&m_ShowArea_rect);
	   ScreenToClient(&m_ShowArea_rect);
	   m_ShowArea_rect.bottom-=10;
	   m_ShowArea_rect.right-=10;
	   m_ShowArea_rect.top+=10;
	   m_ShowArea_rect.left+=10;
	   
   }

  if(m_CMU->Start_Sequence_NoFile())
	{
     
	 ((CHproDlg*)(GetParent()))->m_FrameDisplayer.Create_AFrameDC(&(m_CMU->m_Next_AFrame));
	 ((CHproDlg*)(GetParent()))->m_Tansformer.SetPort(OPEN_PORT_2);
	 ((CHproDlg*)(GetParent()))->m_Tansformer.w=m_CMU->m_Next_AFrame.AF_Bmpinfo.bmiHeader.biWidth; //width of GraedData
	 ((CHproDlg*)(GetParent()))->m_Tansformer.h=m_CMU->m_Next_AFrame.AF_Bmpinfo.bmiHeader.biHeight; //hieght of GraedData

	 

	}
}

}

void camerConnectionDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	m_CMU->DestroyCurrentCaptureWindow();
	
 
		
}



void camerConnectionDlg::OnCancel() 
{
	
}

void camerConnectionDlg::OnOk() 
{
	
}

void camerConnectionDlg::OnDisconnect() 
{  
	if(!m_CMU->Is_Connected)
	{
		AfxMessageBox("Camera dose not connected to close it !");
		return;
	}
	if(::MessageBox(this->m_hWnd,"Are you sure you want to close camera?","Camers Disconnect",MB_YESNO|MB_ICONQUESTION)!=7/*No*/)

	 m_CMU->DestroyCurrentCaptureWindow();
	
	

}
