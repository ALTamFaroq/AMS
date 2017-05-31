// LogonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "LogonDlg.h"
#include "hprodlg.h"
#include "logfile.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LogonDlg dialog


LogonDlg::LogonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LogonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(LogonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void LogonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LogonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LogonDlg, CDialog)
	//{{AFX_MSG_MAP(LogonDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_LOGON_FROM_FILE, OnLogonFromFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LogonDlg message handlers

void LogonDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
		CBitmap b_bmp;
	    b_bmp.LoadBitmap(IDB_DIALOG);
		CDC b_DC;
		b_DC.CreateCompatibleDC(0);
		b_DC.SelectObject(&b_bmp);
		
		CRect rect;
		GetClientRect(&rect);
		int w=rect.Width();
        int h = rect.Height();
        StretchBlt(GetDC()->m_hDC,0,0,w,h,b_DC.m_hDC,0,0,w,h,SRCCOPY);
}



void LogonDlg::OnCancel() 
{     
	
              	ExitProcess(0);

}

void LogonDlg::OnOK() 
{
	OnOk();
	

}
void LogonDlg::OnOk() 
{
	  CString u_name,u_pass,u_pass_confirm;
      GetDlgItemText(IDC_E_NAME,u_name);
      GetDlgItemText(IDC_E_PASS,u_pass);
	  

	  
	if(!u_name.IsEmpty())
 {
		if(!u_pass.IsEmpty()) 
	 {
		if(us_file.Is_U_Member(u_name,u_pass)) 
		{time_t t=CTime::GetCurrentTime().GetTime();
			Tologfile("User :"+((CHproDlg*)(us_file.m_parent))->m_cuurent_user->GetUsername() +
				"  loged in  At time :" + ctime(&t));
			CDialog::OnOK();	
            
		}
	 }
	 else
	 {
		 AfxMessageBox("You must fill user password");
		 
	 }
 }
 else
 {
	 AfxMessageBox("You must fill user name");
	 
 }
	
	

	


}





void LogonDlg::OnLogonFromFile() 
{
	// load from file
   
	AfxMessageBox("When floppy disk ready prees Ok");
	User m_tempUserr;
	if(!m_tempUserr.LoadFromFile("a:\\AMSUser.amsback"))
	{
       AfxMessageBox("An error occure user account not loaded");
	   return;
	}
	SetDlgItemText(IDC_E_NAME,m_tempUserr.GetUsername());
	SetDlgItemText(IDC_E_PASS,m_tempUserr.GetUserpassword());
	OnOk();



	
}
