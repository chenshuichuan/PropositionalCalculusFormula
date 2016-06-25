

#include "stdafx.h"
#include "Fomula.h"
//#define MYDEBUG

Fomula::Fomula()
{
	m_BitreeStr = " ";
}


Fomula::~Fomula()
{
}
void Fomula::SetFomula(string &str)
{
	m_Fomula = str;
}
void Fomula::SetTrueValue(vector<int> &value)
{
	if (!m_TrueValue.empty())m_TrueValue.clear();
	for (size_t i = 0; i < value.size(); i++)
		m_TrueValue.push_back(value[i]);
}
void Fomula::SetTrueValue(vector<int> &Inputvalue,int size)
{
	vector<int> value(m_varriable.size());//��ʱ�洢��ֵ
	std::cout<<"\n\t��Ϊ������ֵ<0:false or 1:true>\n\n";
	int num = 0;
	for (size_t i = 0; i < m_varriable.size(); i++)
	{
		int flag = 0; size_t j = 0;
		//������������Ÿ�ֵ
		if (m_varriable[i] != "~"&&m_varriable[i] != "&"&&m_varriable[i] != "|")
		{
			for (j = 0; j < i; j++)
			{
				if (m_varriable[i] == m_varriable[j]) 
				{
					flag = 1; break;// /���ظ�����ʱflagΪ1�����ҵ���һ���ظ�����[j]
				}            
			}

			if (flag == 0)
			{ ///����������ֵ0��1
				int symble = -1;
				//std::cout << "\t���趨����������ʽ�еı���" << m_varriable[i]<<"����ֵ(0 or 1?)��\n\t";
				if (num >= Inputvalue.size())throw("error !");
				symble=Inputvalue[num++];
				if (0 == symble)value[i]=0;
				else value[i]=1;
			}
			else
			{
				value[i] = value[j];   //���ظ����ֵı������õ�һ�ε�ֵ��ֵ
			}
		}
		else value[i]=-1;
	}
	SetTrueValue(value);//����ֵѹ����ֵջ
}
string Fomula::GetFomula()const
{
	return m_Fomula;
}
string Fomula::GetPostFomula()const
{
	return m_postFomula;
}



void Fomula::SetPostFomula()
{
	m_postFomula = m_Fomula+"          ";
	int n = 0;
	for (size_t i = 0; i < m_varriable.size(); i++)
	{
		for (size_t j = 0; j < m_varriable[i].size(); j++)
			m_postFomula[n++] = m_varriable[i][j];
		m_postFomula[n++] = ' ';
	}
	m_postFomula = string(m_postFomula, 0, n);//��β����
}
void Fomula::Print()const
{
	using std::cout;
	using std::endl;
	cout << "m_Fomula:" << m_Fomula << endl;
	
	cout << "m_postFomula:" << m_postFomula << endl;
	//while (!m_Stack.IsEmpty())cout << m_Stack.Pop() << endl;
	for (size_t i = 0; i < m_varriable.size(); i++)cout << m_varriable[i] <<"\t";
	cout << endl;
	m_Tree.Print();
}

//�ж�������ʽ�Ƿ��д���
bool Fomula::FomulaCorrect(void)
{
	int i = 0; 
	Stack<char> m_Stack;   //ջ

	while (m_Fomula[i])   //���ʽû����ʱ��ִ��'while'ѭ��
	{

#ifdef MYDEBUG
		std::cout << m_Fomula[i];
#endif
		//����������'('�����ջ
		if (m_Fomula[i] == '(')m_Stack.Push(m_Fomula[i]);

		//ջ��Ԫ��Ϊ'('�ҵ�ǰԪ��Ϊ')'ʱ����ջ��������������ַ�
		else if (m_Fomula[i] == ')'&&!m_Stack.IsEmpty() && (m_Stack.Top() == '('))m_Stack.Pop();

		//ջ��Ԫ�ز�Ϊ'('�ҵ�ǰԪ��Ϊ')'ʱ�����'�������Ų�ƥ��'���˳���������
		else if (m_Fomula[i] == ')'&&!m_Stack.IsEmpty() && (m_Stack.Top() != '('))
			return false;

		//��ǰԪ��Ϊ')'���Ƕ�ջ�ѿ�ʱ�����'�����Ŷ���������'���˳�������������
		else if ((m_Fomula[i] == ')') && m_Stack.IsEmpty())
			return false;
		i++;
	}
	if (!m_Stack.IsEmpty())   //��ʱ����ջ�ǿգ������'�����Ŷ���������'���˳�������������
		return false;
	else return true;
}

