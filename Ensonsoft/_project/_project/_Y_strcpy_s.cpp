#include"_Y.h"
void main()
{
	//char* a = "abc";	//static���� ������ �Ǿ ����Ұ���
	//char* b = "dea";	//�׷��� ����ó���� ������

	char * a = NULL;	//�������� ó��
	char * b = NULL;	

	a = new char [strlen("abc") + 1];	//+1�� �ι���
	b = new char [strlen("def") + 1];

	if(a == NULL || b == NULL)
	{
		printf("NULL");
	}

	Ystrcpy_s(a,sizeof(a),"abc");
	Ystrcpy_s(b,sizeof(b),"def");

	cout<<Ystrcpy_s(a,sizeof(a),b)<<endl;
}