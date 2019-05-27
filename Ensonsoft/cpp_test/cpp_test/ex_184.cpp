//#include<cstdlib>
//#include<iostream>
//#include "ex_184.h"
//
//int coffee(int money,int coffemoney){
//	try{
//		if(money<coffemoney)
//			throw Exception("잘못된 액수가 투입 되었습니다.");
//		return money/coffemoney;
//	}catch(Exception& e){
//		cout<<"투입 금액 : "<<money<<endl;
//		cout<<e.what()<<endl;
//		return -1;
//	}
//}
//int can(int money) throw (Exception){
//	if(money<500)
//		throw Exception("음류수는 살 수 없습니다.");
//	return money/500;
//}
//int main(){
//	int money = 300;
//	cout<<"액수를 입력하세요(예:200)"<<endl;
//	cin>>money;
//	cout<<"\n====커피를 살 경우 ===="<<endl;
//	int cup = coffee(money,300);
//	if(cup>0){
//		cout<<cup<<"잔 준비되었습니다."<<endl;
//	}
//
//	cout<<"\n======음료수를 살 경우 ======="<<endl;
//	try{
//		cout<<can(money)<<"캔 준비되었습니다."<<endl;
//	}catch(Exception& e){
//		cout<<"투입 금액 : "<<money<<endl;
//		cout<<e.what()<<endl;
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}