
// MFCFomula.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCFomulaApp: 
// �йش����ʵ�֣������ MFCFomula.cpp
//

class CMFCFomulaApp : public CWinApp
{
public:
	CMFCFomulaApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCFomulaApp theApp;