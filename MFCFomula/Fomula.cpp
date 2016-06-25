

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
	vector<int> value(m_varriable.size());//临时存储真值
	std::cout<<"\n\t请为变量赋值<0:false or 1:true>\n\n";
	int num = 0;
	for (size_t i = 0; i < m_varriable.size(); i++)
	{
		int flag = 0; size_t j = 0;
		//不是运算符，才赋值
		if (m_varriable[i] != "~"&&m_varriable[i] != "&"&&m_varriable[i] != "|")
		{
			for (j = 0; j < i; j++)
			{
				if (m_varriable[i] == m_varriable[j]) 
				{
					flag = 1; break;// /有重复变量时flag为1，且找到第一个重复变量[j]
				}            
			}

			if (flag == 0)
			{ ///给变量赋真值0或1
				int symble = -1;
				//std::cout << "\t请设定上述待求表达式中的变量" << m_varriable[i]<<"的真值(0 or 1?)：\n\t";
				if (num >= Inputvalue.size())throw("error !");
				symble=Inputvalue[num++];
				if (0 == symble)value[i]=0;
				else value[i]=1;
			}
			else
			{
				value[i] = value[j];   //把重复出现的变量都用第一次的值赋值
			}
		}
		else value[i]=-1;
	}
	SetTrueValue(value);//将真值压入真值栈
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
	m_postFomula = string(m_postFomula, 0, n);//截尾处理
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

//判断输入表达式是否有错误
bool Fomula::FomulaCorrect(void)
{
	int i = 0; 
	Stack<char> m_Stack;   //栈

	while (m_Fomula[i])   //表达式没读完时，执行'while'循环
	{

#ifdef MYDEBUG
		std::cout << m_Fomula[i];
#endif
		//遇到左括号'('将其进栈
		if (m_Fomula[i] == '(')m_Stack.Push(m_Fomula[i]);

		//栈顶元素为'('且当前元素为')'时，出栈，继续读下面的字符
		else if (m_Fomula[i] == ')'&&!m_Stack.IsEmpty() && (m_Stack.Top() == '('))m_Stack.Pop();

		//栈顶元素不为'('且当前元素为')'时，输出'左右括号不匹配'，退出重新输入
		else if (m_Fomula[i] == ')'&&!m_Stack.IsEmpty() && (m_Stack.Top() != '('))
			return false;

		//当前元素为')'但是堆栈已空时候，输出'右括号多于左括号'，退出程序重新输入
		else if ((m_Fomula[i] == ')') && m_Stack.IsEmpty())
			return false;
		i++;
	}
	if (!m_Stack.IsEmpty())   //此时若堆栈非空，则输出'左括号多于右括号'，退出程序重新输入
		return false;
	else return true;
}

