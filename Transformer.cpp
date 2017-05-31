// Transformer.cpp: implementation of the Transformer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "Transformer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "HproDlg.h"

Transformer::Transformer()
{
Opened_Port=OPEN_PORT_0;
m_FrDisplayer=NULL;
w=h=0;

d=::GetDC(0);
is_alert=false;

}

Transformer::~Transformer()
{
//	delete [] Graed_Data;

}

void Transformer::SetPort(short shPort)
{
 Opened_Port=shPort;

}



void Transformer::Transfer(AMS_AFrame * m_Next_AFrame)
{
   
	switch(Opened_Port)
	{
	case OPEN_PORT_0:   //do nothing camera disconnected
		
		 OnReco((CHproDlg*)m_paren);
		 Opened_Port=OPEN_PORT_2;
		break;
    case OPEN_PORT_2:  //Transfer the AFrame to the Frame displayer
         
         
		 m_FrDisplayer->DisplayAFrame(m_Next_AFrame);
		 
		break;
    case OPEN_PORT_3:  
		 m_FrDisplayer->DisplayAFrame(m_Next_AFrame);
		 GetColorRefArray(m_FrDisplayer->m_hNewBMP);
		 ToBlurFilter(m_Next_AFrame);
         m_base_cls.SetBase(Graed_Filtered_Data_);
		 Opened_Port=OPEN_PORT_2;
		 
		 

		 


			      // Transfer the AFrame to the Frame Displayer &
		               //1- Convert The AFrame to TFrame
		               //2- Transfer the TFrame to the Base Recorder
		
		break;
    case OPEN_PORT_6:  //Transfer the AFrame to the Frame Displayer &
		               //Transfer the AFrame to the Frame Fragmentary
	     m_FrDisplayer->DisplayAFrame(m_Next_AFrame);
		 GetColorRefArray(m_FrDisplayer->m_hNewBMP);
		 ToBlurFilter(m_Next_AFrame);
		 if(m_base_cls.Is_Base_Created)
		 {
			 //showbase frame
			 m_FrDisplayer->DisplayBaseFrame(m_base_cls.m_hBaseDC,m_base_rect);


		 }
         m_hist.ComputeHistogram(Graed_Filtered_Data_);
		 m_hist.DisplayHistogram(m_FrDisplayer->m_hDC,m_Histogram_rect);
         m_Frame_Frag.m_base_acquire=&m_base_cls;
		 m_Frame_Frag.m_parent=m_paren;
		 m_Frame_Frag.m_user=((CHproDlg*)m_paren)->m_cuurent_user;
		 
		 if(m_Frame_Frag.Threshold==0)
		 {
		 m_Frame_Frag.CreateDC_BMP();
		 m_Frame_Frag.GetAdaptiveThresholdValue((m_Frame_Frag.m_base_acquire->m_arr_color_Base_Frame));
		 }
		 m_Frame_Frag.Fragment(Graed_Filtered_Data_);
		 

		break;

	}

}

