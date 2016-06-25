#include "stdafx.h"

#include "Bitree.h"
#include<iostream>
using namespace std;
Bitree::Bitree() :m_Root(NULL)
{

}

Bitree::~Bitree()
{
}
bool Bitree::IsEmpty()const
{
	if (NULL == m_Root)return true;
	else return false;
}
void Bitree::Visit(BitreeNode<myData> *node)const
{
	cout << node->GetItem();
}
//从node节点开始向下打印二叉树，
void Bitree::Print(BitreeNode<myData> *node, int level)const
{
	if (node != NULL)
	{
		Print(node->RightChild(), level + 1);//递归调用
		if (level != 0)
		{
			for (int i = 0; i < 6 * (level - 1); i++)cout << " ";
			cout << "----";
		}
		Visit(node);
		cout << endl;
		Print(node->LeftChild(), level + 1);
	}
}
//打印整棵二叉树
void Bitree::Print(void)const
{
	Print(m_Root, 0);
}

void Bitree::Destroy(BitreeNode<myData> * &node)
{
	if (node != NULL && node->LeftChild() != NULL)
		Destroy(node->LeftChild());
	if (node != NULL && node->RightChild() != NULL)
		Destroy(node->RightChild());
	cout << node->GetItem() << " ";
	delete node;
}
void Bitree::Destroy()
{
	Destroy(m_Root);
}
void Bitree::MakeBitree(myData &data, BitreeNode<myData> *&left,
	BitreeNode<myData> *&right, BitreeNode<myData> *&parent, bool sym)
{
	m_Root = new BitreeNode<myData>(data, left, right, parent);
	if(left !=NULL)left->Parent() = m_Root;
	if (right != NULL)right->Parent() = m_Root;
	if (NULL != parent && false == sym)parent->LeftChild() = m_Root;
	else if (NULL != parent && true == sym)parent->LeftChild() = m_Root;
}
void Bitree::MakeBitree(BitreeNode<myData> *&root)
{
	m_Root = root;
}
BitreeNode<myData> * Bitree::GetRoot()const
{
	return m_Root;
}
BitreeNode<myData> * Bitree::GetLeft(BitreeNode<myData> *root)const
{
	if (NULL!=root)return root->LeftChild();
	else return NULL;
}
BitreeNode<myData> * Bitree::GetRight(BitreeNode<myData> *root)const
{
	if (NULL != root)return root->RightChild();
	else return NULL;
}
