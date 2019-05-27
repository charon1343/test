//#include<cstdlib>
//#include<cstring>
//#include<iostream>
//using std::cout;
//using std::endl;
//using std::cin;
//int coffee(int money){
//	try{
//		if(money<200) throw money;
//		return money/200;
//	}
//	catch(int _money){
//		cout<<"1투입 금액:"<<_money<<endl;
//		cout<<"1잘못된 액수가 투입 되었습니다."<<endl;
//		return -1;
//	}
//}
//int coffee(int money,int coffemoney){
//	try{
//		if(money<coffemoney) throw money;
//		return money/coffemoney;
//	}
//	catch(int _money){
//		cout<<"2투입 금액:"<<_money<<endl;
//		cout<<"2잘못된 액수가 투입 되었습니다."<<endl;
//		return -1;
//	}
//}
//int main(){
//
//	int money = 300;
//	cout<<"액수를 입력하세요(예:200)"<<endl;
//	cin>>money;
//	//int cup = coffee(money,300);
//	int cup = coffee(money);
//	if(cup>0){
//		cout<<cup<<"잔 준비되었습니다."<<endl;
//	}else{
//		cout<<"3투입 금액 : "<<money<<endl;
//		cout<<"3잘못된 액수가 투입 되었습니다."<<endl;
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}