//将用户输入表达式转化为后缀表达式
void Fomula::Transfer()
{
	int k = 0;
	Stack<char> m_Stack;                //字符栈
	string varriable(100,'0');         //在检查中辍表达式时存储变量
	char character;                    //获取当前栈顶的字符
	string tempFomula = m_Fomula + "#";//加入#符号方便判断算法的结束
	size_t n = tempFomula.size();
	m_Stack.Push('#');            //栈底加入#符号方便判断算法的结束
	for (size_t i = 0; i<n; i++)
	{  
#ifdef MYDEBUG
		std::cout << tempFomula[i];
#endif
		//对运算符的解读
		if (tempFomula[i] == '~' || tempFomula[i] == '|' || tempFomula[i] == '&' ||
			tempFomula[i] == '(' || tempFomula[i] == ')' || tempFomula[i] == '#')
		{
			while (tempFomula[i] == '~' || tempFomula[i] == '|' || tempFomula[i] == '&' ||
				tempFomula[i] == '(' || tempFomula[i] == ')' || tempFomula[i] == '#')
			{
				character = m_Stack.Top();            //获取一个栈顶字符
				if (character == '#'&&tempFomula[i] == '#')return;    //此时堆栈和当前都为‘#’时结束算法
				else if
					((character == '#'&&tempFomula[i] != '#') || (character == '|'&&tempFomula[i] == '~') || (character == '|'&&tempFomula[i] == '&')
					|| (character == '|'&&tempFomula[i] == '(') || (character == '&'&&tempFomula[i] == '~') || (character == '&'&&tempFomula[i] == '(')
					|| (character == '~'&&tempFomula[i] == '(') || (character == '('&&tempFomula[i] != ')'))
				{
					m_Stack.Push(tempFomula[i]);     //当中缀表达式当前运算符优先级较高时，进栈
					break;
				}
				else if (character == '('&&tempFomula[i] == ')')    
				{
					m_Stack.Pop();//'('和')'相遇时，将'('退栈，接着读下面的
					break;
				}
				else
				{
					k=0;//将变量开始标志置为0
					m_Stack.Pop();  //当栈顶元素优先级较高时，退栈
					varriable[k++] = character;
					m_varriable.push_back(string(varriable, 0, k));//将字符存入容器
					continue;
				}
			}//while
			continue;
		}

		if (tempFomula[i] != '~' && tempFomula[i] != '|' && tempFomula[i] != '&'
			&& tempFomula[i] != '(' && tempFomula[i] != ')' &&tempFomula[i] != '#')

		{
			k = 0;//表示一个变量的开始
			while (tempFomula[i] != '~' && tempFomula[i] != '|' && tempFomula[i] != '&'
				&& tempFomula[i] != '(' && tempFomula[i] != ')' &&tempFomula[i] != '#')
			{
				varriable[k++] = tempFomula[i];
				i++;
			}
			i--;//因为在上面while循环有了i++，for循环也有i++
			m_varriable.push_back(string(varriable, 0, k));//变量读完，存入容器中
		}
	}
	return ;
}

//从叶节点开始构造二叉树
void Fomula::MakeBitree(void)
{
	BitreeNode<myData> *p, *q, *o;
	Stack< BitreeNode<myData>* > tempStack;
	size_t n = m_varriable.size();
	for (size_t i = 0; i<n; i++)
	{
		p = new BitreeNode<myData>(m_varriable[i]);  //初始化左右子树以及双亲指针
		string str = m_varriable[i];            //获取变量及运算符存储容器中的一个变量或运算符
		if ( "~"== str) //如果是“~”
		{
			q = tempStack.Pop();
			p->m_Right = q;       //将弹出后的结点作为右孩子
			q->m_Parent = p;
			tempStack.Push(p);
		}
		else if ("|"== str ||  "&"== str)
		{
			q = tempStack.Pop();     //弹出q作为右孩子
			o = tempStack.Pop();      //弹出0作为左孩子
			q->m_Parent= p;
			o->m_Parent= p;
			p->m_Left = o;
			p->m_Right = q;
			tempStack.Push( p);     //根结点入栈
		}
		else     //如果是变量，直接入栈
		{
			tempStack.Push(p);
		}
	}
	p= tempStack.Pop();
	m_Tree.MakeBitree(p);         //弹出构造好的二叉数的根结点指针，并返回
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
		return Calculate(ptr);//返回真值，计算结果
	}
}

//根据构造好的二叉树计算真值
bool Fomula::Calculate(BitreeNode<myData> *ptr)const
{
	bool leftValue=true, rightValue=true;

	if (NULL != ptr->LeftChild())
		leftValue = Calculate(ptr->LeftChild());//后序遍历二叉树
	if (NULL != ptr->RightChild())
		rightValue = Calculate(ptr->RightChild());

	if ("~" == ptr->GetItem())         //遇到'~'将值置反
	{
		if (false == rightValue) return true;
		if (true == rightValue) return false;
	}
	else if ("&" == ptr->GetItem())       //遇到'&'只有两个都为真时才为真
	{
		if (true == leftValue && true == rightValue) return true;
		else return false;
	}
	else if ("|" == ptr->GetItem())            //遇到'|'只有两个都为假时才为假
	{
		if (false == leftValue && false == rightValue) return false;
		else return true;
	}
	else
	{
		//当该结点数据域为变量时
		size_t i = 0;
		for (; i < m_TrueValue.size(); i++)
		{
			if (m_varriable[i] == ptr->GetItem())break;
		}
		if (m_TrueValue[i]==1)return true; //直接返回该变量的真值
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

//中序遍历二叉树，将二叉树集合到string字符串中
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