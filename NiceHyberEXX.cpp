// NiceHyberEXX.cpp : implementation file
//

#include "stdafx.h"
#include "hpro.h"
#include "NiceHyberEXX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NiceHyberEX

NiceHyberEX::NiceHyberEX()
{
	w=h=top=bottom=0;
	Is_First_Drown=true;
	Is_Down=false;
	memset(&lf, 0, sizeof(LOGFONT));       // zero out structure
    lf.lfHeight = 22;   
	strcpy(lf.lfFaceName, "Monotype Corsiva");        // request a face name "Arial"
	lf.lfUnderline=false;
	

	VERIFY(font.CreateFontIndirect(&lf));
	Hyber_State=NORMAL;
	Normal_DC.CreateCompatibleDC(0);
	Move_DC.CreateCompatibleDC(0);
	Down_DC.CreateCompatibleDC(0);
    m_hC=AfxGetApp()->LoadCursor(IDC_CR);
}

NiceHyberEX::~NiceHyberEX()
{
}


BEGIN_MESSAGE_MAP(NiceHyberEX, CStatic)
	//{{AFX_MSG_MAP(NiceHyberEX)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NiceHyberEX message handlers



HBRUSH NiceHyberEX::CtlColor(CDC* pDC, UINT nCtlColor) 
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
	  pDC->Draw3dRect(&h_rect,RGB(255,255,255),RGB(0,0,0));
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

void NiceHyberEX::OnLButtonDown(UINT nFlags, CPoint point) 
{
		if(h_rect.PtInRect(point) )
	{
     Is_Down=true;
	 Hyber_State=DOWN;
	 RedrawWindow();
	 SetCapture();
	 Sleep(200);
	 
	}
	
	CStatic::OnLButtonDown(nFlags, point);
}

void NiceHyberEX::OnLButtonUp(UINT nFlags, CPoint point) 
{
		 
	    
	if(Is_Down)
	    if(h_rect.PtInRect(point))
		{
		   Is_Down=false;
		   Hyber_State=NORMAL;
	       RedrawWindow();
	       ReleaseCapture();
	      ((FACTION)Funcion_Address)(h_parentDlg);

		}
		else
		{
           Is_Down=false;
		   Hyber_State=NORMAL;
	       RedrawWindow();
	       ReleaseCapture();
		}


		
	
	CStatic::OnLButtonUp(nFlags, point);
}

void NiceHyberEX::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(!Is_Down)
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
	
	else
    if(h_rect.PtInRect(point))
	{
    Hyber_State=DOWN;
    RedrawWindow();
	//SetCapture();
	}
	else
	{
	Hyber_State=NORMAL;
    RedrawWindow();
	//ReleaseCapture();
	}

	
	CStatic::OnMouseMove(nFlags, point);
}



BOOL NiceHyberEX::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
::SetCursor(m_hC);	
	
	return true;
}




