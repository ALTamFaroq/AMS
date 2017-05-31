// NiceHyber.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "NiceHyber.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NiceHyber

NiceHyber::NiceHyber()
 
{
	w=h=top=bottom=0;
	Is_First_Drown=true;
	Is_Down=false;
	memset(&lf, 0, sizeof(LOGFONT));       // zero out structure
    lf.lfHeight = 26;   
	strcpy(lf.lfFaceName, "Monotype Corsiva");        // request a face name "Arial"
	lf.lfUnderline=false;
	//lf.lfWeight=FW_BOLD;
	VERIFY(font.CreateFontIndirect(&lf));
	Hyber_State=NORMAL;
	Normal_DC.CreateCompatibleDC(0);
	Move_DC.CreateCompatibleDC(0);
	Down_DC.CreateCompatibleDC(0);
    Last_Object=NULL; 
	m_hC=AfxGetApp()->LoadCursor(IDC_CR);
	

}

NiceHyber::~NiceHyber()
{
	
}


BEGIN_MESSAGE_MAP(NiceHyber, CStatic)
	//{{AFX_MSG_MAP(NiceHyber)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
HBRUSH NiceHyber::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	
	if (Is_First_Drown)
	{
      Is_First_Drown=false;
	  
	  pDC->SetTextColor(Normal_Color);
	  pDC->SetBkMode(TRANSPARENT);
	  pDC->SelectObject(&font);
	  pDC->GetClipBox(&h_rect);
	  w=h_rect.Width();
	  h=h_rect.Height();
	  top=h_rect.top;
	  bottom=h_rect.bottom;
      Normal_bmp.CreateCompatibleBitmap(pDC,w,h);
	  Move_bmp.CreateCompatibleBitmap(pDC,w,h);
	  Down_bmp.CreateCompatibleBitmap(pDC,w,h);

	  /* normal dc initilaiztion */
       Normal_DC.SelectObject(&Normal_bmp);
	   Normal_DC.BitBlt(0,0,w,h,pDC,0,0,SRCCOPY);
	   Normal_DC.SetBkMode(TRANSPARENT);
	   Normal_DC.SetTextColor(Normal_Color);
	   Normal_DC.SelectObject(&font);
       Normal_DC.DrawText(h_Name,-1,&h_rect,DT_VCENTER);

	  /* down dc initilaiztion */
	  Down_DC.SelectObject(&Down_bmp);
	  for(int i=0;i<w;i++)
		  for(int j=0;j<h;j++)
			  SetPixel(Down_DC.m_hDC,i,j,Down_BK_Color);
      Down_DC.SetBkMode(TRANSPARENT);
      Down_DC.SetTextColor(Down_Color);
	  Down_DC.SelectObject(&font);
	  Down_DC.DrawText(h_Name,h_Name.GetLength(),&h_rect,DT_VCENTER  );
      
	  

      /* move dc initilaiztion */
	  Move_DC.SelectObject(&Move_bmp);
	  Move_DC.BitBlt(0,0,w,h,pDC,0,0,SRCCOPY);
	  pDC->DrawText(h_Name,h_Name.GetLength(),&h_rect,DT_VCENTER);
	  Move_DC.SetBkMode(TRANSPARENT);
	  Move_DC.SetTextColor(Move_Color);
	  lf.lfUnderline=true;
	  font.DeleteObject();  
	  VERIFY(font.CreateFontIndirect(&lf));
      Move_DC.SelectObject(&font);
      Move_DC.DrawText(h_Name,-1,&h_rect,DT_VCENTER);
	  font.DeleteObject();  
	  
	  
	}
	else
	{
		switch(Hyber_State)
		{
		case NORMAL:
			pDC->BitBlt(0,0,w,h,&Normal_DC,0,0,SRCCOPY);
			break;

        case MOVE :
			pDC->BitBlt(0,0,w,h,&Move_DC,0,0,SRCCOPY);
			break;

		case DOWN:
			pDC->BitBlt(0,0,w,h,&Down_DC,0,0,SRCCOPY);
			break;
		}
	}


	return (HBRUSH)GetStockObject(NULL_BRUSH);
	
	
}

// NiceHyber message handlers

void NiceHyber::ToNormal()
{
 
	Is_Down=false;
	Hyber_State=NORMAL;
	RedrawWindow();
}





void NiceHyber::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if(h_rect.PtInRect(point) && !Is_Down)
	{
     Is_Down=true;
	 if(Last_Object!=NULL)
	 {
		 Last_Object->ToNormal();
         
		 
	 }
	 Last_Object=this;
	 Hyber_State=DOWN;
	 RedrawWindow();
	 ReleaseCapture();
	 ((FACTION)Funcion_Address)(h_parentDlg);
	}
	//BitBlt(::GetDC(0),0,0,w,h,Down_DC.m_hDC,0,0,SRCCOPY);
	CStatic::OnLButtonDown(nFlags, point);
}

void NiceHyber::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!Is_Down )
	if(h_rect.PtInRect(point))
	{
    Hyber_State=MOVE;
    RedrawWindow();
	SetCapture();
	}
	else
	{
	Hyber_State=NORMAL;
    RedrawWindow();
	ReleaseCapture();
	}
	
	CStatic::OnMouseMove(nFlags, point);
}



BOOL NiceHyber::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
    ::SetCursor(m_hC);	
	return true;/*CStatic::OnSetCursor(pWnd, nHitTest, message);*/
}



void NiceHyber::ToDown()
{
Is_Down=true;
	 if(Last_Object!=NULL)
	 {
		 Last_Object->ToNormal();
         
		 
	 }
	 Last_Object=this;
	 Hyber_State=DOWN;
	 RedrawWindow();
	 ReleaseCapture();
}
