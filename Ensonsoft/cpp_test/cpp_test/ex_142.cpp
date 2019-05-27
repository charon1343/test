//#include<cstdlib>
//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main()
//{
//	int row = 5;
//	int col = 2;
//	//int sample[row][col]={{1,2},{2,3},{3,4},{4,5},{5,6}};	ºÒ°¡
//	int sample[5][2]={{1,2},{2,3},{3,4},{4,5},{5,6}};
//	int i=0;
//	int **twostar;
//	twostar = new int*[row];
//	for(i=0;i<row;i++){
//		twostar[i]=new int[col];
//		memset(twostar[i],0,col*sizeof(int));
//	}
//
//	for(i=0;i<row;i++){
//		memcpy(twostar[i],sample[i],col*sizeof(int));
//	}
//
//	for(int j=0;j<row;j++){
//		for(int k=0;k<col;k++){
//			cout<<twostar[j][k]<<"\t";
//		}
//		cout<<endl;
//	}
//	for(i=0;i<row;i++){
//		delete[] twostar[i];
//	}
//	delete[] twostar;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}