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
//		cout<<"1���� �ݾ�:"<<_money<<endl;
//		cout<<"1�߸��� �׼��� ���� �Ǿ����ϴ�."<<endl;
//		return -1;
//	}
//}
//int coffee(int money,int coffemoney){
//	try{
//		if(money<coffemoney) throw money;
//		return money/coffemoney;
//	}
//	catch(int _money){
//		cout<<"2���� �ݾ�:"<<_money<<endl;
//		cout<<"2�߸��� �׼��� ���� �Ǿ����ϴ�."<<endl;
//		return -1;
//	}
//}
//int main(){
//
//	int money = 300;
//	cout<<"�׼��� �Է��ϼ���(��:200)"<<endl;
//	cin>>money;
//	//int cup = coffee(money,300);
//	int cup = coffee(money);
//	if(cup>0){
//		cout<<cup<<"�� �غ�Ǿ����ϴ�."<<endl;
//	}else{
//		cout<<"3���� �ݾ� : "<<money<<endl;
//		cout<<"3�߸��� �׼��� ���� �Ǿ����ϴ�."<<endl;
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}