// drug.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LoginTest.h"
#include "drug.h"
#include "afxdialogex.h"


// drug �Ի���

IMPLEMENT_DYNAMIC(drug, CDialogEx)

drug::drug(CWnd* pParent /*=NULL*/)
	: CDialogEx(drug::IDD, pParent)
{

}

drug::~drug()
{
}

void drug::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(drug, CDialogEx)
END_MESSAGE_MAP()


// drug ��Ϣ�������
