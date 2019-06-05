//#include"_Y.h"
//void main()
//{
//	//char* a = "abc";	//static으로 선언이 되어서 변경불가능
//	//char* b = "dea";	//그래서 예외처리가 떴었음
//
//	char * a = new char();	//동적으로 처리
//	char * b = new char();
//
//	if(a == NULL || b == NULL)	//NULL 확인 필수 습관화
//	{
//		printf("NULL");
//	}
//
//	strcpy(a,"aaaaaa");	//첫 대입은 _s로 하였을때 제약이 많이 됨
//	strcpy(b,"bbbbbb");	//sizeof로 사용하면 크기가 4밖에 안됨
//
//	cout<<Ystrcpy_s(a,Ystrlen(a),b)<<endl;	//sizeof로 크기를 측정하면 사이즈에러쯤
//}