//���û�������ʽת��Ϊ��׺���ʽ
void Fomula::Transfer()
{
	int k = 0;
	Stack<char> m_Stack;                //�ַ�ջ
	string varriable(100,'0');         //�ڼ����ꡱ��ʽʱ�洢����
	char character;                    //��ȡ��ǰջ�����ַ�
	string tempFomula = m_Fomula + "#";//����#���ŷ����ж��㷨�Ľ���
	size_t n = tempFomula.size();
	m_Stack.Push('#');            //ջ�׼���#���ŷ����ж��㷨�Ľ���
	for (size_t i = 0; i<n; i++)
	{  
#ifdef MYDEBUG
		std::cout << tempFomula[i];
#endif
		//��������Ľ��
		if (tempFomula[i] == '~' || tempFomula[i] == '|' || tempFomula[i] == '&' ||
			tempFomula[i] == '(' || tempFomula[i] == ')' || tempFomula[i] == '#')
		{
			while (tempFomula[i] == '~' || tempFomula[i] == '|' || tempFomula[i] == '&' ||
				tempFomula[i] == '(' || tempFomula[i] == ')' || tempFomula[i] == '#')
			{
				character = m_Stack.Top();            //��ȡһ��ջ���ַ�
				if (character == '#'&&tempFomula[i] == '#')return;    //��ʱ��ջ�͵�ǰ��Ϊ��#��ʱ�����㷨
				else if
					((character == '#'&&tempFomula[i] != '#') || (character == '|'&&tempFomula[i] == '~') || (character == '|'&&tempFomula[i] == '&')
					|| (character == '|'&&tempFomula[i] == '(') || (character == '&'&&tempFomula[i] == '~') || (character == '&'&&tempFomula[i] == '(')
					|| (character == '~'&&tempFomula[i] == '(') || (character == '('&&tempFomula[i] != ')'))
				{
					m_Stack.Push(tempFomula[i]);     //����׺���ʽ��ǰ��������ȼ��ϸ�ʱ����ջ
					break;
				}
				else if (character == '('&&tempFomula[i] == ')')    
				{
					m_Stack.Pop();//'('��')'����ʱ����'('��ջ�����Ŷ������
					break;
				}
				else
				{
					k=0;//��������ʼ��־��Ϊ0
					m_Stack.Pop();  //��ջ��Ԫ�����ȼ��ϸ�ʱ����ջ
					varriable[k++] = character;
					m_varriable.push_back(string(varriable, 0, k));//���ַ���������
					continue;
				}
			}//while
			continue;
		}

		if (tempFomula[i] != '~' && tempFomula[i] != '|' && tempFomula[i] != '&'
			&& tempFomula[i] != '(' && tempFomula[i] != ')' &&tempFomula[i] != '#')

		{
			k = 0;//��ʾһ�������Ŀ�ʼ
			while (tempFomula[i] != '~' && tempFomula[i] != '|' && tempFomula[i] != '&'
				&& tempFomula[i] != '(' && tempFomula[i] != ')' &&tempFomula[i] != '#')
			{
				varriable[k++] = tempFomula[i];
				i++;
			}
			i--;//��Ϊ������whileѭ������i++��forѭ��Ҳ��i++
			m_varriable.push_back(string(varriable, 0, k));//�������꣬����������
		}
	}
	return ;
}

