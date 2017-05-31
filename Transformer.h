// Transformer.h: interface for the Transformer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORMER_H__B95F735F_B184_484F_A02A_BCDBA39A5AFC__INCLUDED_)
#define AFX_TRANSFORMER_H__B95F735F_B184_484F_A02A_BCDBA39A5AFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FrameDisplayer.h"
#include "BaseFrameAcquirer_Fragmentary.h"
#include "HistogramDislpayer.h"
#include "FrameFragmentary.h"

class Transformer  :public CObject
{
public:
	//Attributes
	  short Opened_Port;
	  FrameDisplayer * m_FrDisplayer;
	  COLORREF  Graed_Data[128][96];
	  COLORREF  Graed_Filtered_Data_[128][96];
	  BaseFrameAcquirer_Fragmentary m_base_cls;
	  HistogramDislpayer m_hist;
	  FrameFragmentary m_Frame_Frag;
	  int w,h;
	  HDC d;
	  CRect * m_base_rect,* m_Histogram_rect;
	  CDialog * m_paren;
	  CFile m_f;
      CFileStatus sts;
      long fl;
	  bool is_alert;




public:
	void ToBlurFilter(AMS_AFrame * m_AFrame);
	void GetColorRefArray(HBITMAP);
	void Transfer(AMS_AFrame*);
	void SetPort(short);
	Transformer();
	virtual ~Transformer();

};

#endif // !defined(AFX_TRANSFORMER_H__B95F735F_B184_484F_A02A_BCDBA39A5AFC__INCLUDED_)
