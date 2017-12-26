
// LoginTestDlg.h : 头文件
//

#pragma once


// CLoginTestDlg 对话框
class CLoginTestDlg : public CDialogEx
{
// 构造
public:
	CLoginTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LOGINTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 用户名
	CString username;
	// 密码
	CString password;
	afx_msg void OnClickedLoginButton();
	afx_msg void OnClickedExitButton();
};
