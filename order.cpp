// order.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LoginTest.h"
#include "order.h"
#include "afxdialogex.h"


// order �Ի���

IMPLEMENT_DYNAMIC(order, CDialogEx)

order::order(CWnd* pParent /*=NULL*/)
	: CDialogEx(order::IDD, pParent)
{

}

order::~order()
{
}

void order::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(order, CDialogEx)
END_MESSAGE_MAP()


// order ��Ϣ�������
