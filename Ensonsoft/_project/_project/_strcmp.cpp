//#include<iostream>
//using namespace std;
//int Mystrcmp(char* d1,char* d2){
//
//	for(int i=0;i<strlen(d1);i++){
//		if(*(d1+i)==*(d2+i))
//			continue;
//		else if(*(d1+i)>*(d2+i))
//			return 1;
//		else if(*(d1+i)<*(d2+i))
//			return -1;
//	}
//	if(strlen(d1)<strlen(d2))
//		return -1;
//	return 0;
//
//}
//
//
//void main(){
//	cout<<"\n---------------strcmp-------------"<<endl;
//	int d = 999;
//	char* d1="ddddab";
//	char* d2="ddddac";
//	d = strcmp(d1,d2);
//	cout<<d<<endl;
//	cout<<"\n---------------strncmp-------------"<<endl;
//	int e = strncmp(d1,d2,3);
//	cout<<e<<endl;
//	cout<<"\n---------------Mystrcmp-------------"<<endl;
//	int f = Mystrcmp(d1,d2);
//	cout<<f<<endl;
//}