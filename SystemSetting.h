// SystemSetting.h: interface for the SystemSetting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSTEMSETTING_H__035D4981_97F4_11D9_BEB5_AD55A21A077C__INCLUDED_)
#define AFX_SYSTEMSETTING_H__035D4981_97F4_11D9_BEB5_AD55A21A077C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
const byte VL=0; //very low
const byte L=1;  //low 
const byte N=2;  //normal
const byte AN=3; //Above normal
const byte H=4;  //High
const byte VH=5; //Very high



class SystemSetting :public CObject
{
DECLARE_SERIAL(SystemSetting)
public:
	void Backup(CString);
	bool Load(CString);
	bool Store(CString cszFilePath);
	//data
	int m_NeededSize;
	CString m_RecordingPath;
	CFile SysSetting_file;
	int Is_onTop;
	int Is_load_on_fauiler;
	int Is_Auto_StartUp;

	

	
	
	void Serialize( CArchive& archive );		
	SystemSetting();
	virtual ~SystemSetting();
	

};

#endif // !defined(AFX_SYSTEMSETTING_H__035D4981_97F4_11D9_BEB5_AD55A21A077C__INCLUDED_)
