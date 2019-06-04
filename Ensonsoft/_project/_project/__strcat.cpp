//#include<iostream>
//using namespace std;
//
//int mystrlen(char* a)
//{
//	char *cpTemp = a;
//	int iLength = 0;
//
//
//	while(*cpTemp != '\0')
//	{
//		iLength += 1;
//		cpTemp += 1;
//	}
//
//	return iLength;
//}
//
////
//char* mystrcat_s(char* a, int iSize, char* b)
//{
//	char* _a = a;
//	char* _b = b;
//	/*if(iSize>(mystrlen(a)+mystrlen(b)))
//	{
//		for(int i=0;i<iSize;i++)
//		{
//			while(*_a!='\0')
//			{
//				_a+=1;
//				i++;
//			}
//
//			while(*_b!='\0')
//			{
//				*_a=*_b;
//				_a+=1;
//				_b+=1;
//				i++;
//			}
//			*_a='\0';
//		}
//	
//	}*/
//
//	int iTargetLength, iSourceLength;
//
//	iTargetLength =mystrlen(a);
//	iSourceLength = mystrlen(b);
//
//	if(iTargetLength + iSourceLength > iSize) return NULL;
//
//	_a += iTargetLength;
//	for(int i = 0; i < iSourceLength; i +=1)
//	{
//		*_a = *_b;
//		_a += 1;
//		_b += 1;
//	}
//
//	*_a='\0';
//
//	return a;
//}
//
//void main()
//{
//	char szString[100] = {"12345"}, szString1[10] = {"6789"};
//
//	int b = mystrlen(szString);
//	cout<<b<<endl;
//	
//	strcat_s(szString,sizeof(szString),szString1);
//	cout<<szString<<endl;
//	mystrcat_s(szString, sizeof(szString), szString1);
//	cout<<szString<<endl;
//	mystrcat_s(szString, sizeof(szString), szString1);
//	cout<<szString<<endl;
//	mystrcat_s(szString, sizeof(szString), szString1);
//	cout<<szString<<endl;
//	mystrcat_s(szString, sizeof(szString), szString1);
//	cout<<szString<<endl;
//}