void Transformer::GetColorRefArray(HBITMAP hBitmap)
{




   BITMAP bm;                   // bitmap structure
   BITMAPINFOHEADER bi;         // bitmap header
   BITMAPINFOHEADER *lpbi;  // pointer to BITMAPINFOHEADER
   DWORD dwLen;                 // size of memory block
   HANDLE hDIB, h;              // handle to DIB, temp handle
   HDC hDC;                     // handle to DC
   WORD biBits;                 // bits per pixel

   /* check if bitmap handle is valid */

   if (!hBitmap)
      return ;

   /* fill in BITMAP structure, return NULL if it didn't work */
   if (!GetObject(hBitmap, sizeof(bm), (LPSTR)&bm))
      return ;

   
  
     

   /* calculate bits per pixel */
   biBits = bm.bmPlanes * bm.bmBitsPixel;

   /* make sure bits per pixel is valid */
   if (biBits <= 1)
      biBits = 1;
   else if (biBits <= 4)
      biBits = 4;
   else if (biBits <= 8)
      biBits = 8;
   else /* if greater than 8-bit, force to 24-bit */
      biBits = 24;

   /* initialize BITMAPINFOHEADER */
   bi.biSize = sizeof(BITMAPINFOHEADER);
   bi.biWidth = bm.bmWidth;
   bi.biHeight = bm.bmHeight;
   bi.biPlanes = 1;
   bi.biBitCount = biBits;
   bi.biCompression = BI_RGB;
   bi.biSizeImage = 0;
   bi.biXPelsPerMeter = 0;
   bi.biYPelsPerMeter = 0;
   bi.biClrUsed = 0;
   bi.biClrImportant = 0;

   /* calculate size of memory block required to store BITMAPINFO */
   dwLen = bi.biSize; //+ PaletteSize((LPSTR)&bi);

   /* get a DC */
   hDC = ::GetDC(NULL);

   

   /* alloc memory block to store our bitmap */
   hDIB = GlobalAlloc(GHND, dwLen);

   /* if we couldn't get memory block */
   if (!hDIB)
   {
      /* clean up and return NULL */
      
      ::ReleaseDC(NULL, hDC);
      return ;
   }

   /* lock memory and get pointer to it */
   lpbi = (BITMAPINFOHEADER *)(VOID *)GlobalLock(hDIB);

   /* use our bitmap info. to fill BITMAPINFOHEADER */
   *lpbi = bi;

   /*  call GetDIBits with a NULL lpBits param, so it will calculate the
    *  biSizeImage field for us
    */
   GetDIBits(hDC, hBitmap, 0, (WORD)bi.biHeight, NULL, (LPBITMAPINFO)lpbi,
         DIB_RGB_COLORS);

   /* get the info. returned by GetDIBits and unlock memory block */
   bi = *lpbi;
   GlobalUnlock(hDIB);

   /* if the driver did not fill in the biSizeImage field, make one up */
   if (bi.biSizeImage == 0 )
      bi.biSizeImage = ((((bi.biWidth * bi.biBitCount) + 31) & ~31) >> 3) * bi.biHeight ;

   /* realloc the buffer big enough to hold all the bits */
   dwLen = bi.biSize  + bi.biSizeImage;
   if (h = GlobalReAlloc(hDIB, dwLen, 0))
      hDIB = h;
   else
   {
      /* clean up and return NULL */
      GlobalFree(hDIB);
      hDIB = NULL;
      
      ::ReleaseDC(NULL, hDC);
      return ;
   }

   /* lock memory block and get pointer to it */
   lpbi = (BITMAPINFOHEADER *)(VOID *)GlobalLock(hDIB);
   byte data[36864];

   /*  call GetDIBits with a NON-NULL lpBits param, and actualy get the
    *  bits this time
    */
 
   if (GetDIBits(hDC, hBitmap, 0, (WORD)bi.biHeight, /*(LPSTR)lpbi + (WORD)lpbi->biSize*/data , (LPBITMAPINFO)lpbi,DIB_RGB_COLORS) == 0)
   {
      /* clean up and return NULL */
      GlobalUnlock(hDIB);
      hDIB = NULL;      
      ::ReleaseDC(NULL, hDC);
      return ;
   }
   
   
 
   byte * rgb=data;
	   
   //HDC ff= ::GetDC(0);
//   int g;
   for(int i=96; i>0;i--)
	   for(int j=0;j<128;j++)
	   {
	    Graed_Data[j][i]=RGB(*(rgb+2),* (rgb+1),*rgb);
		rgb+=3; 
		/* g=(GetRValue(Graed_Data[j][i])+GetGValue(Graed_Data[j][i])+GetBValue(Graed_Data[j][i]))/3;
       Graed_Data[j][i]=RGB(g,g,g);*/
	   }



if(is_alert)
{
if(CFile::GetStatus("e:\\12.dib",sts))
{
  m_f.Open("e:\\12.dib",CFile::modeWrite);
  fl=m_f.GetLength();
  m_f.Seek(fl,0);
  m_f.Write(data,36864);
  m_f.Close();
}
else
{
  m_f.Open("e:\\12.dib",CFile::modeCreate|CFile::modeWrite);
  m_f.Write(data,36864);
  m_f.Close();
}
   
}


/* clean up */
   GlobalUnlock(hDIB);
   ::ReleaseDC(NULL, hDC);
   GlobalFree(hDIB);

   /* return handle to the DIB */
   



 
}

void Transformer::ToBlurFilter(AMS_AFrame * m_AFrame)
{
 /*gussian filter*/
 const int gauss_width =3 ;
  int sumr=0,sumg=0,sumb=0,i,j,k,r,g,b;
	  COLORREF c1;
  byte C_gray;
int gauss_fact[gauss_width]={1,2,1};
int gauss_sum=4;
  for(i=0;i<128;i++)
  {
      for(j=0;j<96;j++)
	  {
       sumr=0;
       sumg=0;
       sumb=0;
      for(k=0;k<gauss_width;k++)
	  {
     

     c1=Graed_Data[i-((gauss_width-1)>>1)+k][j];
     r=GetRValue(c1);
	 g=GetGValue(c1);
	 b=GetBValue(c1);
     sumr+=r*gauss_fact[k];
     sumg+=g*gauss_fact[k];
     sumb+=b*gauss_fact[k];

      }

          Graed_Data[i][j]=RGB(sumr/gauss_sum,sumg/gauss_sum,sumb/gauss_sum);
		  
	  }

}

for(i=0;i<128;i++)
{
 for(j=0;j<96;j++)
 {	
  sumr=0;
  sumg=0;
  sumb=0;
for(k=0;k<gauss_width;k++)
{
	 c1=Graed_Data[i][j-((gauss_width-1)>>1)+k];
     r=GetRValue(c1);
	 g=GetGValue(c1);
	 b=GetBValue(c1);
     sumr+=r*gauss_fact[k];
     sumg+=g*gauss_fact[k];
     sumb+=b*gauss_fact[k];
}
sumr/=gauss_sum;
sumg/=gauss_sum;
sumb/=gauss_sum;

C_gray=(sumr+sumg+sumb)/3; //to gray
Graed_Filtered_Data_[i][j]=RGB(C_gray,C_gray,C_gray);

	 
        }
}

//StretchBlt(d,0,0,180,150,m_FrDisplayer->m_DC.m_hDC,0,0,128,96,SRCCOPY);

  /*end guss*/


}
