#include<iostream>

using namespace std;

void Mystrcpy(char* z,char* a){
	char* mz = z;
	for(int i=0;i<100;i++,z++){
		*z='\0';
	}
	z = mz;
	for(int i=0;i<strlen(a);i++,z++){
		*z+i;
		*z=*(a+i);
	}
}
void Mystrcpy(char* z,char* a,int s){
	for(int i=0;i<s;i++,z++){
		*z+i;
		*z=*(a+i);
	}
}

void main(){
	char* a = "ccc333";
	char* a1 = "bb22";
	char* a2 = "a1";
	char z[100]="\0";



	cout<<"---------------¿øº»-------------"<<endl;
	strcpy_s(z,a);
	cout<<"\n"<<z<<endl;
	strcpy_s(z,a1);
	cout<<"\n"<<z<<endl;
	strncpy(z,a2,2);
	cout<<"\n"<<z<<endl;

	cout<<"---------------Mystrcpy-------------"<<endl;
	Mystrcpy(z,a); 
	cout<<"\n"<<z<<endl;
	Mystrcpy(z,a1);
	cout<<"\n"<<z<<endl;
	Mystrcpy(z,a2,2);
	cout<<"\n"<<z<<endl;
}