#pragma once
#include "stdafx.h"

#include"BitreeNode.h"
#include<string>
using std::string;
typedef string myData;

class Bitree//二叉树类
{
private:
	//二叉树头指针
	BitreeNode<myData> *m_Root;
	//输出二叉树，为void Print()const;调用
	void Print(BitreeNode<myData> *node, int level)const;
	//删除二叉树，为void Destroy();调用
	void Destroy(BitreeNode<myData> * &node);
public:
	Bitree();
	~Bitree();
	//打印node节点的数据域
	void Visit(BitreeNode<myData> *node)const;
	//后序遍历二叉树
	void Print()const; 
	void Destroy();
	void MakeBitree(myData &data, BitreeNode<myData> *&left,
		BitreeNode<myData> *&right, BitreeNode<myData> *&parent,bool sym);
	void MakeBitree(BitreeNode<myData> *&root);
    //判断二叉树是否为空
	bool IsEmpty()const;
	BitreeNode<myData> *GetRoot()const;
	BitreeNode<myData> *GetLeft(BitreeNode<myData> *)const;
	BitreeNode<myData> *GetRight(BitreeNode<myData> *)const;
};

