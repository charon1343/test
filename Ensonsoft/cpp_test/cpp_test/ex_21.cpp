//#include<iostream>
//#include<cstdlib>
//#include<cmath>
//
//#define BINARY	2
//#define OCT		8
//#define HEX		16
//
//using namespace std;
//
////2 <-->8���� 16����
//int main()
//{
//	char str[100];
//	int num=123;
//	cout<<num<<" 123(10):"<<num<<endl;
//	itoa(num,str,BINARY);
//	cout<<num<<"2���� :"<<str<<"(2)"<<endl;
//	itoa(num,str,OCT);
//	cout<<num<<"8���� :0"<<str<<endl;
//	itoa(num,str,HEX);
//	cout<<num<<"16���� :0x"<<str<<endl;
//
//	cout<<"12345678901234567890"<<endl;
//	for(int i=0;i<sizeof(int)*8;i++){
//		int temp=(int)(num/(int)pow(2.0,31-i));
//		cout<<temp;
//		num = (int)(num%(int)pow(2.0,31-i));
//	}
//	cout<<endl;
//	system("PAUSE");
//	return 0;
//}
