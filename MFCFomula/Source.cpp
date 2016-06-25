
#include"Stack.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include"Bitree.h"
#include"Header.h"
#include"Fomula.h"

int main()
{	
	char str;
	string sFomula="~(a123&bcd|ang&cnm)";          //storage the user's input
	vector<bool>value = { 1, 1, 1, 1, 1, 1, 1 ,1};
	//vector<bool>value = { 0, 0, 0, 0, 0, 0, 0, 0 };
	//vector<bool>value = { 1, 1, 1, 1, 1, 1, 1, 1 };
	while (true)
		try{
		Fomula myFomula;
		cout << "\n.................................................................."<<endl;
		cout << endl << endl << "\t\t\t\t计算命题演算公式" << endl << endl;
		cout << "\t\t\t &、|、~ 分别代表 与、或、非 " << endl;
		cout << "\n.................................................................."<<endl;

		cout << "\n\t请输入待求表达式:";
		//cin >> sFomula;
		cout<<"您输入的表达式为：";
		cout << sFomula << endl;
		cout<<"\n...................................................................."<<endl;
		cout<<"\n\t我们现在检测其括号匹配......\n"<<endl;
		myFomula.SetFomula(sFomula);
		if (myFomula.FomulaCorrect())
		{
			cout << "\t您输入的表达式括号匹配正确......" << endl;
			cout << "\t我们现在进行后缀表达式的转换......\n" << endl;
			
			myFomula.Transfer();
			myFomula.SetPostFomula();
			myFomula.MakeBitree();

			myFomula.Print();
			cout <<"二叉树：\n" <<myFomula.GetBitreeStr() << endl;;
			myFomula.SetTrueValueForTest(value);//for test 
			//myFomula.SetTrueValue();
			if (myFomula.Calculate())cout << "计算结果为:true" << endl;
			else cout << "计算结果为:false" << endl;
		}
		else
		{
			cout << "\t您输入的表达式括号不能正确匹配......" << endl;
		}
		cout << "whether continue?(y/n):";
		cin >> str;
		if (str != 'y')break;
	}
	catch (std::exception const &ex)
	{
		cerr << "exception accure:" << ex.what() << endl;
		cin >> str;
	}
	catch (...)
	{
		cout << "发生未知错误！" << endl;
		cin >> str;
	}
	
	return 0;
}