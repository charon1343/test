//#include "_strcpy.h"
//
//void main(){
//	char* a = "abc123";
//	char* a1 = "cd";
//	char* a2 = "ef";
//	char z[100]="\0";
//	char* _z=z;
//
//	std::cout<<"---------------����-------------"<<endl;
//	strcpy_s(z,a);
//	cout<<"\n"<<z<<endl;
//	strcpy_s(z,10,a1);
//	cout<<"\n"<<z<<endl;
//	strncpy(z,a2,1);
//	cout<<"\n"<<z<<endl;
//	cout<<"---------------mem����� ����-------------"<<endl;
//	mystrcpy(z,a);
//	cout<<"\n"<<z<<endl;
//	mystrcpy(z,2,a1); 
//	cout<<"\n"<<z<<endl;
//	cout<<"---------------2�� ������ �̿� ����-------------"<<endl;
//	ccopy(&_z,&a);
//	cout<<"\n"<<_z<<endl;
//
//	ccopy(&_z,&a1);
//	cout<<"\n"<<_z<<endl;
//
//	ccopy(&_z,&a2);
//	cout<<"\n"<<_z<<endl;
//	cout<<"---------------������ �̿� ����-------------"<<endl;
//	cccopy(_z,a);
//	cout<<"\n"<<_z<<endl;	//�Լ��� �ݿ����� ����
//}