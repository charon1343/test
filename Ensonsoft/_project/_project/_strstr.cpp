//#include <iostream>
//#include <string.h>
//using namespace std;
//
//char* Mystrstr(char* a, char* b)
//{
//	char* _a = a;
//	char* _b = b;
//	
//	while(*_a!='\0')
//	{
//		while(*_b==*_a)
//		{
//			for(int i=0;i<strlen(b);i++)
//			{	
//				if(*(_a+i)==*(_b+i))
//				{
//					continue;
//				}
//				else
//				{
//					return 0;
//				}
//			}
//			return _a;
//		}
//		_a++;
//	}
//	return 0;
//}
//
//int main(void)
//{
//	char* a = "abcdefghijk";
//	char* b = "cd";
//	char* c = "ak";
//	char* a3 = strstr( a, c);
//
//	
//	printf( "%s\n", a3);
//
//	a=Mystrstr(a,c);
//	//printf( "%s\n",a);
//	if(a == NULL)
//	{
//		printf( "NULL ������\n");
//	}
//	else
//	{
//		cout<<a<<endl;	//null�� �����������
//	}
//	system("PAUSE");
//	return EXIT_SUCCESS;
//
//}