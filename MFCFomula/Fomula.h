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
	Bitree m_Tree;//二叉树
	string m_Fomula;//用户输入公式
	string m_postFomula;//后缀表达式
	vector<string> m_varriable;//用于分开存储变量及运算符
	string m_BitreeStr;//二叉树字符串，将整个二叉树数据集合到字符串中

	vector<int> m_TrueValue;//真值栈，存储真值,变量赋值-1
	//将数组中的真值插入真值栈
	void SetTrueValue(vector<int>&);
	//根据构造好的二叉树递归调用计算结果
	bool Calculate(BitreeNode<myData> *ptr)const;
	//中序遍历二叉树
	void MidVisit(BitreeNode<myData> *node, int level);

public:
	Fomula();
	~Fomula();
	void SetFomula(string &str);//传入用户输入的公式

	void SetPostFomula();
	void SetTrueValue(vector<int> &value, int size);//用户设定变量真值
	
	string GetPostFomula()const;
	string GetFomula()const;
	void MakeBitree(void);//建立二叉树
	void Transfer(void);//中辍表达式转换为后辍表达式
	bool FomulaCorrect(void);//检查用户输入的字符串括号是否匹配
	void Print()const;//输出数据成员的值
	bool Calculate()const;//计算公式的真值
	void SetTrueValueForTest(vector<bool>&value);
	string GetBitreeStr();
};

