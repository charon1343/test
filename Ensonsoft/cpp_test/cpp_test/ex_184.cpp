//#include<cstdlib>
//#include<iostream>
//#include "ex_184.h"
//
//int coffee(int money,int coffemoney){
//	try{
//		if(money<coffemoney)
//			throw Exception("�߸��� �׼��� ���� �Ǿ����ϴ�.");
//		return money/coffemoney;
//	}catch(Exception& e){
//		cout<<"���� �ݾ� : "<<money<<endl;
//		cout<<e.what()<<endl;
//		return -1;
//	}
//}
//int can(int money) throw (Exception){
//	if(money<500)
//		throw Exception("�������� �� �� �����ϴ�.");
//	return money/500;
//}
//int main(){
//	int money = 300;
//	cout<<"�׼��� �Է��ϼ���(��:200)"<<endl;
//	cin>>money;
//	cout<<"\n====Ŀ�Ǹ� �� ��� ===="<<endl;
//	int cup = coffee(money,300);
//	if(cup>0){
//		cout<<cup<<"�� �غ�Ǿ����ϴ�."<<endl;
//	}
//
//	cout<<"\n======������� �� ��� ======="<<endl;
//	try{
//		cout<<can(money)<<"ĵ �غ�Ǿ����ϴ�."<<endl;
//	}catch(Exception& e){
//		cout<<"���� �ݾ� : "<<money<<endl;
//		cout<<e.what()<<endl;
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}