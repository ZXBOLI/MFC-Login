
// LoginTestDlg.h : ͷ�ļ�
//

#pragma once


// CLoginTestDlg �Ի���
class CLoginTestDlg : public CDialogEx
{
// ����
public:
	CLoginTestDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LOGINTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// �û���
	CString username;
	// ����
	CString password;
	afx_msg void OnClickedLoginButton();
	afx_msg void OnClickedExitButton();
};
