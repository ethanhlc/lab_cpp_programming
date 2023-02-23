
// lab230223MFC.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Clab230223MFCApp:
// See lab230223MFC.cpp for the implementation of this class
//

class Clab230223MFCApp : public CWinApp
{
public:
	Clab230223MFCApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Clab230223MFCApp theApp;
