//#include<iostream>
//#define MAX	4
//using namespace std;
//double total(int sub[],int num);
//double ave(int sub[],int num);
//void print(int stu[][MAX],int row,int col);
//
//char subject[][10]={"국어","영어","수학","C++"};
//
//int main()
//{
//	int student[][4] = {{100,90,80,95},{97,98,99,87},{100,98,78,98},{90,100,87,86}};
//
//	int row = sizeof(student)/sizeof(student)[0];
//	int col = sizeof(student[0])/sizeof(int);
//
//	cout<<"번호\t";
//
//	for(int i=0;i<col;i++){
//		cout<<subject[i]<<"\t";
//	}
//
//	cout<<"총점"<<"\t평균"<<endl;
//	for(int j=0; j<row;j++){
//		cout<<(j+1)<<"\t";
//		for(int k=0;k<col;k++){
//			cout<<student[j][k]<<"\t";
//		}
//		cout<<total(student[j],col)<<"\t";
//		cout<<ave(student[j],col)<<endl;
//	}
//
//	cout<<"\n==함수이용=="<<endl;
//	print(student,row,col);
//
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
//
//double total(int sub[],int num){
//	double tot=0.0;
//	for(int i=0;i<num;i++){
//		tot+=sub[i];
//	}
//	return tot;
//}
//
//double ave(int sub[],int num){
//	return total(sub,num)/num;
//}
//
//void print(int stu[][MAX],int row,int col){
//	cout<<"번호\t";
//	for(int i=0;i<col;i++){
//		cout<<subject[i]<<"\t";
//	}
//
//	cout<<"총점"<<"\t"<<endl;
//	for(int j=0;j<row;j++){
//		cout<<(j+1)<<"\t";
//		for(int k=0;k<col;k++){
//			cout<<stu[j][k]<<"\t";
//		}
//		cout<<total(stu[j],col)<<"\t";
//		cout<<ave(stu[j],col)<<endl;
//	}
//}