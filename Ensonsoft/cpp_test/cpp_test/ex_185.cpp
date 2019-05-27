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
//	cout<<"액수를 입력하세요(예:200)"<<endl;
//	cin>>money;
//	cout<<"\n==커피를 살 경우=="<<endl;
//	int cup =0;
//	try{
//		cup=coffee(money,300);
//		cout<<cup<<"잔 준비되었습니다."<<endl;
//	}catch(InsufficientException& e){
//		cout<<"구입에 실패했습니다"<<endl;
//		//cout<<e.what()<<endl;
//		e.printError();
//	}catch(WrongMoneyException& e){
//		cout<<"구입에 실패했습니다."<<endl;
//		//cout<<e.what()<<endl;
//		e.printError();
//	}
//	cout<<"\n==음료수를 살 경우=="<<endl;
//	try{
//		cout<<can(money)<<"캔 준비되었습니다."<<endl;
//	}catch(InsufficientException& e){
//		cout<<"구입에 실패했습니다."<<endl;
//		e.printError();
//	}catch(WrongMoneyException& e){
//		cout<<"구입에 실패했습니다."<<endl;
//		e.printError();
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
