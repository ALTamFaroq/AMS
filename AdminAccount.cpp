// AdminAccount.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "AdminAccount.h"
#include "LogFilecls.h"


#include "hprodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdminAccount dialog


CAdminAccount::CAdminAccount(CWnd* pParent /*=NULL*/)
	: CDialog(CAdminAccount::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdminAccount)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAdminAccount::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdminAccount)
	
	DDX_Control(pDX, IDC_CMB_USERS, m_Cmb_Users);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdminAccount, CDialog)
	//{{AFX_MSG_MAP(CAdminAccount)
	ON_BN_CLICKED(IDC_CHANGEUSERACCOUNT, OnChangeuseraccount)
	ON_BN_CLICKED(IDC_ADDNEWUSER, OnAddnewuser)
	ON_BN_CLICKED(IDC_DELETE_USER, OnDeleteUser)
	ON_BN_CLICKED(IDC_VIEW_LOG, OnViewLog)
	ON_BN_CLICKED(IDC_BACKUP, OnBackup)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdminAccount message handlers

void CAdminAccount::OnOK() 
{
	// TODO: Add extra validation here
	
CDialog::OnCancel();
}

void CAdminAccount::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CAdminAccount::OnChangeuseraccount() 
{
CString  cs;
m_Cmb_Users.GetWindowText(cs);

	CUser_account cu;

	cu.m_user_tochanged=cs;
	cu.m_user.SetUsername(cs);
	cu.us_file.m_parent=us_file.m_parent;
	cu.us_file.SetUser(cu.m_user);
    cu.DoModal();
	if(!(((CHproDlg*)us_file.m_parent)->m_cuurent_user->Is_Admin))
	{
		CDialog::OnOK();
		return;
	}
	    
	RefreshUsersLiset();
	
}

void CAdminAccount::OnAddnewuser() 
{
	
	CUser_account cu;
	cu.us_file.m_parent=us_file.m_parent;
	cu.DoModal();
	RefreshUsersLiset();
	
}

BOOL CAdminAccount::OnInitDialog() 
{
	CDialog::OnInitDialog();

    //load all users;
	RefreshUsersLiset();

	
	


	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CAdminAccount::OnDeleteUser() 
{
    if(::MessageBox(m_hWnd,"Are you sure you want to remove this account?","Exit",MB_YESNO|MB_ICONQUESTION)!=7/*No*/)
	{
		CString m_user_name;
	    m_Cmb_Users.GetWindowText(m_user_name);
		if(us_file.DeleteUser(m_user_name))
         RefreshUsersLiset();		
	}

}

void CAdminAccount::RefreshUsersLiset()
{

	//clear 
   //for(int j=0;j<m_Cmb_Users.GetCount();j++)
	   m_Cmb_Users.ResetContent();


User** u=(User**)(((CHproDlg*)us_file.m_parent)->Users_Array.GetData());
		for(int i=0;i<((CHproDlg*)us_file.m_parent)->Users_Array.GetSize();i++)
		{
			m_Cmb_Users.AddString(u[i]->GetUsername());
		}
		m_Cmb_Users.SetCurSel(0);
}

void CAdminAccount::OnViewLog() 
{
	//show log file data
	CLogFilecls logdlg;
	logdlg.m_cu_user=((CHproDlg*)us_file.m_parent)->m_cuurent_user;
	logdlg.DoModal();
	
}

void CAdminAccount::OnBackup() 
{
    User m_tempuser;
	CString m_username;
	m_Cmb_Users.GetWindowText(m_username);
	m_tempuser.SetUsername(m_username);
	us_file.SetUser(m_tempuser);
	AfxMessageBox("When floppy disk ready prees Ok");
      if(m_tempuser.StoreToFile("A:\\AMSUser.Amsback"))
	  { 
		  AfxMessageBox("Backup creation succed");
	  }	
}

BOOL CAdminAccount::OnEraseBkgnd(CDC* pDC) 
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
