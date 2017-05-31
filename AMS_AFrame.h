// AMS_AFrame.h: interface for the AMS_AFrame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMS_AFRAME_H__C8E118DB_A242_4EFB_A9AB_8A487F3D628B__INCLUDED_)
#define AFX_AMS_AFRAME_H__C8E118DB_A242_4EFB_A9AB_8A487F3D628B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<vfw.h>
class AMS_AFrame  // AFrame Acquired farme class 
{
public:
	//data
	byte *AF_Data;
	BITMAPINFO AF_Bmpinfo;
	HDRAWDIB hDib;

	AMS_AFrame();
	virtual ~AMS_AFrame();

};

#endif // !defined(AFX_AMS_AFRAME_H__C8E118DB_A242_4EFB_A9AB_8A487F3D628B__INCLUDED_)
