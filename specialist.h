#pragma once


// specialist �Ի���

class specialist : public CDialogEx
{
	DECLARE_DYNAMIC(specialist)

public:
	specialist(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~specialist();

// �Ի�������
	enum { IDD = SPECIALIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
