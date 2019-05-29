//#include<iostream>
//using namespace std;
//void mystrcat(char** z,char** a){
//	if(**z==0)
//	{
//	//char* z1 = *z;
//	//char z2 = *z1;
//	//char* a1 = *a ;
//	//char a2 = *a1;
//	*z=*a;
//	}
//	else{
//		char* mz = *z;
//		char* ma = *a;
//		char mma = **a;
//		char mmz = **z;
//		mz = mz+strlen(mz);
//		**z=**a;
//
//		//**z = **a;
//		//**z=**a;
//			
//		
//		/*char* z1 = *z;
//		char z2 = *z1;
//		char* a1 = *a ;
//		char a2 = *a1;
//		cout<<z2<<endl;
//		cout<<a2<<endl;*/
//	}
//		/*strlen(*z);*/
//	
//	//cout<<z<<"\n"<<endl;
//	//cout<<z1<<"\n"<<endl;
//	//cout<<z2<<"\n"<<endl;
//	//cout<<"\n"<<endl;
//	//cout<<a<<"\n"<<endl;
//	//cout<<a1<<"\n"<<endl;
//	//cout<<a2<<"\n"<<endl;
//
//	//for(int i=0;a1+i!="";i++)
//	//for(int i=0;i<strlen(a1)+1;i++)
//	//	cout<<a1+strlen(a1)<<endl;
//	
//	//else
//	//{
//	//	z1 = z1;
//	//	z1 = 1+strlen(z1)+a1;
//	//}
//	//
//	
//}
//void main(){
//	char* a = "abcdefg";
//	char* a1 = "cd";
//	char* a2 = "ef";
//	char z[100]="\0";
//	char* _z=z;
//
//	//strcat(z,a);
//	//cout<<z<<endl;
//	//strcat(z,a1);
//	//cout<<z<<endl;
//
//	mystrcat(&_z,&a);
//	cout<<_z<<endl;
//	mystrcat(&_z,&a1);
//	cout<<_z<<endl;
//	//mystrcat(&_z,&a);
//	//strcat(z,a);
//	//strcat(z,a1);
//	//strncat(z,a2,1);
//	//cout<<z<<endl;
//}