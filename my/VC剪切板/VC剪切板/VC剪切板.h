
// VC���а�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CVC���а�App: 
// �йش����ʵ�֣������ VC���а�.cpp
//

class CVC���а�App : public CWinApp
{
public:
	CVC���а�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CVC���а�App theApp;