
// MusicTest_1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMusicTest_1App: 
// �йش����ʵ�֣������ MusicTest_1.cpp
//

class CMusicTest_1App : public CWinApp
{
public:
	CMusicTest_1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMusicTest_1App theApp;