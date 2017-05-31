// HistogramDislpayer.cpp: implementation of the HistogramDislpayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "HistogramDislpayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HistogramDislpayer::HistogramDislpayer()
{

m_hDC.CreateCompatibleDC(0);
HBITMAP hbmp=CreateCompatibleBitmap(::GetDC(0),300,300);
::SelectObject(m_hDC.m_hDC,hbmp);
BitBlt(m_hDC.m_hDC,0,0,300,300,::GetDC(0),0,0,BLACKNESS);

HPEN pn;
pn=CreatePen(PS_SOLID,1,RGB(150,150,150));
::SelectObject(m_hDC.m_hDC,pn);





}

HistogramDislpayer::~HistogramDislpayer()
{

}

void HistogramDislpayer::ComputeHistogram(COLORREF data[][96])
{
	
	int r;
for(int i=0;i<128;i++)
{
	for(int j=0;j<96;j++)
    {
       
       r=GetRValue(data[i][j]); //data is graed then R=G=B 
	   m_HistogramData[r]++;

  }
}

}


void HistogramDislpayer::DisplayHistogram(HDC m_NhDC, CRect *m_Rect)
{

for( int i=0;i<256;i++)
{
    m_hDC.MoveTo(i+20,290);
	m_hDC.LineTo(i+20,290-m_HistogramData[i]);
	
}

StretchBlt(m_NhDC,m_Rect->left,m_Rect->top,m_Rect->Width(),m_Rect->Height(),m_hDC.m_hDC,0,0,300,300,SRCCOPY);
BitBlt(m_hDC.m_hDC,0,0,300,300,m_NhDC,0,0,BLACKNESS);
memset(m_HistogramData,0,256);
}
