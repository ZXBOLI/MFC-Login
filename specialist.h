#pragma once


// specialist 对话框

class specialist : public CDialogEx
{
	DECLARE_DYNAMIC(specialist)

public:
	specialist(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~specialist();

// 对话框数据
	enum { IDD = SPECIALIST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
