
// ѧ���ɼ�����ϵͳ1.0.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cѧ���ɼ�����ϵͳ10App: 
// �йش����ʵ�֣������ ѧ���ɼ�����ϵͳ1.0.cpp
//

class Cѧ���ɼ�����ϵͳ10App : public CWinApp
{
public:
	Cѧ���ɼ�����ϵͳ10App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cѧ���ɼ�����ϵͳ10App theApp;