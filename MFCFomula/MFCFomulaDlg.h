
// MFCFomulaDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include<string>
using namespace std;

// CMFCFomulaDlg 对话框
class CMFCFomulaDlg : public CDialogEx
{
// 构造
public:
	CMFCFomulaDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCFOMULA_DIALOG };

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
	
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedButtonSetValue();

    // 用户输入的字符串
	CString m_UserFomula;
	// //转化后的后缀表达式
	CString m_PostFomula;
	
	// //用于输出二叉树
	CListBox m_ListBox;
	// //计算真值结果
	CString m_TrueValue;
	
	void CMFCFomulaDlg::SetListBox(string str);
	// //用户输入的真值
	CString m_EditValue;
	afx_msg void OnEnChangeEditPostfomula();
};
