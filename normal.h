#pragma once


// normal �Ի���

class normal : public CDialogEx
{
	DECLARE_DYNAMIC(normal)

public:
	normal(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~normal();

// �Ի�������
	enum { IDD = NORMAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
