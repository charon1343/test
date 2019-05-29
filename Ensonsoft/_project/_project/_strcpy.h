#include<iostream>

using namespace std;

void ccopy(char** z,char** a){
	*z = *a;
}
void cccopy(char* z,char* a){
	z=a;
}
void mystrcpy(char* _z,char* _a){
	memset(_z,0,100);
	memcpy(_z,_a,100);
}
void mystrcpy(char* _z,int _asize,char* _a){
	memcpy(_z,_a,_asize);
}
