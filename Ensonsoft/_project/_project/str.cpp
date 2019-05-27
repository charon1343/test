#include"str.h"
void ccopy(char** z,char** a){
	*z = *a;
}
void mystrcpy(char* _z,char* _a){
	memset(_z,0,100);
	memcpy(_z,_a,100);
}
void mystrcpy(char* _z,int _asize,char* _a){
	memcpy(_z,_a,_asize);
}
void main(){
	char* a = "abcdefg";
	char* a1 = "cd";
	char* a2 = "ef";
//
//	char b[] = "abcde";
//	char b1[] = "cd";
//
//	char* c = "abc";
//	char c1 = 'b';
//	char* c2;
//
//	int d = 999;
//	char* d1="dddd";
//	char* d2="ddde";
//
	char z[100]="\0";
	char* _z=z;
//
//	int b2 = strcspn(b,b1);
//	cout<<b2<<endl;
//
//	c2 = strchr(c,c1);
//	cout<<c2<<endl;
//	
	//strcpy_s(z,a1);
	//cout<<"\n"<<z<<endl;
	//strcpy_s(z,10,a);
	//cout<<"\n"<<z<<endl;
	//strncpy(z,a1,1);
	//cout<<"\n"<<z<<endl;

	//mystrcpy(z,a1);
	//cout<<"\n"<<z<<endl;
	//mystrcpy(z,2,a2);
	//cout<<"\n"<<z<<endl;
	
	ccopy(&_z,&a);
	cout<<"\n"<<_z<<endl;

	ccopy(&_z,&a1);
	cout<<"\n"<<_z<<endl;

	ccopy(&_z,&a2);
	cout<<"\n"<<_z<<endl;
//	strcat(z,a1);
//	strncat(z,a2,1);
//	cout<<z<<endl;

//	d = strcmp(d1,d2);
//	int e = strncmp(d1,d2,4);
//	cout<<d<<endl;
//	cout<<e<<endl;
//
//	strcpy(z,"\0");
//	cout<<z<<endl;
//
//	
}