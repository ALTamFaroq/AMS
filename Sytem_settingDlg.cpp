// Sytem_settingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "Sytem_settingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSytem_settingDlg dialog


CSytem_settingDlg::CSytem_settingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSytem_settingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSytem_settingDlg)
	m_Nedded_Size =0;
	//}}AFX_DATA_INIT
}


void CSytem_settingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSytem_settingDlg)
	
	
	DDX_Control(pDX, IDC_CMB_DRIVER, m_Cmb_Driver);
	DDX_Text(pDX, IDC_E_SIZE, m_Nedded_Size);
	DDV_MinMaxInt(pDX, m_Nedded_Size, 0, 50000);
	DDX_Control(pDX, IDC_ON_TOP, m_OnTop);
	DDX_Control(pDX, IDC_STARTUP, m_StartUp);
	DDX_Control(pDX, IDC_LANCH, m_Lanch);


	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSytem_settingDlg, CDialog)
	//{{AFX_MSG_MAP(CSytem_settingDlg)
	ON_CBN_SELCHANGE(IDC_CMB_DRIVER, OnSelchangeCmbDriver)
	ON_EN_CHANGE(IDC_E_SIZE, OnChangeESize)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSytem_settingDlg message handlers

void CSytem_settingDlg::ListDrivers()
{
char *dr;
int d=GetLogicalDriveStrings(0,dr);
dr=new char[d];
GetLogicalDriveStrings(d,dr);
CString csDriver="";
for(int i=0;i<d;i++)
{
 	
	if(dr[i]!='\0')
	{
		csDriver+=dr[i++];
		csDriver+=dr[i++];
	    csDriver+=dr[i];
		if(GetDriveType(csDriver)==DRIVE_FIXED) //Get only fixed disks
		{
			m_Cmb_Driver.AddString(csDriver);

		}
	    csDriver="";
	}


}

m_Cmb_Driver.SetCurSel(0);

//
m_Cmb_Driver.SetWindowText(csDriver);
OnSelchangeCmbDriver();

delete dr;
}

BOOL CSytem_settingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	LoadCurrentSetting();
	ListDrivers();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSytem_settingDlg::OnSelchangeCmbDriver() 
{
//compute the avialble space in the selected driver
	char cmbtext[3];
	m_Cmb_Driver.GetWindowText(cmbtext,10);
	unsigned long SectorsPerCluster=0	 ,BytesPerSector=0 ,NumberOfFreeClusters=0,TotalNumberOfClusters=0 ;
   	FreeBytes=0;



	if(GetDiskFreeSpace(cmbtext,
		&SectorsPerCluster
		,&BytesPerSector
		,&NumberOfFreeClusters
		,&TotalNumberOfClusters))
		
	{
		 FreeBytes=(SectorsPerCluster*BytesPerSector);
			 FreeBytes*=NumberOfFreeClusters;
		 FreeBytes/=(1024*1024);
        char csFree[100];
		wsprintf(csFree,"Free space :%d MBytes",FreeBytes);
				;


	     SetDlgItemText(IDC_S_AVALIBLE_SPACE,csFree);
	}

 
OnChangeESize();	
	
}

void CSytem_settingDlg::OnChangeESize() 
{
    
	 m_Nedded_Size=GetDlgItemInt(IDC_E_SIZE);
	 if(m_Nedded_Size>FreeBytes)
	 {
		 AfxMessageBox("Needed size must be <= Disk free space");
	    ::SetFocus((HWND)GetDlgItem(IDC_E_SIZE));
	 }
	 if(m_Nedded_Size==0)
	 {
		 AfxMessageBox("Cant accept this value");
	    ::SetFocus((HWND)GetDlgItem(IDC_E_SIZE));
	 }
	
}



bool CSytem_settingDlg::LoadCurrentSetting()
{
  
	

	m_OnTop.SetCheck(m_SysSetting->Is_onTop);
	m_Lanch.SetCheck(m_SysSetting->Is_load_on_fauiler);
	m_StartUp.SetCheck(m_SysSetting->Is_Auto_StartUp);
	SetDlgItemInt(IDC_E_SIZE,m_SysSetting->m_NeededSize);
	m_Cmb_Driver.SetCurSel(0);


	
     
		



return true;
}

void CSytem_settingDlg::StoreCurrentSetting()
{
m_SysSetting->Is_onTop=m_OnTop.GetCheck();
m_SysSetting->Is_Auto_StartUp=m_StartUp.GetCheck();
m_SysSetting->Is_load_on_fauiler=m_Lanch.GetCheck();
m_SysSetting->m_NeededSize=(int)GetDlgItemInt(IDC_E_SIZE);
m_Cmb_Driver.GetWindowText(m_SysSetting->m_RecordingPath);
m_SysSetting->Store("AMSSystemsetting.ams");




}

void CSytem_settingDlg::OnOK() 
{
	
	StoreCurrentSetting();
	CDialog::OnOK();
	
}

BOOL CSytem_settingDlg::OnEraseBkgnd(CDC* pDC) 
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
