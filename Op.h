
// Op.h : Op ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// COpApp:
// �� Ŭ������ ������ ���ؼ��� Op.cpp�� �����Ͻʽÿ�.
//

class COpApp : public CWinApp
{
public:
	COpApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COpApp theApp;
