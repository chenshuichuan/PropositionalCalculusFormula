#pragma once
#include "stdafx.h"

#include"BitreeNode.h"
#include<string>
using std::string;
typedef string myData;

class Bitree//��������
{
private:
	//������ͷָ��
	BitreeNode<myData> *m_Root;
	//�����������Ϊvoid Print()const;����
	void Print(BitreeNode<myData> *node, int level)const;
	//ɾ����������Ϊvoid Destroy();����
	void Destroy(BitreeNode<myData> * &node);
public:
	Bitree();
	~Bitree();
	//��ӡnode�ڵ��������
	void Visit(BitreeNode<myData> *node)const;
	//�������������
	void Print()const; 
	void Destroy();
	void MakeBitree(myData &data, BitreeNode<myData> *&left,
		BitreeNode<myData> *&right, BitreeNode<myData> *&parent,bool sym);
	void MakeBitree(BitreeNode<myData> *&root);
    //�ж϶������Ƿ�Ϊ��
	bool IsEmpty()const;
	BitreeNode<myData> *GetRoot()const;
	BitreeNode<myData> *GetLeft(BitreeNode<myData> *)const;
	BitreeNode<myData> *GetRight(BitreeNode<myData> *)const;
};

