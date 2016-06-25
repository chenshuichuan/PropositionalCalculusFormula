
// MFCFomulaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCFomula.h"
#include "MFCFomulaDlg.h"
#include "afxdialogex.h"

#include"Fomula.h"
#include"SetTrueValue.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


string CStringToString(const CString &cstr)
{
	string tempstr(CString::StringLength(cstr), '0');
	for (int i = 0; i < CString::StringLength(cstr); i++)
	{
		tempstr[i] = (char)cstr[i];
	}
	return tempstr;
}
CString StringToCString(const string &str)
{
	CString tempcstr(str.c_str());
	return tempcstr;
}
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCFomulaDlg 对话框



CMFCFomulaDlg::CMFCFomulaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCFomulaDlg::IDD, pParent)
	, m_UserFomula(_T(""))
	, m_PostFomula(_T(""))
	, m_TrueValue(_T(""))
	, m_EditValue(_T(""))
{
	//设置图标
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMFCFomulaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//窗口数据与变量交换
	DDX_Text(pDX, IDC_EDIT_Fomula, m_UserFomula);
	DDX_Text(pDX, IDC_EDIT_POSTFOMULA, m_PostFomula);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Text(pDX, IDC_EDIT_VALUE, m_TrueValue);
	DDX_Text(pDX, IDC_EDIT1, m_EditValue);
}

BEGIN_MESSAGE_MAP(CMFCFomulaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CMFCFomulaDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_BUTTON_SET_VALUE, &CMFCFomulaDlg::OnBnClickedButtonSetValue)
	ON_EN_CHANGE(IDC_EDIT_POSTFOMULA, &CMFCFomulaDlg::OnEnChangeEditPostfomula)
END_MESSAGE_MAP()


// CMFCFomulaDlg 消息处理程序

BOOL CMFCFomulaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCFomulaDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCFomulaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCFomulaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCFomulaDlg::OnBnClickedButtonCalculate()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);
	bool sym = true;//判断用户真值输入是否有问题，有为false
	string editvalue = CStringToString(m_EditValue);
	vector<int>value;
	if (editvalue.size() < 1)sym = false;
	for (int i = 0; i<editvalue.size(); i++)
	{
		if (editvalue[i] == '0')value.push_back(0);
		else if (editvalue[i] == '1')value.push_back(1);
		else
		{
			MessageBox(_T("\t您输入的变量真值有错误，请重新输入！"), 
				_T("警告！"), MB_OKCANCEL | MB_ICONQUESTION);
			sym = false;
		}
			
	}
	try{
		Fomula myFomula;
		string sFomula = "~(a123&bcd|ang&cnm&(a123&bcd))";//storage the user's input
		sFomula = CStringToString(m_UserFomula);
		//m_Fomula = StringToCString(sFomula);
		myFomula.SetFomula(sFomula);
		if (1 <= sFomula.size() && myFomula.FomulaCorrect()&&sym==true)
		{
			myFomula.Transfer();
			myFomula.SetPostFomula();
			m_PostFomula = StringToCString(myFomula.GetPostFomula());
			myFomula.MakeBitree();

			m_ListBox.ResetContent();
			SetListBox(myFomula.GetBitreeStr());
			//myFomula.SetTrueValueForTest(value);//for test
			myFomula.SetTrueValue(value, editvalue.size());

			if (myFomula.Calculate())m_TrueValue = "true";
			else m_TrueValue = "false";
		}
		else
		{
			MessageBox(_T("\t您输入的表达式括号不能正确匹配，请重新输入！"), _T("警告！"), MB_OKCANCEL | MB_ICONQUESTION);
		}
	}
	catch (std::exception const &ex)
	{
		// "exception accure:" << ex.what()
		string tempstr(ex.what());
		tempstr += "exception accure:";
		CString temp = StringToCString(tempstr);
		MessageBox(temp, _T("警告！"), MB_OKCANCEL | MB_ICONQUESTION);
	}
	catch (...)
	{
		MessageBox(_T("\t发生未知错误！"), _T("警告！"), MB_OKCANCEL | MB_ICONQUESTION);
	}

	UpdateData(FALSE);
}


void CMFCFomulaDlg::OnBnClickedButtonSetValue()
{
	// TODO:  在此添加控件通知处理程序代码
	INT_PTR nRes;             // 用于保存DoModal函数的返回值   

	CSetTrueValue tipDlg;           // 构造对话框类CTipDlg的实例   
	nRes = tipDlg.DoModal();  // 弹出对话框   
	if (IDCANCEL == nRes)     // 判断对话框退出后返回值是否为IDCANCEL，如果是则return，否则继续向下执行   
		return;

	// 将各控件中的数据保存到相应的变量   
	UpdateData(TRUE);

	// 将被加数和加数的加和赋值给m_editSum   
	//m_editSum = m_editSummand + m_editAddend;

	// 根据各变量的值更新相应的控件。和的编辑框会显示m_editSum的值   
	UpdateData(FALSE);

}

