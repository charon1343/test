//#include<iostream>
//using namespace std;
//class Progression{
//public :
//	int anDiff(int start, int n, int d);
//	int sumAnDiff(int start, int n, int d);
//};
//
//int Progression::anDiff(int start,int n,int d){
//	return (start+n*d);
//}
//
//int Progression::sumAnDiff(int start,int n,int d){
//	int sum=0;
//	for(int i=0;i<=n;i++){
//		sum+=anDiff(start,i,d);
//	}
//	return sum;
//}
//
//int main()
//{
//	Progression arith;
//	int n=49;
//	cout<<" --1,3,5,7, .., An"<<endl;
//	cout<<"A"<<n<<"="<<arith.anDiff(1,n,2)<<endl;
//	cout<<" --1,3,5,7, .., An"<<endl;
//	cout<<"Sum"<<n<<"="<<"="<<arith.sumAnDiff(1,n,2)<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}