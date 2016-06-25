
// MFCFomulaDlg.cpp : ʵ���ļ�
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
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFCFomulaDlg �Ի���



CMFCFomulaDlg::CMFCFomulaDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCFomulaDlg::IDD, pParent)
	, m_UserFomula(_T(""))
	, m_PostFomula(_T(""))
	, m_TrueValue(_T(""))
	, m_EditValue(_T(""))
{
	//����ͼ��
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CMFCFomulaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	//�����������������
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


// CMFCFomulaDlg ��Ϣ�������

BOOL CMFCFomulaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCFomulaDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCFomulaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCFomulaDlg::OnBnClickedButtonCalculate()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);
	bool sym = true;//�ж��û���ֵ�����Ƿ������⣬��Ϊfalse
	string editvalue = CStringToString(m_EditValue);
	vector<int>value;
	if (editvalue.size() < 1)sym = false;
	for (int i = 0; i<editvalue.size(); i++)
	{
		if (editvalue[i] == '0')value.push_back(0);
		else if (editvalue[i] == '1')value.push_back(1);
		else
		{
			MessageBox(_T("\t������ı�����ֵ�д������������룡"), 
				_T("���棡"), MB_OKCANCEL | MB_ICONQUESTION);
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
			MessageBox(_T("\t������ı��ʽ���Ų�����ȷƥ�䣬���������룡"), _T("���棡"), MB_OKCANCEL | MB_ICONQUESTION);
		}
	}
	catch (std::exception const &ex)
	{
		// "exception accure:" << ex.what()
		string tempstr(ex.what());
		tempstr += "exception accure:";
		CString temp = StringToCString(tempstr);
		MessageBox(temp, _T("���棡"), MB_OKCANCEL | MB_ICONQUESTION);
	}
	catch (...)
	{
		MessageBox(_T("\t����δ֪����"), _T("���棡"), MB_OKCANCEL | MB_ICONQUESTION);
	}

	UpdateData(FALSE);
}


