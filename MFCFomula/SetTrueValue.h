#pragma once

#include<string>
#include<vector>
using namespace std;
// CSetTrueValue �Ի���

class CSetTrueValue : public CDialogEx
{
	DECLARE_DYNAMIC(CSetTrueValue)

public:
	CSetTrueValue(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetTrueValue();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

	void SetValue(const vector<string> &str);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	//�Ի�������
	vector<string >m_Value;
	vector<string> m_TrueValue;
	DECLARE_MESSAGE_MAP()
};
