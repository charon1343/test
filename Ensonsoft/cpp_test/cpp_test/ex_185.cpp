//#include<cstdlib>
//#include<iostream>
//#include"ex_185.h"
//#include"ex_185_1.h"
//using namespace std;
//
////int coffee(int money=0,int coffemoney=200)
//int coffee(int money=0,int coffemoney=200)
//	throw(InsufficientException,WrongMoneyException){
//		if(money<=0)
//			throw WrongMoneyException(money);
//		if(money<coffemoney)
//			throw InsufficientException(coffemoney-money);
//		return money/coffemoney;
//}
////int can(int money){
//int can(int money=0,int canmoney=500)
//	throw(InsufficientException,WrongMoneyException){
//		if(money<=0)
//			throw WrongMoneyException(money);
//		if(money<canmoney)
//			throw InsufficientException(canmoney-money);
//		return money/canmoney;
//}
//
//int main(){
//	int money = 0;
//	cout<<"�׼��� �Է��ϼ���(��:200)"<<endl;
//	cin>>money;
//	cout<<"\n==Ŀ�Ǹ� �� ���=="<<endl;
//	int cup =0;
//	try{
//		cup=coffee(money,300);
//		cout<<cup<<"�� �غ�Ǿ����ϴ�."<<endl;
//	}catch(InsufficientException& e){
//		cout<<"���Կ� �����߽��ϴ�"<<endl;
//		//cout<<e.what()<<endl;
//		e.printError();
//	}catch(WrongMoneyException& e){
//		cout<<"���Կ� �����߽��ϴ�."<<endl;
//		//cout<<e.what()<<endl;
//		e.printError();
//	}
//	cout<<"\n==������� �� ���=="<<endl;
//	try{
//		cout<<can(money)<<"ĵ �غ�Ǿ����ϴ�."<<endl;
//	}catch(InsufficientException& e){
//		cout<<"���Կ� �����߽��ϴ�."<<endl;
//		e.printError();
//	}catch(WrongMoneyException& e){
//		cout<<"���Կ� �����߽��ϴ�."<<endl;
//		e.printError();
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
