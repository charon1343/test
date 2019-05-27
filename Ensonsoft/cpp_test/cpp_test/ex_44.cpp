//#include<iostream>
//using namespace std;
//int Max(int *num,int counts);	//포인터 사용
//
//int main()
//{
//	int num[]={8,54,11,-45,43,26,66,12,33,65};
//	int n = sizeof(num)/sizeof(int);
//	cout<<"최대값 :"<<Max(num,n)<<endl;
//	cout<<"\n--"<<endl;
//	system("PAUSE");
//	return 0;
//}
//
//int Max(int *num,int counts)
//{
//	cout<<counts<<endl;
//	int max=*(num+0);
//	for(int i=1;i<counts;i++)
//	{
//		if(*(num+i)>max){
//			max=*(num+i);
//		}
//	}
//	return max;
//}