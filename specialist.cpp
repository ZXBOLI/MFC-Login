// specialist.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LoginTest.h"
#include "specialist.h"
#include "afxdialogex.h"


// specialist �Ի���

IMPLEMENT_DYNAMIC(specialist, CDialogEx)

specialist::specialist(CWnd* pParent /*=NULL*/)
	: CDialogEx(specialist::IDD, pParent)
{

}

specialist::~specialist()
{
}

void specialist::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(specialist, CDialogEx)
END_MESSAGE_MAP()


// specialist ��Ϣ�������
