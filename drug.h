#pragma once


// drug �Ի���

class drug : public CDialogEx
{
	DECLARE_DYNAMIC(drug)

public:
	drug(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~drug();

// �Ի�������
	enum { IDD = DRUG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
