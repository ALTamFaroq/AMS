// FrameDisplayer.cpp: implementation of the FrameDisplayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "FrameDisplayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FrameDisplayer::FrameDisplayer()
{

}

FrameDisplayer::~FrameDisplayer()
{

}

void FrameDisplayer::DisplayAFrame(AMS_AFrame * m_AFrame)
{
	/*if(m_Rect->Height()==NULL)
		return;*/
		::DrawDibDraw(m_AFrame->hDib,
		          m_hDC,
				  m_Rect->left,
	              m_Rect->top,
			      m_Rect->Width(),
			      m_Rect->Height(),
				  &(m_AFrame->AF_Bmpinfo.bmiHeader),			 // bmp header info
    			  m_AFrame->AF_Data,
				  0,
				  0,
				  m_AFrame->AF_Bmpinfo.bmiHeader.biWidth,
				  m_AFrame->AF_Bmpinfo.bmiHeader.biHeight,
				  DDF_SAME_DRAW			 // use prev params....
				  );

	::DrawDibDraw(m_AFrame->hDib,
		          m_DC.m_hDC,
				  0,
	              0,
			      128,
			      96,
				  &(m_AFrame->AF_Bmpinfo.bmiHeader),			 // bmp header info
    			  m_AFrame->AF_Data,
				  0,
				  0,
				  m_AFrame->AF_Bmpinfo.bmiHeader.biWidth,
				  m_AFrame->AF_Bmpinfo.bmiHeader.biHeight,
				  DDF_SAME_DRAW			 // use prev params....
				  );

	
BitBlt(m_DC_1.m_hDC,0,0,128,96,m_DC.m_hDC,0,0,SRCCOPY);
m_hNewBMP=(HBITMAP)::SelectObject(m_DC_1.m_hDC,m_hOldBMP);//get the bitmap handle




	



}



void FrameDisplayer::Create_AFrameDC(AMS_AFrame * m_AFrame)
{

m_DC.CreateCompatibleDC(0);
m_DC_1.CreateCompatibleDC(0);
HBITMAP h_Bmp=NULL;
HBITMAP h_Bmp_1=NULL;
h_Bmp=CreateCompatibleBitmap(m_hDC,m_AFrame->AF_Bmpinfo.bmiHeader.biWidth,m_AFrame->AF_Bmpinfo.bmiHeader.biHeight);
h_Bmp_1=CreateCompatibleBitmap(m_hDC,m_AFrame->AF_Bmpinfo.bmiHeader.biWidth,m_AFrame->AF_Bmpinfo.bmiHeader.biHeight);
 m_hOldBMP=CreateCompatibleBitmap(m_hDC,128,96);
 m_hNewBMP=CreateCompatibleBitmap(m_hDC,128,96);

if(h_Bmp==NULL)

{
	AfxMessageBox("For system developer \nInternal error in Function :FrameDisplayer::Create_AFrameDC h_Bmp=NULL",MB_ICONSTOP);
	ExitProcess(0);

}

::SelectObject(m_DC.m_hDC,h_Bmp);
::SelectObject(m_DC_1.m_hDC,h_Bmp_1);


}

void FrameDisplayer::DisplayBaseFrame(HDC src_hDC, CRect *m_rect_Base)
{
	StretchBlt(m_hDC,
		    m_rect_Base->left
		   ,m_rect_Base->top
		   ,m_rect_Base->Width()
		   ,m_rect_Base->Height()
		   ,src_hDC,
		   0,0,128,96,
		   SRCCOPY);

}
