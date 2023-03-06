
// lab230228Clock.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab230228ClockApp:
// See lab230228Clock.cpp for the implementation of this class
//

class Clab230228ClockApp : public CWinApp
{
public:
	Clab230228ClockApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab230228ClockApp theApp;
