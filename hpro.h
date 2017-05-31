// hpro.h : main header file for the HPRO application
//

#if !defined(AFX_HPRO_H__86D7D11F_BFC0_4C4C_A178_5F96BC547D8D__INCLUDED_)
#define AFX_HPRO_H__86D7D11F_BFC0_4C4C_A178_5F96BC547D8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif


#include "resource.h"		// main symbols
#include "AMS_AFrame.h"



/////////////////////////////////////////////////////////////////////////////
// CHproApp:
// See hpro.cpp for the implementation of this class
//


// Transformer ports states
const short OPEN_PORT_2  =0x2;  //connection established ..frame diplayer
const short OPEN_PORT_0  =0x20;  //All ports closed
const short OPEN_PORT_3  =0x23;  //to base recorder & frame diplayer
const short OPEN_PORT_6  =0x26; //When satrt monitoring

enum h_State {NORMAL,MOVE,DOWN};
typedef void (*FACTION)(CDialog*);









//Camera Commands



class CHproApp : public CWinApp
{
public:
	CHproApp();
	
    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHproApp)
	public:
		
	virtual BOOL InitInstance();
     
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHproApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HPRO_H__86D7D11F_BFC0_4C4C_A178_5F96BC547D8D__INCLUDED_)


