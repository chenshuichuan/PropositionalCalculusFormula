
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
		cout << endl << endl << "\t\t\t\t�����������㹫ʽ" << endl << endl;
		cout << "\t\t\t &��|��~ �ֱ���� �롢�򡢷� " << endl;
		cout << "\n.................................................................."<<endl;

		cout << "\n\t�����������ʽ:";
		//cin >> sFomula;
		cout<<"������ı��ʽΪ��";
		cout << sFomula << endl;
		cout<<"\n...................................................................."<<endl;
		cout<<"\n\t�������ڼ��������ƥ��......\n"<<endl;
		myFomula.SetFomula(sFomula);
		if (myFomula.FomulaCorrect())
		{
			cout << "\t������ı��ʽ����ƥ����ȷ......" << endl;
			cout << "\t�������ڽ��к�׺���ʽ��ת��......\n" << endl;
			
			myFomula.Transfer();
			myFomula.SetPostFomula();
			myFomula.MakeBitree();

			myFomula.Print();
			cout <<"��������\n" <<myFomula.GetBitreeStr() << endl;;
			myFomula.SetTrueValueForTest(value);//for test 
			//myFomula.SetTrueValue();
			if (myFomula.Calculate())cout << "������Ϊ:true" << endl;
			else cout << "������Ϊ:false" << endl;
		}
		else
		{
			cout << "\t������ı��ʽ���Ų�����ȷƥ��......" << endl;
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
		cout << "����δ֪����" << endl;
		cin >> str;
	}
	
	return 0;
}