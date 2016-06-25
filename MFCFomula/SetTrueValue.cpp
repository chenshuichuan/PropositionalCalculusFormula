// SetTrueValue.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCFomula.h"
#include "SetTrueValue.h"
#include "afxdialogex.h"


// CSetTrueValue 对话框

IMPLEMENT_DYNAMIC(CSetTrueValue, CDialogEx)

CSetTrueValue::CSetTrueValue(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetTrueValue::IDD, pParent)
{

}

CSetTrueValue::~CSetTrueValue()
{
}

void CSetTrueValue::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSetTrueValue, CDialogEx)
END_MESSAGE_MAP()


// CSetTrueValue 消息处理程序
