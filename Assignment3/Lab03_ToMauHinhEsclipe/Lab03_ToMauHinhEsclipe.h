
// Lab03_ToMauHinhEsclipe.h : main header file for the Lab03_ToMauHinhEsclipe application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLab03ToMauHinhEsclipeApp:
// See Lab03_ToMauHinhEsclipe.cpp for the implementation of this class
//

class CLab03ToMauHinhEsclipeApp : public CWinAppEx
{
public:
	CLab03ToMauHinhEsclipeApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLab03ToMauHinhEsclipeApp theApp;
