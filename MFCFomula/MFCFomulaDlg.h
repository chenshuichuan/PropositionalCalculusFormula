
// MFCFomulaDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include<string>
using namespace std;

// CMFCFomulaDlg �Ի���
class CMFCFomulaDlg : public CDialogEx
{
// ����
public:
	CMFCFomulaDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCFOMULA_DIALOG };

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
	
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedButtonSetValue();

    // �û�������ַ���
	CString m_UserFomula;
	// //ת����ĺ�׺���ʽ
	CString m_PostFomula;
	
	// //�������������
	CListBox m_ListBox;
	// //������ֵ���
	CString m_TrueValue;
	
	void CMFCFomulaDlg::SetListBox(string str);
	// //�û��������ֵ
	CString m_EditValue;
	afx_msg void OnEnChangeEditPostfomula();
};
