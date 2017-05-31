// hproDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "hproDlg.h"
#include "UsersFile.h"
#include "User_account.h"
#include  "Logfile.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHproDlg dialog

CHproDlg::CHproDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHproDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHproDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	
	m_cuurent_user=NULL;
	last_object=NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHproDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHproDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHproDlg, CDialog)
	//{{AFX_MSG_MAP(CHproDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHproDlg message handlers

BOOL CHproDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	 
	
	y[0].h_Name="Camera Connection";
	y[0].Normal_Color=RGB(255,255,255);
    y[0].Move_Color=RGB(120,120,255);
	y[0].Down_Color=RGB(255,0,0);
    y[0].Down_BK_Color=RGB(173,214,236);
	y[0].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(7,110,185,140),this,185);
	pFunction= (FACTION)OnCameraConnection;
	y[0].Funcion_Address=pFunction;
    y[0].h_parentDlg=this;
	
	y[1].h_Name="Base Frame";
	y[1].Normal_Color=RGB(255,255,255);
    y[1].Move_Color=RGB(120,120,255);
	y[1].Down_Color=RGB(255,0,0);
    y[1].Down_BK_Color=RGB(173,214,236);
	y[1].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(7,140,185,170),this,186);
	pFunction= (FACTION)OnBaseFrame;
	y[1].Funcion_Address=pFunction;
	y[1].h_parentDlg=this;
	
	y[2].h_Name="Monitoring";
	y[2].Normal_Color=RGB(255,255,255);
    y[2].Move_Color=RGB(120,120,255);
	y[2].Down_Color=RGB(255,0,0);
    y[2].Down_BK_Color=RGB(173,214,236);
	y[2].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(7,170,185,200),this,187);
	pFunction= (FACTION)OnMontoring;
	y[2].Funcion_Address=pFunction;
	y[2].h_parentDlg=this;
	m_hMonitoring_Hyber_Window=y[2].m_hWnd;
	
	/*above button*/

	hEx[0].h_Name=" System setting";
	hEx[0].Normal_Color=RGB(255,255,255);
    hEx[0].Move_Color=RGB(120,120,255);
	hEx[0].Down_Color=RGB(255,255,255);
    hEx[0].Down_BK_Color=RGB(24,91,144);
	hEx[0].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(1 ,40,120 ,70),this,188);
    pFunction= (FACTION)OnSystemSetting;
	hEx[0].Funcion_Address=pFunction;
	hEx[0].h_parentDlg=this;

	hEx[1].h_Name="  User account  ";
	hEx[1].Normal_Color=RGB(255,255,255);
    hEx[1].Move_Color=RGB(120,120,255);
	hEx[1].Down_Color=RGB(255,255,255);
    hEx[1].Down_BK_Color=RGB(24,91,144);
	hEx[1].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(120,40,240 ,70),this,188);
    pFunction= (FACTION)OnUserAccount;
	hEx[1].Funcion_Address=pFunction;
	hEx[1].h_parentDlg=this;

	hEx[2].h_Name="      Help     ";
	hEx[2].Normal_Color=RGB(255,255,255);
    hEx[2].Move_Color=RGB(120,120,255);
	hEx[2].Down_Color=RGB(255,255,255);
    hEx[2].Down_BK_Color=RGB(24,91,144);
	hEx[2].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(240,40,360 ,70),this,188);
    pFunction= (FACTION)OnOpenHelp;
	hEx[2].Funcion_Address=pFunction;
	hEx[2].h_parentDlg=this;

	hEx[3].h_Name="      About     ";
	hEx[3].Normal_Color=RGB(255,255,255);
    hEx[3].Move_Color=RGB(120,120,255);
	hEx[3].Down_Color=RGB(255,255,255);
    hEx[3].Down_BK_Color=RGB(24,91,144);
	hEx[3].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(360,40,480 ,70),this,188);
    pFunction= (FACTION)OnAbout;
	hEx[3].Funcion_Address=pFunction;
	hEx[3].h_parentDlg=this;


	hEx[4].h_Name="      Exit     ";
	hEx[4].Normal_Color=RGB(255,255,255);
    hEx[4].Move_Color=RGB(120,120,255);
	hEx[4].Down_Color=RGB(255,255,255);
    hEx[4].Down_BK_Color=RGB(24,91,144);
	hEx[4].Create(NULL,WS_CHILD|SS_NOTIFY |WS_VISIBLE,CRect(480,40,595 ,70),this,188);
    pFunction= (FACTION)OnExit;
	hEx[4].Funcion_Address=pFunction;
	hEx[4].h_parentDlg=this;
	


	//check if this first time system work;
  UsersFile uf;
  uf.m_parent=this;
	if(!uf.Load_Users("Users\\AMSUsers.ams"))
	{
	 CreateDirectory("Users",0);
	 CUser_account useraccountdlg;
	 useraccountdlg.us_file.m_parent=this;
	  useraccountdlg.is_first=true;
	 if(useraccountdlg.DoModal()==IDCANCEL)
	 {
		 ExitProcess(0);
	 }
	 
	 

	 

	}
	else
	{
    
	LogonDlg logondlg;
	logondlg.us_file.m_parent=this;
	logondlg.DoModal();
	/**                     **
	 *  load system setting  *
	 **                     **/

	  CFileStatus status;
   if(CFile::GetStatus("AMSSystemsetting.ams",status))  //if setting file founded
   {
	m_Syssetting.Load("AMSSystemsetting.ams");
   }
	
	// On_TOP

   if(m_Syssetting.Is_onTop)
	{
     CRect rect;
	 GetWindowRect(&rect);	
	 int Scx=GetSystemMetrics(SM_CXSCREEN);
	 int Scy=GetSystemMetrics(SM_CYSCREEN);
	 Scx=(Scx-rect.Width())/2;
	 Scy=(Scy-rect.Height())/2;
	 
	::SetWindowPos(m_hWnd,HWND_TOPMOST ,Scx,Scy,rect.Width(),rect.Height(),SWP_SHOWWINDOW);
	}
	

	

	}
		m_CMU=new AMS_CMU();
		m_Tansformer.m_paren=this;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CHproDlg::OnPaint() 
{
	CDialog::OnPaint();
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CHproDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

// freind functions
void OnCameraConnection(CHproDlg* pDlg)
{
 // show camerconnection view
	
		//first check monitoring not started
       if((pDlg->monitordlg.Is_Monitored))
	   {
		   AfxMessageBox("When Monitoring started ,you can't open this form .Close monitoring and try agine.");
		   pDlg->y[2].ToDown();
		   return;
           
	   }

    if (pDlg->camerdlg.m_hWnd==0)
	{
	  (pDlg->camerdlg).Create(IDD_CAMERA_CONNECTION,pDlg);
	  (pDlg->camerdlg).SetWindowPos(NULL,185,80,599,374-10,SWP_SHOWWINDOW);
	   pDlg->camerdlg.m_CMU=pDlg->m_CMU;
	   pDlg->m_Tansformer.m_FrDisplayer=&(pDlg->m_FrameDisplayer);
	   pDlg->m_CMU->SetParentCls(&(pDlg->m_Tansformer));
	}
	else
	(pDlg->camerdlg).SetWindowPos(NULL,185,80,599,374-10,SWP_SHOWWINDOW);
     
	




	
	if(last_object!=NULL)
	 {
		 last_object->ShowWindow(0);
	 }
	 
	 
     last_object=&(pDlg->camerdlg);
	 pDlg->m_Tansformer.SetPort(OPEN_PORT_2);
	 pDlg->m_FrameDisplayer.m_Rect=& (pDlg->camerdlg.m_ShowArea_rect);
	 pDlg->m_FrameDisplayer.m_hDC=pDlg->camerdlg.GetDC()->m_hDC;
	 


}

void OnBaseFrame(CHproDlg* pDlg)
{


	//first check monitoring not started

    if((pDlg->monitordlg.Is_Monitored))
	   {
		   AfxMessageBox("When Monitoring started ,you can't open this form .Close monitoring and try agine.");
		   pDlg->y[2].ToDown();
		   return;
           
	   }

	if(pDlg->baseframedlg.m_hWnd==0)
	{
      (pDlg->baseframedlg).Create(IDD_BASE_FRAME,pDlg);
      (pDlg->baseframedlg).SetWindowPos(NULL,185,80,599,374-10,SWP_SHOWWINDOW);
	   
	}
	else
    (pDlg->baseframedlg).SetWindowPos(NULL,185,80,599,374-10,SWP_SHOWWINDOW);

	if(last_object!=NULL)
	 {
		 last_object->ShowWindow(0);
	 }

	last_object=&(pDlg->baseframedlg);
	pDlg->m_Tansformer.SetPort(OPEN_PORT_3);
	pDlg->baseframedlg.ComputeDisplayRect();
    pDlg->m_FrameDisplayer.m_Rect=& (pDlg->baseframedlg.m_ShowArea_rect);
	pDlg->m_FrameDisplayer.m_hDC=pDlg->baseframedlg.GetDC()->m_hDC;
	
	
	
	



}




void OnMontoring(CHproDlg* pDlg)
{
if(pDlg->monitordlg.m_hWnd==0)
	{
      (pDlg->monitordlg).Create(IDD_MONITORING,pDlg);
      (pDlg->monitordlg).SetWindowPos(NULL,185,80,599,374-10,SWP_SHOWWINDOW);
	}
	else
    (pDlg->monitordlg).SetWindowPos(NULL,185,80,599,374-10,SWP_SHOWWINDOW);

	if(last_object!=NULL)
	 {
		 last_object->ShowWindow(0);
	 }

	last_object=&(pDlg->monitordlg);
	
	if(pDlg->monitordlg.Is_Monitored)
	{
		pDlg->monitordlg.StartMonitoring();
	}
	 
	

}





void OnUserAccount(CHproDlg* pDlg)

{
	if( pDlg->m_cuurent_user->Is_Admin)
	{
		CAdminAccount Admin_accouint;
		Admin_accouint.us_file.m_parent=pDlg;
		Admin_accouint.DoModal();
		return;

	}

	CUser_account user_accountdlg;
	user_accountdlg.us_file.m_parent=pDlg;
	user_accountdlg.m_user.SetUsername(pDlg->m_cuurent_user->GetUsername());
	user_accountdlg.m_user.SetUserpassword(pDlg->m_cuurent_user->GetUserpassword());
	user_accountdlg.m_user.Is_Admin=pDlg->m_cuurent_user->Is_Admin;
    user_accountdlg.m_user_tochanged=pDlg->m_cuurent_user->GetUsername();

	user_accountdlg.DoModal();


}

void OnSystemSetting(CHproDlg* pDlg)
{
CSytem_settingDlg sys_settingdlg;
sys_settingdlg.m_SysSetting=&(pDlg->m_Syssetting);

sys_settingdlg.DoModal();


}

void OnReco(CHproDlg* pdlg)
{
	

//	capFileSetCaptureFile(pdlg->m_CMU->hCapWnd ,"c:\\1.avi"); 
    //capFileAlloc(pdlg->m_CMU->hCapWnd ,(1024L * 1024L )*20);




capCaptureSequence(pdlg->m_CMU->hCapWnd);

	



	
	
}

void OnOpenHelp(CHproDlg*)
{


}

void OnAbout(CHproDlg*)
{
CAbout aboutdlg;
aboutdlg.DoModal();


}


void OnExit(CHproDlg* PDlg)
{
	if(::MessageBox(PDlg->m_hWnd,"Are you sure you want to exit program?","Exit",MB_YESNO|MB_ICONQUESTION)!=7/*No*/)

{
	
	    if(PDlg->m_CMU->Is_Connected)
		{
	       if(PDlg->m_CMU->m_Next_AFrame.hDib!=NULL)
	{
    	::DrawDibEnd(PDlg->m_CMU->m_Next_AFrame.hDib);
	    ::DrawDibClose(PDlg->m_CMU->m_Next_AFrame.hDib);
	}
			PDlg->m_CMU->DestroyCurrentCaptureWindow();		 //close camera first
		}

		
            time_t t=CTime::GetCurrentTime().GetTime();
			Tologfile("User :"+ PDlg->m_cuurent_user->GetUsername() +
				"  loged out  At time :" + ctime(&t));
		ExitProcess(0);      //exit program     

	
}
}

BOOL CHproDlg::OnEraseBkgnd(CDC* pDC) 
{
	
// Set brush to desired background color
      
	  CBitmap b_bmp;
	   b_bmp.LoadBitmap(IDB_B);
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




void CHproDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	
}

void CHproDlg::OnOK() 
{
	
}

void CHproDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	OnExit(this);
	

	
	CDialog::OnClose();
}
