#include"_Y.h"
void main()
{
	//char* a = "abc";	//static으로 선언이 되어서 변경불가능
	//char* b = "dea";	//그래서 예외처리가 떴었음

	char * a = NULL;	//동적으로 처리
	char * b = NULL;	

	a = new char [strlen("abc") + 1];	//+1은 널문자
	b = new char [strlen("def") + 1];

	if(a == NULL || b == NULL)
	{
		printf("NULL");
	}

	Ystrcpy_s(a,sizeof(a),"abc");
	Ystrcpy_s(b,sizeof(b),"def");

	cout<<Ystrcpy_s(a,sizeof(a),b)<<endl;
}