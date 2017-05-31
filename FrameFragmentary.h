// FrameFragmentary.h: interface for the FrameFragmentary class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMEFRAGMENTARY_H__2306BE33_5CDE_4468_9608_41C759315E36__INCLUDED_)
#define AFX_FRAMEFRAGMENTARY_H__2306BE33_5CDE_4468_9608_41C759315E36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "BaseFrameAcquirer_Fragmentary.h"
#include "User.h"

class FrameFragmentary  
{
public:
	void CreateDC_BMP();
	void DisplayWBFrame();
	void WBQuntization(int Threshold_Value, COLORREF AF_segment[][16],COLORREF Base_Segment [][16]);
	int GetAdaptiveThresholdValue(COLORREF segment[][96]);
	void Fragment(COLORREF frame[][96]);
     BaseFrameAcquirer_Fragmentary * m_base_acquire;
	 FrameFragmentary();
	virtual ~FrameFragmentary();

	//attributes
	COLORREF m_arr_byte_Segment[48][16][16];
	COLORREF m_Base_Segment[16][16];
	byte m_Segment_Histogram[256];
	float Maxy,Maxx, Miny,Minx,Newx;
	int Threshold;
	float m;
	double D_Threshold,D_Threshold_1;
	CDC m_hdc ;
	CBitmap m_bmp;
	
	HWND m_wnd;
	byte Segemnt_Threshods[48]; //48 segments
	CWinThread * m_Snd_Thraed;
	friend UINT Start_ALert(LPVOID pParam);
	CWinThread * m_Stop_Thraed;
	friend UINT Stop_ALert(LPVOID pParam);
	bool Is_threads_suspendes;
	User * m_user;
	CDialog * m_parent;
	bool is_on;
	CRect *m_filterd_rect;
	HDC m_parent_hDC;


	




};

#endif // !defined(AFX_FRAMEFRAGMENTARY_H__2306BE33_5CDE_4468_9608_41C759315E36__INCLUDED_)
