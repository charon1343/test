//#include<iostream>
//using namespace std;
//
//void ccopy(char** z,char** a){
//	*z = *a;
//}
//void cccopy(char* z,char* a){
//	z=a;
//}
//void mystrcpy(char* _z,char* _a){
//	memset(_z,0,100);
//	memcpy(_z,_a,100);
//}
//void mystrcpy(char* _z,int _asize,char* _a){
//	memcpy(_z,_a,_asize);
//}
//
//
//void main(){
//	char* a = "abc123";
//	char* a1 = "cd";
//	char* a2 = "ef";
//	char z[100]="\0";
//	char* _z=z;
//
//	cout<<"---------------원본-------------"<<endl;
//	strcpy_s(z,a);
//	cout<<"\n"<<z<<endl;
//	strcpy_s(z,10,a1);
//	cout<<"\n"<<z<<endl;
//	//strncpy(z,a2,1);
//	//cout<<"\n"<<z<<endl;
//	cout<<"---------------mem사용한 정의-------------"<<endl;
//	mystrcpy(z,a);
//	cout<<"\n"<<z<<endl;
//	mystrcpy(z,2,a1); 
//	cout<<"\n"<<z<<endl;
//	cout<<"---------------2중 포인터 이용 정의-------------"<<endl;
//	ccopy(&_z,&a);
//	cout<<"\n"<<_z<<endl;
//
//	ccopy(&_z,&a1);
//	cout<<"\n"<<_z<<endl;
//
//	ccopy(&_z,&a2);
//	cout<<"\n"<<_z<<endl;
//	cout<<"---------------포인터 이용 정의-------------"<<endl;
//	cccopy(_z,a);
//	cout<<"\n"<<_z<<endl;	//함수가 반영되지 않음
//
//	cout<<"\n---------------strcspn-------------"<<endl;
//	char b[] = "abcde";
//	char b1[] = "cd";
//	int b2 = strcspn(b,b1);
//	cout<<b2<<endl;
//
//	cout<<"\n---------------strchr-------------"<<endl;
//	char* c = "abc";
//	char c1 = 'c';
//	char* c2;
//	c2 = strchr(c,c1);
//	cout<<c2<<endl;
//	
//	/*char b[] = "abcde";
//	char b1[] = "cd";
//
//	int b2 = strcspn(b,b1);
//	cout<<b2<<endl;*/
//	
//
//	cout<<"\n---------------strcat-------------"<<endl;
//	strcat(z,a1);
//	strncat(z,a2,1);
//	cout<<z<<endl;
//
//	cout<<"\n---------------strcmp-------------"<<endl;
//	int d = 999;
//	char* d1="dddd";
//	char* d2="ddde";
//	d = strcmp(d1,d2);
//	int e = strncmp(d1,d2,3);
//	cout<<d<<endl;
//	cout<<e<<endl;
//
//	strcpy(z,"\0");
//	cout<<z<<endl;
//
//	
//}