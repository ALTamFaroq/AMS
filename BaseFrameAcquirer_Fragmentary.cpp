// BaseFrameAcquirer_Fragmentary.cpp: implementation of the BaseFrameAcquirer_Fragmentary class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "hpro.h"
#include "BaseFrameAcquirer_Fragmentary.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BaseFrameAcquirer_Fragmentary::BaseFrameAcquirer_Fragmentary()
{
Is_Base_Created=false;
m_hBaseDC=CreateCompatibleDC(0);
m_hBaseBmp=CreateCompatibleBitmap(::GetDC(0),128,96);

if(m_hBaseBmp==NULL)
{
	AfxMessageBox("Internal error in BaseFrameAcquirer_Fragmentary (m_hBaseBmp=NULL)");
	ExitProcess(0);

}
::SelectObject(m_hBaseDC,m_hBaseBmp);



}

BaseFrameAcquirer_Fragmentary::~BaseFrameAcquirer_Fragmentary()
{
//clean up GDI objects
	DeleteObject(m_hBaseBmp);
	::DeleteDC(m_hBaseDC);

}

void BaseFrameAcquirer_Fragmentary::SetBase(COLORREF base[128][96])
{

	for(int i=0;i<128;i++)
		for(int j=0;j<96;j++)
		{
			m_arr_color_Base_Frame[i][j]=base[i][j];
            SetPixel(m_hBaseDC,i,j,base[i][j]);

		}

		Is_Base_Created=true;
    /////////////
	FragmentBase();


}

void BaseFrameAcquirer_Fragmentary::FragmentBase()
{

int X,Y,r,c;
for(int Seg=0;Seg<48;Seg++)
{
 X=Y=r=c=0;
 X=(Seg-((Seg /8)*8))*16;
 Y=16*(Seg/8);


  for(int y=X;y<X+16;y++)
  {
	  for(int x=Y;x<Y+16;x++)
	  {
		  m_arr_byte_Segment[Seg][r][c]=m_arr_color_Base_Frame[y][x];
          c+=1;
		   
	  }
	  c=0;
	  r+=1;

  }
}
}
void BaseFrameAcquirer_Fragmentary::GetSegment(int Seg_Index, COLORREF Segment[][16])
{
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			Segment[i][j]=m_arr_byte_Segment[Seg_Index][i][j];
}
