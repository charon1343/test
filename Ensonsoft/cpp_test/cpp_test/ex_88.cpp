//#include<iostream>
//#include<cmath>
//using namespace std;
//
//void printDivisor(int num);
//int division(int num);
//void printPerfect(int num);
//
//int main(){
//	cout<<"--완전수 찾기 2~10000--"<<endl;
//	int i=0;
//	for(i=2;i<10000;i++){
//		printPerfect(i);
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
//
//void printPerfect(int num){
//	if(division(num)==num){
//		cout<<"완전수"<<num<<endl;
//		printDivisor(num);
//	}
//}
//
//int division(int num){
//	int sum=1,i=0;
//	for(i=2;i<num;i++){
//		if(num%i==0){
//			sum+=i;
//		}
//	}
//	return sum;
//}
//
//void printDivisor(int num){
//	int i=0;
//	if(num==1){
//		cout<<"[1]"<<endl;
//		return;
//	}
//	cout<<"[1, ";
//	for(i=2;i<num;i++){
//		if(num%i==0){
//			cout<<i<<", ";
//		}
//	}
//	cout<<num<<"]"<<endl;
//}