//#include<iostream>
//using namespace std;
//void mystrcat(char* z,char* a){
//	if(*z==0)
//	{
//	for(int i=0;i<strlen(a);i++,z++){
//		*z = *(a+i);
//		}
//		*z='\0';
//	}
//	else{
//		char* mz = z;
//		char* ma = a;
//		mz = mz+strlen(mz);
//		for(int i=0;i<strlen(a);i++,mz++){
//		*mz = *(ma+i);
//		}
//		*mz='\0';
//	}
//}
//void main(){
//	char* a = "aaa";
//	char* a1 = "bb";
//	char* a2 = "cc";
//	char* a3 = "dd";
//	char z[100]="\0";
//	cout<<"---------strcat---------------"<<endl;
//	strcat_s(z,a);
//	cout<<z<<endl;
//	cout<<"---------strcat---------------"<<endl;
//	strcat_s(z,a1);
//	cout<<z<<endl;
//	cout<<"---------Mystrcat---------------"<<endl;
//	mystrcat(z,a2);
//	cout<<z<<endl;
//	cout<<"---------Mystrcat---------------"<<endl;
//	mystrcat(z,a3);
//	cout<<z<<endl;
//	cout<<"---------z---------------"<<endl;
//	cout<<z<<endl;
//}