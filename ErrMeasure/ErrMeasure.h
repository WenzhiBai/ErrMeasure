
// ErrMeasure.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CErrMeasureApp: 
// �йش����ʵ�֣������ ErrMeasure.cpp
//

class CErrMeasureApp : public CWinApp
{
public:
	CErrMeasureApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CErrMeasureApp theApp;