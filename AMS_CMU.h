// AMS_CMU.h: interface for the AMS_CMU class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AMS_CMU_H__6C7C26CB_601D_43C4_A8D9_DF073FF438FC__INCLUDED_)
#define AFX_AMS_CMU_H__6C7C26CB_601D_43C4_A8D9_DF073FF438FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AMS_AFrame.h"
#include "Transformer.h"

#pragma comment (lib,"vfw32")
class AMS_CMU  //camera manipulation unit CMU
{
public:
	
	//attribute
	HWND hCapWnd;
	CObject *m_parentCls;
	BITMAPINFO bmp;
	AMS_AFrame m_Next_AFrame;
	bool Is_Connected;
public :
	void SetParentCls(CObject * m_obParent);
	void Store_Stream_ToFile(CString cspath);
	void Start_Sequence_ToFile(CString cspath,int);
	bool Start_Sequence_NoFile(void);
	bool Camera_Connect();
	void DestroyCurrentCaptureWindow(void);
	bool CreateNewCaptureWindow(void);
	//methods
	
	bool SetVidoparam(void);//used to setup video parameter 
	friend  LRESULT CALLBACK OnVideoReceived(HWND h_CapWnd,LPVIDEOHDR lpVhdr);
	friend  LRESULT CALLBACK OnCameraError(HWND h_CapWnd ,int ERR_ID,LPSTR ERR_Text);
	
	AMS_CMU();
	virtual ~AMS_CMU();

};

#endif // !defined(AFX_AMS_CMU_H__6C7C26CB_601D_43C4_A8D9_DF073FF438FC__INCLUDED_)
