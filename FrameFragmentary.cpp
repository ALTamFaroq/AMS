// FrameFragmentary.cpp: implementation of the FrameFragmentary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "FrameFragmentary.h"
#include "logfile.h"
#include <math.h>
#include "hprodlg.h"


#pragma comment (lib,"winmm.lib")

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FrameFragmentary::FrameFragmentary()
{

	Threshold=0;
	m_Snd_Thraed=0;
	Is_threads_suspendes=false;
	is_on=false;


		
}

FrameFragmentary::~FrameFragmentary()
{

}

void FrameFragmentary::Fragment(COLORREF frame[][96])
{
int X,Y,r,c;
if(is_on) 
{

return;
}

for(int Seg=0;Seg<48;Seg++)
{
 X=Y=r=c=0;
 X=(Seg-((Seg /8)*8))*16;
 Y=16*(Seg/8);


  for(int y=X;y<X+16;y++)
  {
	  for(int x=Y;x<Y+16;x++)
	  {
		  m_arr_byte_Segment[Seg][r][c]=frame[y][x];
          c+=1;
		   
	  }
	  c=0;
	  r+=1;

	 
  }

  
  //WBQuantization
  
 
  //get base i segment
  m_base_acquire->GetSegment(Seg,m_Base_Segment);
  //call the WBQuntization function
  WBQuntization(Threshold,m_arr_byte_Segment[Seg],m_Base_Segment);

} 




//draw



for( Seg=0;Seg<48;Seg++)
{

 X=Y=r=c=0;
 X=(Seg-((Seg /8)*8))*16;
 Y=16*(Seg/8);


  for(int y=X;y<X+16;y++)
  {
	  for(int x=Y;x<Y+16;x++)
	  {
		  
          c+=1;
		 
		  m_hdc.SetPixel(y,x,m_arr_byte_Segment[Seg][r][c]);
		   
	  }
	  c=0;
	  r+=1;

	 
  }
}


  //display the WBFrame
DisplayWBFrame();
}

int  FrameFragmentary::GetAdaptiveThresholdValue(COLORREF segment[][96])
{
 
	

	//reset the histogram values
	memset(m_Segment_Histogram,0,256);
   //compute the segment histogram  
	
	for(int i=0;i<128;i++)
	{
		for(int j=0;j<96;j++)
		{
        m_Segment_Histogram[GetRValue(segment[i][j])]++; //R=G=B 

		}
	}

	//get the adaptive threshold value using Tringular method

	//get Max and Min values and them indexes
	
       Miny=Maxy=m_Segment_Histogram[0];
	   Maxx=Minx=0;
	   
	 for(i=1;i<256;i++)
	 {    //Maxy
		 if(m_Segment_Histogram[i]<Miny)
		 {
			 Miny=m_Segment_Histogram[i];
			 Minx=i;

		 }
		 else
			 //Miny
		 {
		 if(m_Segment_Histogram[i]>Maxy)
		 {
			 Maxy=m_Segment_Histogram[i];
			 Maxx=i;

		 }
		 }
		 
		  }
	 if (Maxx<Minx)
	 {
		 //swap 
		 float temp;
		 temp=Maxx;
		 Maxx=Minx;
		 Minx=temp;

	 }

	 //compute the straight line EQ.
	 m=(Miny-Maxy)/(Minx-Maxx); //slop m
	 Threshold=Maxx;
	 Maxy=m*(Threshold-Minx)+Miny;
	 Miny=m_Segment_Histogram[Threshold];
	 Newx=(Maxy-Miny)/m +(Minx);
	 D_Threshold=sqrt((Threshold-Newx)*(Threshold-Newx)+ (Maxy-Miny)*(Maxy-Miny));
    
	 //find the adaptive threshold value

	 for(i=Maxx-1;i>Minx;i--)
	 {
	 Maxy=m*(i-Minx)+Miny;
	 Miny=m_Segment_Histogram[i];
	 Newx=(Maxy-Miny)/m +(Minx);
     D_Threshold_1=sqrt((i-Newx)*(i-Newx)+ (Maxy-Miny)*(Maxy-Miny));
	 
	 if(D_Threshold_1>D_Threshold)
	 {
         Threshold=i;
		 D_Threshold=D_Threshold_1;
	 }

	 }

	 
         
     
return Threshold;		  

}

