// User_account.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "User_account.h"

#include "hproDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUser_account dialog


CUser_account::CUser_account(CWnd* pParent /*=NULL*/)
	: CDialog(CUser_account::IDD, pParent)
{
	is_first=false;
	m_user_tochanged="";
}


void CUser_account::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CMB_MEMBEROF, m_Cmb_MemberOf);
	
	//{{AFX_DATA_MAP(CUser_account)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUser_account, CDialog)
	//{{AFX_MSG_MAP(CUser_account)
	ON_BN_CLICKED(IDC_BACKUP, OnBackup)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUser_account message handlers

void CUser_account::OnOK() 
{
	// TODO: Add extra validation here
 
 CString m_csMember;
 int is_admin;
 is_admin=0;
	m_Cmb_MemberOf.GetWindowText(m_csMember);
 if(m_csMember=="Administrators")
 {
	 is_admin=1;
 }

CString u_name,u_pass,u_pass_confirm;
 GetDlgItemText(IDC_E_NAME,u_name);
 GetDlgItemText(IDC_E_PASS,u_pass);
 GetDlgItemText(IDC_E_PASS2,u_pass_confirm);
 if(!u_name.IsEmpty())
 {
	 if(!u_pass.IsEmpty())
	 {
		 if(u_pass==u_pass_confirm)
		 {
			 
			 //change user account

			 CString m_uName,m_uPass,m_Memberof;
			 GetDlgItemText(IDC_E_NAME,m_uName);
			if(!m_user_tochanged.IsEmpty())	 
			{
			    if( m_uName==m_user_tochanged)
				 { 

                   GetDlgItemText(IDC_E_NAME, m_uName);
				   m_user.SetUsername(m_uName);
		           GetDlgItemText(IDC_E_PASS,m_uPass);
				    m_user.SetUserpassword(m_uPass);
				    m_Cmb_MemberOf.GetWindowText(m_Memberof);
					 if(m_Memberof=="Administrators")
					 {
						 m_user.Is_Admin=1;
					 }
					 else
					 {
						 m_user.Is_Admin=0;
					 }
                      if(us_file.SetUserAccount(&m_user,m_user_tochanged))
					    CDialog::OnOK();
					  return;
				}
				else
				{

					 if(!us_file.Is_U_Member(m_uName) )
				 {
					 GetDlgItemText(IDC_E_NAME, m_uName);m_user.SetUsername(m_uName);
		             GetDlgItemText(IDC_E_PASS,m_uPass);m_user.SetUserpassword(m_uPass);
					 m_Cmb_MemberOf.GetWindowText(m_Memberof);
					 if(m_Memberof=="Administrators")
					 {
						 m_user.Is_Admin=1;
					 }
					 else
					 {m_user.Is_Admin=0;}
                      if(us_file.SetUserAccount(&m_user,m_user_tochanged))					  
					  CDialog::OnOK();
					  return;

                    
				 }
				 else
				 {
					 AfxMessageBox("This user name is registered for anthor user .");
					 return;
				 }
				 }
			 
			 
			}
			 
			 
			 
			 
			 if(us_file.AddUser(u_name,u_pass,is_admin))
			 {
				 
				 if(is_first)
				 {
					 us_file.Is_U_Member(u_name,u_pass);
					 is_first=false;
				 }
				 CDialog::OnOK();
				

			 }
		 }
		 else
		 {
			 AfxMessageBox("Confirmed password not equal");
			
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
	
	//CDialog::OnOK();
}

BOOL CUser_account::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Cmb_MemberOf.AddString("Administrators");
	m_Cmb_MemberOf.AddString("User");

	if(is_first)
	{
		m_Cmb_MemberOf.SetCurSel(0);
		m_Cmb_MemberOf.EnableWindow(0);
	}
	else

    
	{
		SetDlgItemText(IDC_E_NAME,m_user.GetUsername());
		SetDlgItemText(IDC_E_PASS,m_user.GetUserpassword());
		SetDlgItemText(IDC_E_PASS2,m_user.GetUserpassword());
		if(m_user.Is_Admin)
		{
            m_Cmb_MemberOf.SetCurSel(0);
			::ShowWindow(GetDlgItem(IDC_BACKUP)->m_hWnd,0);
		}
		else
			m_Cmb_MemberOf.SetCurSel(1);

		if(((CHproDlg*)us_file.m_parent)->m_cuurent_user-> Is_Admin!=1)
		{
			m_Cmb_MemberOf.EnableWindow(0);
			
		}

	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUser_account::OnBackup() 
{
	
	
	AfxMessageBox("When floppy disk ready prees Ok");
      if(((CHproDlg*)us_file.m_parent)->m_cuurent_user->StoreToFile("A:\\AMSUser.Amsback"))
	  { 
		  AfxMessageBox("Backup creation succed");
	  }
	  



	
}

BOOL CUser_account::OnEraseBkgnd(CDC* pDC) 
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
