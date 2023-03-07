
// lab230307ListCtrl.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab230307ListCtrlApp:
// See lab230307ListCtrl.cpp for the implementation of this class
//

class Clab230307ListCtrlApp : public CWinApp
{
public:
	Clab230307ListCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab230307ListCtrlApp theApp;
