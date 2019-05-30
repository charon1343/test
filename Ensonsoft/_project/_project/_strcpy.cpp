//#include "_strcpy.h"
//
//void main(){
//	char* a = "abc123";
//	char* a1 = "cd";
//	char* a2 = "ef";
//	char z[100]="\0";
//	char* _z=z;
//
//	std::cout<<"---------------원본-------------"<<endl;
//	strcpy_s(z,a);
//	cout<<"\n"<<z<<endl;
//	strcpy_s(z,10,a1);
//	cout<<"\n"<<z<<endl;
//	strncpy(z,a2,1);
//	cout<<"\n"<<z<<endl;
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
//}