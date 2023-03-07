
// lab230307Tabs.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab230307TabsApp:
// See lab230307Tabs.cpp for the implementation of this class
//

class Clab230307TabsApp : public CWinApp
{
public:
	Clab230307TabsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab230307TabsApp theApp;
