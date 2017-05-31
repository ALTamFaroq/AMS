// Monitoring.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "Monitoring.h"
#include "hproDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Monitoring dialog


Monitoring::Monitoring(CWnd* pParent /*=NULL*/)
	: CDialog(Monitoring::IDD, pParent)
{
	//{{AFX_DATA_INIT(Monitoring)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	Is_Monitored=false;
}


void Monitoring::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Monitoring)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Monitoring, CDialog)
	//{{AFX_MSG_MAP(Monitoring)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Monitoring message handlers



BOOL Monitoring::OnEraseBkgnd(CDC* pDC) 
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

void Monitoring::OnCancel() 
{
	
	
}

void Monitoring::OnStart() 
{
	
	if((((CHproDlg*)GetParent())->m_CMU))
	if(!((CHproDlg*)GetParent())->m_CMU->Is_Connected)
	{
		AfxMessageBox("You must connect to Camera befor start monitoring !");
		return;

	}
		if(!(((CHproDlg*)GetParent())->m_Tansformer.m_base_cls.Is_Base_Created))
		{
			AfxMessageBox("You must create Base Frame befor start monitoring !");
			return;
		}

	GetDlgItem(IDC_CURRENT_FRAME,&m_hWnd_Current_frame);
	GetDlgItem(IDC_BASE,&m_hWnd_Base_Frame);
	GetDlgItem(IDC_FILTERED_FRAME,&m_hWnd_Filterd_Frame);
	GetDlgItem(IDC_HISTOGRAM,&m_hWnd_Histogram);
	m_hDC=GetDC()->m_hDC;
	//compute the rect of these windows
	CRect m_rect;
	GetWindowRect(&m_rect); //main rect

	//get current rect;
       ::GetWindowRect(m_hWnd_Current_frame,&m_rect_Current_frame);
	    ScreenToClient(&m_rect_Current_frame);
	   m_rect_Current_frame.bottom-=5;
	   m_rect_Current_frame.right-=5;
	   m_rect_Current_frame.top+=5;
	   m_rect_Current_frame.left+=5;
	  
   //get base rect
	   
	   
	   ::GetWindowRect(m_hWnd_Base_Frame,&m_rect_Base_Frame);
	    ScreenToClient(&m_rect_Base_Frame);
	    m_rect_Base_Frame.bottom-=5;
	    m_rect_Base_Frame.right-=5;
	    m_rect_Base_Frame.top+=5;
	    m_rect_Base_Frame.left+=5;
	   
  //get histogram rect
        
	   ::GetWindowRect(m_hWnd_Histogram,&m_rect_Histogram);
	    ScreenToClient(&m_rect_Histogram);
	   m_rect_Histogram.bottom-=5;
	   m_rect_Histogram.right-=5;
	   m_rect_Histogram.top+=5;
	   m_rect_Histogram.left+=5;



//get filterd frame rect

	   ::GetWindowRect(m_hWnd_Filterd_Frame,&m_rect_Filtered_Frame);
	    ScreenToClient(&m_rect_Filtered_Frame);
	   m_rect_Filtered_Frame.bottom-=5;
	   m_rect_Filtered_Frame.right-=5;
	   m_rect_Filtered_Frame.top+=5;
	   m_rect_Filtered_Frame.left+=5;

	   
	   
	   
	   
	   //start showing




	   ((CHproDlg*)GetParent())->m_FrameDisplayer.m_hDC=m_hDC;
	   ((CHproDlg*)GetParent())->m_FrameDisplayer.m_Rect=&m_rect_Current_frame;
       ((CHproDlg*)GetParent())->m_Tansformer.m_base_rect=&m_rect_Base_Frame;
       ((CHproDlg*)GetParent())->m_Tansformer.m_Histogram_rect=&m_rect_Histogram;
	   ((CHproDlg*)GetParent())->m_Tansformer.SetPort(OPEN_PORT_6);
	   ((CHproDlg*)GetParent())->m_Tansformer.m_Frame_Frag.m_filterd_rect=&m_rect_Filtered_Frame;
	   ((CHproDlg*)GetParent())->m_Tansformer.m_Frame_Frag.m_parent_hDC=m_hDC;

	   Is_Monitored=true;
       ::EnableWindow(m_Start,false);
	   ::EnableWindow(m_Stop,true);
	   
}

void Monitoring::OnStop() 
{
	if(::MessageBox(m_hWnd,"Are you sure you want to Stop Monitoring?","Monitoring",MB_YESNO|MB_ICONQUESTION)!=7/*No*/)
	{
		((CHproDlg*)GetParent())->m_Tansformer.SetPort(OPEN_PORT_2);
		
		 
		 ::EnableWindow(m_Start,true);
		 ::EnableWindow(m_Stop,false);
		 Is_Monitored=false;
		 

	}
	
}

BOOL Monitoring::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_START,&m_Start);
	GetDlgItem(IDC_STOP,&m_Stop);
	::EnableWindow(m_Stop,false);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void Monitoring::StartMonitoring()
{
OnStart();
}
