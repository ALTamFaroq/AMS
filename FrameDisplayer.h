// FrameDisplayer.h: interface for the FrameDisplayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMEDISPLAYER_H__2546FEED_F88B_49AF_8F3B_DE42A3AB5DBF__INCLUDED_)
#define AFX_FRAMEDISPLAYER_H__2546FEED_F88B_49AF_8F3B_DE42A3AB5DBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class FrameDisplayer  
{
public :
	//Attribute 
	CRect *m_Rect;
	HDC   m_hDC;
	CDC   m_DC,m_DC_1; //for store the AFrame & trnsform  it.
	HBITMAP  m_hOldBMP,m_hNewBMP;

public:
	void DisplayBaseFrame(HDC src_hDC,CRect * m_rect_Base);
	void Create_AFrameDC(AMS_AFrame *);
	void DisplayAFrame(AMS_AFrame * m_AFrame);

	FrameDisplayer();
	virtual ~FrameDisplayer();

};

#endif // !defined(AFX_FRAMEDISPLAYER_H__2546FEED_F88B_49AF_8F3B_DE42A3AB5DBF__INCLUDED_)