void CMFCFomulaDlg::OnBnClickedButtonSetValue()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	INT_PTR nRes;             // ���ڱ���DoModal�����ķ���ֵ   

	CSetTrueValue tipDlg;           // ����Ի�����CTipDlg��ʵ��   
	nRes = tipDlg.DoModal();  // �����Ի���   
	if (IDCANCEL == nRes)     // �ж϶Ի����˳��󷵻�ֵ�Ƿ�ΪIDCANCEL���������return�������������ִ��   
		return;

	// �����ؼ��е����ݱ��浽��Ӧ�ı���   
	UpdateData(TRUE);

	// ���������ͼ����ļӺ͸�ֵ��m_editSum   
	//m_editSum = m_editSummand + m_editAddend;

	// ���ݸ�������ֵ������Ӧ�Ŀؼ����͵ı༭�����ʾm_editSum��ֵ   
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
			m_ListBox.InsertString(num++,temp);  // ���б��������Ϊnum��λ�ò����ַ���  
			lastIndex = i + 1;
		}
	}
	//
}
/*
int GetCount( ) const;
����ֵ�������б�����б������Ŀ��������������򷵻�LB_ERR��

int GetSel(int nIndex) const;
������nIndexָ��ĳ���б����������
����ֵ������nIndexָ���б����״̬��
������б��ѡ�����򷵻�һ����ֵ�����򷵻�0�������������򷵻�LB_ERR��

int SetSel(int nIndex,BOOL bSelect = TRUE);
�˺���ֻ���ڶ�ѡ�б��ʹ��������ѡ���ȡ��ѡ��ָ�����б��
������nIndexָ��ĳ���б����������
��Ϊ-1���൱��ָ���������б��bSelectΪTRUEʱѡ��ָ���б������ȡ��ѡ��ָ���б��
����ֵ��������������򷵻�LB_ERR��

int AddString(LPCTSTR lpszItem);
�˺����������б��������ַ���������б��ָ����LBS_SORT���
�ַ����ͱ�������˳����뵽�б���У����û��ָ��LBS_SORT����ַ����ͱ���ӵ��б��Ľ�β��
������lpszItemָ����Ҫ��ӵ��ַ�����
����ֵ�������ַ������б������ӵ�λ�á�������������򷵻�LB_ERR,�ڴ治���򷵻�LB_ERRSPACE��

int InsertString(int nIndex, LPCTSTR lpszItem);
�ú����������б���е�ָ��λ�ò����ַ�������AddString������ͬ���ǣ�
InsertString�������ᵼ��LBS_SORT�����б���������򡣲�Ҫ�ھ���LBS_SORT�����б��
��ʹ��InsertString�����������ƻ��б���Ĵ���
������������nIndex �����˲���λ�ã������������ֵΪ-1�����ַ���������ӵ��б��ĩβ��
����lpszItem ָ����Ҫ������ַ�����
����ֵ������ʵ�ʵĲ���λ�ã����������󣬻᷵��LB_ERR ��LB_ERRSPACE��

int DeleteString(UINT nIndex);
�ú�������ɾ��ָ�����б��
������nIndex ָ����Ҫɾ�����������
����ֵ�������ķ���ֵΪʣ�µ��б�����Ŀ�����nIndex ������ʵ�ʵı����������򷵻�LB_ERR��

void ResetContent();
�ú���������������б��

int GetText(int nIndex,LPTSTR lpszBuffer) const;
void GetText(int nIndex,CString& rString) const;
��������Ա�������ڻ�ȡָ���б�����ַ���������nIndex ָ�����б����������
����lpszBuffer ָ��һ�������ַ����Ļ����������ò���rString ��ָ���˽����ַ�����CString����
��һ���汾�ĺ����᷵�ػ�õ��ַ����ĳ��ȣ��������򷵻�LB_ERR���ڶ����汾�ĺ����򲻻ᡣ

int GetTextLen(int nIndex) const;
�ú�������ָ���б�����ַ������ֽڳ��ȡ�
������nIndex ָ�����б����������
����ֵ���������򷵻�LB_ERR��

int GetCurSel() const;
�ú����������ڵ�ѡ�б���������ص�ǰ��ѡ��������������û���б��ѡ����д���������������LB_ERR��

int SetCurSel(int nSelect);
�ú����������ڵ�ѡ�б������ѡ��ָ�����б���ú���������б����ʹѡ����ɼ���
����nIndex ָ�����б������������Ϊ-1����ô������б���е�ѡ��������������LB_ERR��

int GetSelCount() const;
�ú��������ڶ���ѡ���б��������ѡ�������Ŀ��������������LB_ERR��

int FindString(int nStartAfter,LPCTSTR lpszItem) const;
�ú������ڶ��б���������Сд�޹ص�����������nStartAfter ָ���˿�ʼ������λ�ã�
����ָ��nStartAfter ���Լӿ������ٶȣ���nStartAfter Ϊ-1�����ͷ��ʼ���������б�
����lpszItem ָ����Ҫ�������ַ���������������lpszItem ָ�����ַ�����ƥ����б����������
��û���ҵ�ƥ��������˴�����᷵��LB_ERR��FindString �����ȴ�nStartAfterָ����λ�ÿ�ʼ������
��û���ҵ�ƥ�������ͷ��ʼ�����б�ֻ���ҵ�ƥ�����������б�������һ����������̲Ż�ֹͣ��
���Բ��ص��Ļ�©��Ҫ�������б��

int SelectString(int nStartAfter,LPCTSTR lpszItem);
�ú����������ڵ�ѡ�б������ѡ����ָ���ַ�����ƥ����б���ú���������б����ʹѡ����ɼ���
���������弰�����ķ����뺯��FindString ���ơ�����ҵ���ƥ�����������ظ�������������û��ƥ����
��������LB_ERR ���ҵ�ǰ��ѡ�񲻱��ı䡣*/


void CMFCFomulaDlg::OnEnChangeEditPostfomula()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
