
// LoginTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LoginTest.h"
#include "LoginTestDlg.h"
#include "afxdialogex.h"
#include "order.h"
#include "normal.h"
#include "specialist.h"
#include "drug.h"
#include <Windows.h>
#include <mysql.h> //mysql数据库自带的C API函数库，还需搭配函数库libmysql.lib和动态链接库libmysql.dll
#include <string>
#include <cstring>
#include <sstream> //类型转换专用

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma comment(lib,"G:\\Program Files (x86)\\MySQL\\MySQL Server 5.1\\lib\\opt\\libmysql.lib") //mysql数据库的库函数


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CLoginTestDlg 对话框



CLoginTestDlg::CLoginTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLoginTestDlg::IDD, pParent)
	, username(_T(""))
	, password(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoginTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, USR_EDIT, username);
	DDX_Text(pDX, PSWD_EDIT, password);
}

BEGIN_MESSAGE_MAP(CLoginTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(LOGIN_BUTTON, &CLoginTestDlg::OnClickedLoginButton)
	ON_BN_CLICKED(EXIT_BUTTON, &CLoginTestDlg::OnClickedExitButton)
END_MESSAGE_MAP()


// CLoginTestDlg 消息处理程序

BOOL CLoginTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CLoginTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CLoginTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CLoginTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLoginTestDlg::OnClickedLoginButton() //按下登录按钮
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(USR_EDIT)->GetWindowText(username); //获得输入的用户名
	GetDlgItem(PSWD_EDIT)->GetWindowText(password); //获得输入的密码

	const char user[] = "root";
	const char pswd[] = "1111";
	const char host[] = "localhost";
	const char table[] = "testlogin";
	unsigned int port = 3306;
	char sql[300]; //待加入参数的sql语句

	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL mysqlCon;

	if (username.IsEmpty() || password.IsEmpty())
	{
		MessageBox(_T("用户名或密码不能为空!"), _T("用户登录信息"));
		return;
	}

	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, host, user, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("访问数据库失败!"));
	}
	else
	{
		mysql_query(&mysqlCon,"SET USER GBK"); 

	}
	std::string name1;
	name1 = (char*)_bstr_t(username);
	char name3[100];
	const char *name2;
	name2 = name1.c_str();
	strcpy_s(name3, name2); //加入_s更安全
	sprintf_s(sql, "select name, password, class from user where name = '%s';", name3); //加入_s更安全
	int ress = mysql_query(&mysqlCon, sql);
	if (ress == 0) //检测查询成功
	{
		res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0) //查询结果为空
		{
			AfxMessageBox(_T("用户不存在"));
		}
		else
		{
			
			row = mysql_fetch_row(res);
			if (password == row[1])
			{
				MessageBox(_T("登录成功!"));
				if (!strcmp(row[2],"order"))
				{
					mysql_free_result(res);
					CDialog::OnOK();
					order order_dlg;
					order_dlg.DoModal();
					
				}
				else if (!strcmp(row[2], "normal"))
				{
					mysql_free_result(res);
					CDialog::OnOK();
					normal normal_dlg;
					normal_dlg.DoModal();
					
				}
				else if (!strcmp(row[2], "specialist"))
				{
					mysql_free_result(res);
					CDialog::OnOK();
					specialist specialist_dlg;
					specialist_dlg.DoModal();
				}
				else if (!strcmp(row[2], "drug"))
				{
					mysql_free_result(res);
					CDialog::OnOK();
					drug drug_dlg;
					drug_dlg.DoModal();
				}
			}
			else
			{
				AfxMessageBox(_T("密码错误!"));
			}
		}


	}

	mysql_close(&mysqlCon);
}


void CLoginTestDlg::OnClickedExitButton() //按下退出按钮
{
	// TODO:  在此添加控件通知处理程序代码
	if (MessageBox(_T("确认退出"), _T("退出"), MB_YESNO | MB_ICONQUESTION) == IDYES){
		this->SendMessage(WM_CLOSE);
	}
}
