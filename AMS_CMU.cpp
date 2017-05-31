// AMS_CMU.cpp: implementation of the AMS_CMU class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "AMS_CMU.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AMS_CMU::AMS_CMU()
{
Is_Connected=false;
}

AMS_CMU::~AMS_CMU()
{

}

bool AMS_CMU::SetVidoparam()
{
	CAPTUREPARMS  CapParms={0};	



	
	capCaptureGetSetup(hCapWnd,&CapParms,sizeof(CapParms));

	CapParms.fAbortLeftMouse = FALSE;
	CapParms.fAbortRightMouse = FALSE;
	CapParms.fYield = TRUE;
	CapParms.fCaptureAudio = FALSE;
	CapParms.wPercentDropForError = 1;
	//CapParms.vKeyAbort=0;

	if(capCaptureSetSetup(hCapWnd,&CapParms,sizeof(CapParms))==FALSE)
	{
	
	return FALSE;
	}

	// Get Video Format 
	capGetVideoFormat(hCapWnd,&(m_Next_AFrame.AF_Bmpinfo),sizeof(m_Next_AFrame.AF_Bmpinfo));
	 
	return true;
}

bool AMS_CMU::CreateNewCaptureWindow()
{
 
//To create new capture window 
	hCapWnd=capCreateCaptureWindow("CaptureWindow",WS_POPUP,0,0,1,1,0,0);

if (hCapWnd==NULL)
{
	//can't create window .an error occure
	return false;
}

capSetUserData(hCapWnd,this);
capSetCallbackOnVideoStream(hCapWnd,OnVideoReceived);
capSetCallbackOnError(hCapWnd,OnCameraError);


if(!capDriverConnect(hCapWnd,0))
{
	hCapWnd=NULL;
	return false;

}
 
if(SetVidoparam()==false)
{
	capDriverDisconnect(hCapWnd);
}

Is_Connected=true;
return true;


}

void AMS_CMU::DestroyCurrentCaptureWindow()
{
// to destroy current capture window
	
  
	if(hCapWnd==NULL)
		return;
	capCaptureStop(hCapWnd);
	capCaptureAbort(hCapWnd);
	



	capSetCallbackOnVideoStream(hCapWnd,NULL);
	
    capSetCallbackOnError(hCapWnd,NULL);

     capDriverDisconnect(hCapWnd);
	DestroyWindow(hCapWnd);

   
		Sleep(10);
	
	
	
	

	
	hCapWnd=NULL;
	
	Is_Connected=false;
}




LRESULT CALLBACK OnVideoReceived(HWND h_CapWnd,LPVIDEOHDR lpVhdr)
{
	//to receive the data and the Video header
	//memcpy(lpVhdr->lpData,m_Next_AFrame->AF_Data,sizeof(*(m_Next_AFrame->AF_Data)));
	AMS_CMU *vidcap=(AMS_CMU *)capGetUserData(h_CapWnd);


    vidcap->m_Next_AFrame.AF_Data=lpVhdr->lpData;
	

   if(vidcap!=NULL )
   {

   ((Transformer*) (vidcap->m_parentCls))->Transfer(&(vidcap->m_Next_AFrame));
    
   }



	return (LRESULT)TRUE;
}




LRESULT CALLBACK OnCameraError(HWND h_CapWnd ,int ERR_ID,LPSTR ERR_Text)
{
//to handle the Camera errors
	if(ERR_ID==0)
	{
		AfxMessageBox("Make sure your camera is connected and instaled into you system correctely !");
		return true;
	}
	
	CString Err_str="Camera Error...\n";
	        Err_str=ERR_Text;
	AfxMessageBox(Err_str);
return true;
}




bool AMS_CMU::Camera_Connect()
{
	if(Is_Connected)
	{
		AfxMessageBox("Camera connected previously! ");
		return false;
	}
	// 1- Create new capture window 
	if(CreateNewCaptureWindow())
	{
		//2-Send CAMERA_CONNECTED command  the (CICU,IIU) in the (AMSCPU
		//3-Send 'date' , 'Camera connection established' and "Username" to the log file
		//4-Inform the user with the connection establishment.
		
		
		
		


	

	m_Next_AFrame.hDib=::DrawDibOpen();
	if(m_Next_AFrame.hDib!=NULL)
	{
	 
		::DrawDibBegin(m_Next_AFrame.hDib,
			::GetDC(0),
					   -1,				// don't stretch
					   -1,				// don't stretch
					   &(m_Next_AFrame.AF_Bmpinfo.bmiHeader),
					   m_Next_AFrame.AF_Bmpinfo.bmiHeader.biWidth,
					   m_Next_AFrame.AF_Bmpinfo.bmiHeader.biHeight,      // height of image
					   0				
					   );
    return true;
	}
	}
return false;
}


bool AMS_CMU::Start_Sequence_NoFile()
{
  if(capCaptureSequenceNoFile(hCapWnd)==FALSE)
		{
	
	       return FALSE;
		  
		}
		return true;


}





void AMS_CMU::Start_Sequence_ToFile(CString cspath,int MBneeded)
{



//DestroyCurrentCaptureWindow();


Camera_Connect();
capFileSetCaptureFile(hCapWnd ,"c:\\1.avi"); 
    capFileAlloc(hCapWnd ,(1024L * 1024L )*20);



capCaptureSequence(hCapWnd);

}




void AMS_CMU::Store_Stream_ToFile(CString cspath)
{

}

void AMS_CMU::SetParentCls(CObject * m_obParent)
{
m_parentCls=m_obParent;
}
