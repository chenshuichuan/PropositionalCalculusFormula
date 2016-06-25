//#pragma once
#ifndef STACK_H
#define STACK_H
#include "stdafx.h"
#include<vector>
#include<stdexcept>
template<typename Type>class Stack
{
public:
	Stack(){};
	~Stack(){};
	//push the item to the top of the vector 
	void Push(const Type &item);
	// pop the top item of vector 
	Type Pop(void);      
	//return the top item of the vector 
	Type Top(void)const;  
	//judge wether the Stack is empty ,empty return true else return false
	bool IsEmpty(void)const;

private:
	//the vector of the Stack  use for storage the element
	std::vector<Type> m_Items;
};
template<typename Type>
void Stack<Type>::Push(const Type &item)
{
	m_Items.push_back(item);
}

template<typename Type>
Type Stack<Type>::Pop(void)
{
	if (m_Items.empty())
		throw std::out_of_range("the Stack is empty!");
	Type temp = m_Items.back();
	m_Items.pop_back();
	return temp;
}

template<typename Type>
Type Stack<Type>::Top()const
{
	if (m_Items.empty())
		throw std::out_of_range("the Stack is empty!");
	return m_Items.back();
}

template<typename Type>
bool Stack<Type>::IsEmpty()const
{
	if (m_Items.empty())return true;
	else return false;
}

#endif