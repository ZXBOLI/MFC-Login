#pragma once


// order 对话框

class order : public CDialogEx
{
	DECLARE_DYNAMIC(order)

public:
	order(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~order();

// 对话框数据
	enum { IDD = ORDER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
