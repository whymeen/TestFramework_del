
// TestFramework_del.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CTestFramework_delApp:
// �� Ŭ������ ������ ���ؼ��� TestFramework_del.cpp�� �����Ͻʽÿ�.
//

class CTestFramework_delApp : public CWinApp
{
public:
	CTestFramework_delApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CTestFramework_delApp theApp;