//#include"ex_188.h"
//#include<iomanip>
//using namespace std;
//
//template <class T>
//void swaps(T *n,T *m){
//	T temp = *n;
//	*n=*m;
//	*m=temp;
//}
//template<class T>
//void bubble_inc(T *n,int counts){
//	int i=0,j=0;
//	for(i=1;i<counts;i++){
//		for(j=0;j<counts-i;j++){
//			if(n[j]>n[j+1]){
//				swaps(&n[j],&n[j+1]);
//			}
//		}
//	}
//}
//template <class T>
//void bubble_dec(T *n,int counts){
//	int i=0,j=0;
//	for(i=1;i<counts;i++){
//		for(j=0;j<counts-i;j++){
//			if(n[j]<n[j+1]){
//				swaps(&n[j],&n[j+1]);
//			}
//		}
//	}
//}
//int main(){
//	cout<<"a"<<endl;
//	Grade grd[5];
//	grd[1]=Grade("10001",70,90,100);
//	grd[2]=Grade("10002",70,100,80);
//	grd[3]=Grade("10003",90,70,50);
//	grd[4]=Grade("10004",90,80,100);
//	grd[0]=Grade("10005",90,100,30);
//	cout<<"------------------"<<endl;
//	int i=0;
//	for(i=0;i<5;i++){
//		grd[i].PintGrade();
//	}
//	bubble_dec<Grade>(grd,5);
//	cout<<"------------------"<<endl;
//	int igrd[5]={2,6,3,7,4};
//	bubble_dec<int>(igrd,5);
//	
//	for(i=0;i<5;i++){
//		cout<<igrd[i]<<std::setw(5);
//	}
//	cout<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}