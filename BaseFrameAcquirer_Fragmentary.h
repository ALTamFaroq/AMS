// BaseFrameAcquirer_Fragmentary.h: interface for the BaseFrameAcquirer_Fragmentary class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEFRAMEACQUIRER_FRAGMENTARY_H__83C9BCBA_C5EA_4F63_86CB_150874CC6FC7__INCLUDED_)
#define AFX_BASEFRAMEACQUIRER_FRAGMENTARY_H__83C9BCBA_C5EA_4F63_86CB_150874CC6FC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class BaseFrameAcquirer_Fragmentary  
{
public:
	void GetSegment(int Seg_Index, COLORREF Segment[][16]);
	void FragmentBase();
	void SetBase(COLORREF base[][96]);
	BaseFrameAcquirer_Fragmentary();
	virtual ~BaseFrameAcquirer_Fragmentary();
	//data 
	COLORREF m_arr_color_Base_Frame[128][96]; //base frame
	COLORREF m_arr_byte_Segment[48][16][16]; //number of segment * (segment size);
	int m_NextSegment;
	bool Is_Base_Created;  //to check when base is created;
	HDC m_hBaseDC;  //to store base 
	HBITMAP m_hBaseBmp; //to create BaseDC;




};

#endif // !defined(AFX_BASEFRAMEACQUIRER_FRAGMENTARY_H__83C9BCBA_C5EA_4F63_86CB_150874CC6FC7__INCLUDED_)