//��Ҷ�ڵ㿪ʼ���������
void Fomula::MakeBitree(void)
{
	BitreeNode<myData> *p, *q, *o;
	Stack< BitreeNode<myData>* > tempStack;
	size_t n = m_varriable.size();
	for (size_t i = 0; i<n; i++)
	{
		p = new BitreeNode<myData>(m_varriable[i]);  //��ʼ�����������Լ�˫��ָ��
		string str = m_varriable[i];            //��ȡ������������洢�����е�һ�������������
		if ( "~"== str) //����ǡ�~��
		{
			q = tempStack.Pop();
			p->m_Right = q;       //��������Ľ����Ϊ�Һ���
			q->m_Parent = p;
			tempStack.Push(p);
		}
		else if ("|"== str ||  "&"== str)
		{
			q = tempStack.Pop();     //����q��Ϊ�Һ���
			o = tempStack.Pop();      //����0��Ϊ����
			q->m_Parent= p;
			o->m_Parent= p;
			p->m_Left = o;
			p->m_Right = q;
			tempStack.Push( p);     //�������ջ
		}
		else     //����Ǳ�����ֱ����ջ
		{
			tempStack.Push(p);
		}
	}
	p= tempStack.Pop();
	m_Tree.MakeBitree(p);         //��������õĶ������ĸ����ָ�룬������
	return ;
}

bool Fomula::Calculate()const
{
	if (m_Tree.IsEmpty())
	{
		throw ("the Bitree is empty !");
		//return false;
	}
	else
	{
		BitreeNode<myData> *ptr = m_Tree.GetRoot();
		return Calculate(ptr);//������ֵ��������
	}
}

//���ݹ���õĶ�����������ֵ
bool Fomula::Calculate(BitreeNode<myData> *ptr)const
{
	bool leftValue=true, rightValue=true;

	if (NULL != ptr->LeftChild())
		leftValue = Calculate(ptr->LeftChild());//�������������
	if (NULL != ptr->RightChild())
		rightValue = Calculate(ptr->RightChild());

	if ("~" == ptr->GetItem())         //����'~'��ֵ�÷�
	{
		if (false == rightValue) return true;
		if (true == rightValue) return false;
	}
	else if ("&" == ptr->GetItem())       //����'&'ֻ��������Ϊ��ʱ��Ϊ��
	{
		if (true == leftValue && true == rightValue) return true;
		else return false;
	}
	else if ("|" == ptr->GetItem())            //����'|'ֻ��������Ϊ��ʱ��Ϊ��
	{
		if (false == leftValue && false == rightValue) return false;
		else return true;
	}
	else
	{
		//���ý��������Ϊ����ʱ
		size_t i = 0;
		for (; i < m_TrueValue.size(); i++)
		{
			if (m_varriable[i] == ptr->GetItem())break;
		}
		if (m_TrueValue[i]==1)return true; //ֱ�ӷ��ظñ�������ֵ
		else return false;
	}
#ifdef MYDEBUG
	std::cout << "Calculate error!" << std::endl;
#endif
	return false;
}
void Fomula::SetTrueValueForTest(vector<bool>&value)
{
	if (!m_TrueValue.empty())m_TrueValue.clear();
	for (size_t i = 0; i < value.size(); i++)
		m_TrueValue.push_back(value[i]);
}

//��������������������������ϵ�string�ַ�����
void Fomula::MidVisit(BitreeNode<myData> *node, int level)
{
	if (node != NULL)
	{
		MidVisit(node->RightChild(), level + 1);
		if (level != 0)
		{
			for (int i = 0; i < 6 * (level - 1); i++)m_BitreeStr+=" ";
			m_BitreeStr+="---";
		}
		m_BitreeStr+= node->GetItem();
		m_BitreeStr+="#";
		MidVisit(node->LeftChild(), level + 1);
	}
}
string Fomula::GetBitreeStr()
{
	MidVisit(m_Tree.GetRoot(),0);
	return m_BitreeStr;
}