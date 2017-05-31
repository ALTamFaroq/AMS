// LogFilecls.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "logfile.h"
#include "LogFilecls.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogFilecls dialog
void ClearLogfile(CString m_str)
{
	CString  csFile_path;
	CFile m_file;
	CFileStatus status;
	CFileException ex;
  TCHAR windir[MAX_PATH];
		GetWindowsDirectory(windir,MAX_PATH);
	    csFile_path=windir;
		csFile_path+="\\tasks\\AMSLogFile.ams";

	
	if(CFile::GetStatus( csFile_path, status ))
	{
	 if(m_file.Open(csFile_path,CFile::modeWrite,&ex))
	 {
		 m_file.SetLength(0);
		 m_file.Write(m_str.GetBuffer(m_str.GetLength()),m_str.GetLength());
		 m_file.Close();
	 }
	  else
		{
			TCHAR szError[1024];
            ex.GetErrorMessage(szError, 1024);
	        AfxMessageBox(szError);
			
		}

	}
}


CLogFilecls::CLogFilecls(CWnd* pParent /*=NULL*/)
	: CDialog(CLogFilecls::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogFilecls)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLogFilecls::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogFilecls)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogFilecls, CDialog)
	//{{AFX_MSG_MAP(CLogFilecls)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogFilecls message handlers

void CLogFilecls::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();



}

void CLogFilecls::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();

}

void CLogFilecls::OnClear() 

{
      	
	    if(::MessageBox(m_hWnd,"Are you sure you want to Clear the log file data ? \n if you choose yes ,all data will be deleted and you can not restore it  . ","Log file",MB_YESNO|MB_ICONQUESTION)!=7/*No*/)

		{
     	    time_t t=CTime::GetCurrentTime().GetTime();		
	    	ClearLogfile("Log file was cleared by " + m_cu_user->GetUsername() + "   At time :    " + ctime(&t));
			CDialog::OnOK();

		}

}

BOOL CLogFilecls::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString m_logdata;
	Loadlogfile(m_logdata);
	SetDlgItemText(IDC_E_Log,m_logdata);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CLogFilecls::OnEraseBkgnd(CDC* pDC) 
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
