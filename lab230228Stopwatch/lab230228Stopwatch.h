
// lab230228Stopwatch.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab230228StopwatchApp:
// See lab230228Stopwatch.cpp for the implementation of this class
//

class Clab230228StopwatchApp : public CWinApp
{
public:
	Clab230228StopwatchApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab230228StopwatchApp theApp;
