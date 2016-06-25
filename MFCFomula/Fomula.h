#pragma once
#include "stdafx.h"
#include"Bitree.h"
#include"Stack.h"
#include<vector>
using std::vector;
//typedef int myitem;
class Fomula
{
private:
	Bitree m_Tree;//������
	string m_Fomula;//�û����빫ʽ
	string m_postFomula;//��׺���ʽ
	vector<string> m_varriable;//���ڷֿ��洢�����������
	string m_BitreeStr;//�������ַ��������������������ݼ��ϵ��ַ�����

	vector<int> m_TrueValue;//��ֵջ���洢��ֵ,������ֵ-1
	//�������е���ֵ������ֵջ
	void SetTrueValue(vector<int>&);
	//���ݹ���õĶ������ݹ���ü�����
	bool Calculate(BitreeNode<myData> *ptr)const;
	//�������������
	void MidVisit(BitreeNode<myData> *node, int level);

public:
	Fomula();
	~Fomula();
	void SetFomula(string &str);//�����û�����Ĺ�ʽ

	void SetPostFomula();
	void SetTrueValue(vector<int> &value, int size);//�û��趨������ֵ
	
	string GetPostFomula()const;
	string GetFomula()const;
	void MakeBitree(void);//����������
	void Transfer(void);//��ꡱ��ʽת��Ϊ��ꡱ��ʽ
	bool FomulaCorrect(void);//����û�������ַ��������Ƿ�ƥ��
	void Print()const;//������ݳ�Ա��ֵ
	bool Calculate()const;//���㹫ʽ����ֵ
	void SetTrueValueForTest(vector<bool>&value);
	string GetBitreeStr();
};

