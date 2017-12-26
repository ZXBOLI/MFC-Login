// normal.cpp : 实现文件
//

#include "stdafx.h"
#include "LoginTest.h"
#include "normal.h"
#include "afxdialogex.h"


// normal 对话框

IMPLEMENT_DYNAMIC(normal, CDialogEx)

normal::normal(CWnd* pParent /*=NULL*/)
	: CDialogEx(normal::IDD, pParent)
{

}

normal::~normal()
{
}

void normal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(normal, CDialogEx)
END_MESSAGE_MAP()


// normal 消息处理程序