void CMFCFomulaDlg::SetListBox(string str)
{
	size_t lastIndex = 0;
	int num = 0; 
	CString temp;
	for (size_t i = 0; i < str.size(); i++)
	{
		char tp = str[i];
		if (str[i] == '#')
		{
			string s(str, lastIndex, i-lastIndex);
			 temp= StringToCString(s);
			m_ListBox.InsertString(num++,temp);  // 在列表框中索引为num的位置插入字符串  
			lastIndex = i + 1;
		}
	}
	//
}
/*
int GetCount( ) const;
返回值：返回列表框中列表项的数目，如果发生错误则返回LB_ERR。

int GetSel(int nIndex) const;
参数：nIndex指定某个列表项的索引。
返回值：返回nIndex指定列表项的状态。
如果此列表项被选择了则返回一个正值，否则返回0，若发生错误则返回LB_ERR。

int SetSel(int nIndex,BOOL bSelect = TRUE);
此函数只用于多选列表框，使用它可以选择或取消选择指定的列表项。
参数：nIndex指定某个列表项的索引，
若为-1则相当于指定了所有列表项。bSelect为TRUE时选择指定列表项，否则取消选择指定列表项。
返回值：如果发生错误则返回LB_ERR。

int AddString(LPCTSTR lpszItem);
此函数用来向列表框中添加字符串。如果列表框指定了LBS_SORT风格，
字符串就被以排序顺序插入到列表框中，如果没有指定LBS_SORT风格，字符串就被添加到列表框的结尾。
参数：lpszItem指定了要添加的字符串。
返回值：返回字符串在列表框中添加的位置。如果发生错误则返回LB_ERR,内存不够则返回LB_ERRSPACE。

int InsertString(int nIndex, LPCTSTR lpszItem);
该函数用来在列表框中的指定位置插入字符串。与AddString函数不同的是，
InsertString函数不会导致LBS_SORT风格的列表框重新排序。不要在具有LBS_SORT风格的列表框
中使用InsertString函数，以免破坏列表项的次序。
参数：。参数nIndex 给出了插入位置（索引），如果值为-1，则字符串将被添加到列表的末尾。
参数lpszItem 指定了要插入的字符串。
返回值：返回实际的插入位置，若发生错误，会返回LB_ERR 或LB_ERRSPACE。

int DeleteString(UINT nIndex);
该函数用于删除指定的列表项。
参数：nIndex 指定了要删除项的索引。
返回值：函数的返回值为剩下的列表项数目，如果nIndex 超过了实际的表项总数，则返回LB_ERR。

void ResetContent();
该函数用于清除所有列表项。

int GetText(int nIndex,LPTSTR lpszBuffer) const;
void GetText(int nIndex,CString& rString) const;
这两个成员函数用于获取指定列表项的字符串。参数nIndex 指定了列表项的索引。
参数lpszBuffer 指向一个接收字符串的缓冲区。引用参数rString 则指定了接收字符串的CString对象。
第一个版本的函数会返回获得的字符串的长度，若出错，则返回LB_ERR；第二个版本的函数则不会。

int GetTextLen(int nIndex) const;
该函数返回指定列表项的字符串的字节长度。
参数：nIndex 指定了列表项的索引。
返回值：若出错则返回LB_ERR。

int GetCurSel() const;
该函数仅适用于单选列表框，用来返回当前被选择项的索引，如果没有列表项被选择或有错误发生，则函数返回LB_ERR。

int SetCurSel(int nSelect);
该函数仅适用于单选列表框，用来选择指定的列表项。该函数会滚动列表框以使选择项可见。
参数nIndex 指定了列表项的索引，若为-1，那么将清除列表框中的选择。若出错函数返回LB_ERR。

int GetSelCount() const;
该函数仅用于多重选择列表框，它返回选择项的数目，若出错函数返回LB_ERR。

int FindString(int nStartAfter,LPCTSTR lpszItem) const;
该函数用于对列表项进行与大小写无关的搜索。参数nStartAfter 指定了开始搜索的位置，
合理指定nStartAfter 可以加快搜索速度，若nStartAfter 为-1，则从头开始搜索整个列表。
参数lpszItem 指定了要搜索的字符串。函数返回与lpszItem 指定的字符串相匹配的列表项的索引，
若没有找到匹配项或发生了错误，则会返回LB_ERR。FindString 函数先从nStartAfter指定的位置开始搜索，
若没有找到匹配项，则会从头开始搜索列表。只有找到匹配项，或对整个列表搜索完一遍后，搜索过程才会停止，
所以不必担心会漏掉要搜索的列表项。

int SelectString(int nStartAfter,LPCTSTR lpszItem);
该函数仅适用于单选列表框，用来选择与指定字符串相匹配的列表项。该函数会滚动列表框以使选择项可见。
参数的意义及搜索的方法与函数FindString 类似。如果找到了匹配的项，函数返回该项的索引，如果没有匹配的项，
函数返回LB_ERR 并且当前的选择不被改变。*/


void CMFCFomulaDlg::OnEnChangeEditPostfomula()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
