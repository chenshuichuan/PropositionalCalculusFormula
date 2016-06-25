#pragma once

#include<string>
#include<vector>
using namespace std;
// CSetTrueValue 对话框

class CSetTrueValue : public CDialogEx
{
	DECLARE_DYNAMIC(CSetTrueValue)

public:
	CSetTrueValue(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetTrueValue();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

	void SetValue(const vector<string> &str);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	//对话框数据
	vector<string >m_Value;
	vector<string> m_TrueValue;
	DECLARE_MESSAGE_MAP()
};
