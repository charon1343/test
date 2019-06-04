//#include <iostream>
//#include <string>
//using namespace std;
//
//char* Mystrstr(char* a, char* b)
//{
//	char* _a = a;
//	char* _b = b;
//	
//	for(int i=0;i<strlen(a);i++,_a++)
//	{
//		while(*_b==*_a)
//		{
//			for(int i=0;i<strlen(b);i++)
//			{	
//				if(*(_a+i)==*(_b+i))
//					continue;
//				else
//					return 0;
//			}
//			return _a;
//		}
//	}
//	return 0;
//	
//}
//
//int main(void)
//{
//	char* a = "abcdefghijk";
//	char* b = "cd";
//	char* c = "ak";
//	char* a3 = strstr(a,c);
//	printf( "%s\n", a3);
//	a=Mystrstr(a,c);
//	printf( "%s\n",a);
//	//cout<<a<<endl;	//null을 출력하지못함
//	system("PAUSE");
//	return EXIT_SUCCESS;
//
//}