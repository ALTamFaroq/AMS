// HistogramDislpayer.h: interface for the HistogramDislpayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HISTOGRAMDISLPAYER_H__7714DEC7_2F40_4DC2_BB68_3E7A03C2DE4C__INCLUDED_)
#define AFX_HISTOGRAMDISLPAYER_H__7714DEC7_2F40_4DC2_BB68_3E7A03C2DE4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class HistogramDislpayer  
{
public:
	void DisplayHistogram(HDC m_hDC,CRect  *m_Rect);
	void ComputeHistogram(COLORREF data[][96]);
	HistogramDislpayer();
	virtual ~HistogramDislpayer();
	//data

	byte m_HistogramData[256];
	CDC m_hDC;


};

#endif // !defined(AFX_HISTOGRAMDISLPAYER_H__7714DEC7_2F40_4DC2_BB68_3E7A03C2DE4C__INCLUDED_)
