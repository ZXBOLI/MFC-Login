#pragma once


// drug 对话框

class drug : public CDialogEx
{
	DECLARE_DYNAMIC(drug)

public:
	drug(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~drug();

// 对话框数据
	enum { IDD = DRUG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
