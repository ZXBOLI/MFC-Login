
// LoginTestDlg.cpp : ʵ���ļ�
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
#include <mysql.h> //mysql���ݿ��Դ���C API�����⣬������亯����libmysql.lib�Ͷ�̬���ӿ�libmysql.dll
#include <string>
#include <cstring>
#include <sstream> //����ת��ר��

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#pragma comment(lib,"G:\\Program Files (x86)\\MySQL\\MySQL Server 5.1\\lib\\opt\\libmysql.lib") //mysql���ݿ�Ŀ⺯��


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CLoginTestDlg �Ի���



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


// CLoginTestDlg ��Ϣ�������

BOOL CLoginTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLoginTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLoginTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLoginTestDlg::OnClickedLoginButton() //���µ�¼��ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(USR_EDIT)->GetWindowText(username); //���������û���
	GetDlgItem(PSWD_EDIT)->GetWindowText(password); //������������

	const char user[] = "root";
	const char pswd[] = "1111";
	const char host[] = "localhost";
	const char table[] = "testlogin";
	unsigned int port = 3306;
	char sql[300]; //�����������sql���

	MYSQL_RES *res;
	MYSQL_ROW row;
	MYSQL mysqlCon;

	if (username.IsEmpty() || password.IsEmpty())
	{
		MessageBox(_T("�û��������벻��Ϊ��!"), _T("�û���¼��Ϣ"));
		return;
	}

	mysql_init(&mysqlCon);
	if (!mysql_real_connect(&mysqlCon, host, user, pswd, table, port, NULL, 0))
	{
		AfxMessageBox(_T("�������ݿ�ʧ��!"));
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
	strcpy_s(name3, name2); //����_s����ȫ
	sprintf_s(sql, "select name, password, class from user where name = '%s';", name3); //����_s����ȫ
	int ress = mysql_query(&mysqlCon, sql);
	if (ress == 0) //����ѯ�ɹ�
	{
		res = mysql_store_result(&mysqlCon);
		if (mysql_num_rows(res) == 0) //��ѯ���Ϊ��
		{
			AfxMessageBox(_T("�û�������"));
		}
		else
		{
			
			row = mysql_fetch_row(res);
			if (password == row[1])
			{
				MessageBox(_T("��¼�ɹ�!"));
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
				AfxMessageBox(_T("�������!"));
			}
		}


	}

	mysql_close(&mysqlCon);
}


void CLoginTestDlg::OnClickedExitButton() //�����˳���ť
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox(_T("ȷ���˳�"), _T("�˳�"), MB_YESNO | MB_ICONQUESTION) == IDYES){
		this->SendMessage(WM_CLOSE);
	}
}
