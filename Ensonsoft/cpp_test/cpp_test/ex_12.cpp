//#include<iostream>
//enum Dates{SUN, MON, TUE, WED, THU, FRI, SAT};
//
//using namespace std;
//int main(){
//	cout<<"오늘 요일을 입력하세요. "<<endl;
//	cout<<"SUN 0,MON 1,TUE 2,WED 3,THU 4,FRI 5,SAT 6"<<endl;
//	int today=0;
//	cin>>today;
//	cout<<"몇 일 후의 요일을 원하십니까? 입력하세요."<<endl;
//	int input=0;
//	cin>>input;
//	cout<<input<<"일 이후는 ";
//	switch((input+today)%7){
//	case SUN : cout<<"일요일"<<endl;break;
//	case MON : cout<<"월요일"<<endl;break;
//	case TUE : cout<<"화요일"<<endl;break;
//	case WED : cout<<"수요일"<<endl;break;
//	case THU : cout<<"목요일"<<endl;break;
//	case FRI : cout<<"금요일"<<endl;break;
//	case SAT : cout<<"토요일"<<endl;break;
//	}
//
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}