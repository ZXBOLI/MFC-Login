#pragma once


// normal 对话框

class normal : public CDialogEx
{
	DECLARE_DYNAMIC(normal)

public:
	normal(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~normal();

// 对话框数据
	enum { IDD = NORMAL_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