void FrameFragmentary::WBQuntization(int Threshold_Value, COLORREF AF_segment[][16],COLORREF Base_Segment [][16])
{

  COLORREF c1,c2;
  int h,h1,k,W_number;
  W_number=0;

	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
		{
         c1=AF_segment[i][j]; //segment i
		 c2=Base_Segment[i][j]; //base segment i
         h=GetRValue(c2);
		 h1=GetRValue(c1);
		 k=sqrt(((h-h1)*(h-h1))+((h-h1)*(h-h1))+((h-h1)*(h-h1)));
		 if (k>=Threshold_Value)
		 {
			 //make pexils white
			  AF_segment[i][j]=RGB(255,255,255);
			  W_number++;
			 
		 }
		 else
		 {
			 //black
			 AF_segment[i][j]=RGB(0,0,0);
		 }
		}

	 	if(W_number>5)
		{
			
		
			
			

			   
			   
		
			
		   if(m_Snd_Thraed==NULL )
		   {
			   
			   m_Snd_Thraed=(CWinThread*)AfxBeginThread(Start_ALert,NULL,THREAD_PRIORITY_TIME_CRITICAL);
			   m_Stop_Thraed=(CWinThread*)AfxBeginThread(Stop_ALert,this,THREAD_PRIORITY_TIME_CRITICAL);
			   
               

			   //add data to the log file 
			   // alert start 
			   time_t t=CTime::GetCurrentTime().GetTime();
			    Tologfile("Alert Start on User :"+m_user->GetUsername() +
				"  session    At time :" + ctime(&t));

			   
			 
		   }
		   else
		   
		  if(Is_threads_suspendes)
		  {
		  Is_threads_suspendes=false;
	      m_Snd_Thraed->ResumeThread();
		  time_t t=CTime::GetCurrentTime().GetTime();
			    Tologfile("Alert Start on User :"+ m_user->GetUsername() +"  session    At time :" + ctime(&t));

		  m_Stop_Thraed=(CWinThread*)AfxBeginThread(Stop_ALert,this,THREAD_PRIORITY_TIME_CRITICAL);
		  
		  		  
		   }
		
		
			

		}

}


UINT Start_ALert(LPVOID pParam)
{

    for(;;)
    {
		PlaySound((char *)IDR_NOTFY,NULL,SND_LOOP|SND_SYNC|SND_RESOURCE);
	}
return 0;

}

UINT Stop_ALert(LPVOID pParam)
{

    
     ((CHproDlg*)((FrameFragmentary*)pParam)->m_parent)->m_Tansformer.is_alert=true;
	AfxMessageBox("press the follwing button toclose Alert !");
	((CHproDlg*)((FrameFragmentary*)pParam)->m_parent)->m_Tansformer.is_alert=false;
    
    
	

	//add data to log file

	   time_t t=CTime::GetCurrentTime().GetTime();
	   Tologfile("Alert Stop By  User :"+ ((FrameFragmentary*)pParam)->m_user->GetUsername() +" At time  :" + ctime(&t));
	   //////////////////////////////////////////////////////
	 ((FrameFragmentary*)pParam)->Is_threads_suspendes=true;
	 ((FrameFragmentary*)pParam)->m_Snd_Thraed->SuspendThread();
	 
	 
	 

return 0;

}


void FrameFragmentary::DisplayWBFrame()
{

StretchBlt(m_parent_hDC,
		    m_filterd_rect->left
		   ,m_filterd_rect->top
		   ,m_filterd_rect->Width()
		   ,m_filterd_rect->Height()
		   ,m_hdc.m_hDC,
		   0,0,128,96,
		   SRCCOPY);


}

void FrameFragmentary::CreateDC_BMP()
{

	m_hdc.CreateCompatibleDC(m_parent->GetDC());
	m_bmp.CreateCompatibleBitmap(m_parent->GetDC(),128,96);
	m_hdc.SelectObject(&m_bmp);


}
