#pragma once


// order �Ի���

class order : public CDialogEx
{
	DECLARE_DYNAMIC(order)

public:
	order(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~order();

// �Ի�������
	enum { IDD = ORDER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
