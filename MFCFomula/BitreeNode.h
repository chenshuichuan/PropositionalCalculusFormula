#pragma once
#include "stdafx.h"
#include<iostream>
using std::nullptr_t;
//using namespace std;
template<typename Type>class BitreeNode//二叉树结点类
{
	
public:
	Type m_Item;              //数据域
	BitreeNode<Type> *m_Left;//左孩子
	BitreeNode<Type> *m_Right;//右孩子 
	BitreeNode<Type> *m_Parent;//父节点//为方便使用，添加了指向父节点的指针
    //构造函数，
	BitreeNode(Type item)
		:m_Item(item),m_Left(NULL),m_Right(NULL),m_Parent(NULL){};
	~BitreeNode(){};
	BitreeNode(BitreeNode<Type> * parent, Type &item)
		:m_Item(item), m_Left(NULL), m_Right(NULL), m_Parent(parent){};
	BitreeNode( Type &item, BitreeNode<Type> * left, BitreeNode<Type> * right,BitreeNode<Type> * parent)
		:m_Item(item), m_Left(left), m_Right(right), m_Parent(parent){};
	BitreeNode<Type>* &LeftChild(void)
	{
		return m_Left;
	};
	BitreeNode<Type>* &RightChild(void)
	{
		return m_Right;
	};
	BitreeNode<Type>* &Parent(void)
	{
		return m_Parent;
	};
	
	void SetItem(Type &item)//设置数据域
	{
		m_Item = item;
	};
	Type GetItem()const//获取数据
	{
		return m_Item;
	}

};

/*template<typename Type> class Bitree
{
private:
	BitreeNode<Type> *m_Root;//the root point of the bitree

public:
	Bitree();   //the constructor function of Bitree
	~Bitree();  //distructor function 
	void Print()const;//print the bitree in reversed order

};*/