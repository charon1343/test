//#include<iostream>
//using namespace std;
//
//int Mystrcspn(char* b,char* b1){
//	int result = strlen(b);
//	for(int i=0;i<strlen(b);i++){
//		for(int j=0;j<strlen(b1);j++){
//			if((char)*(b+i)==*(b1+j))
//				if(result>i)
//					result = i;
//		}
//	}
//	return result;
//}
//
//void main(){
//	char b[] = "aehfvn";
//	char b1[] = "n";
//	cout<<"---------------¿øº»-------------"<<endl;
//	int b2 = strcspn(b,b1);
//	cout<<b2<<endl;
//	cout<<"---------------strscpn-------------"<<endl;
//	int b3 = Mystrcspn(b,b1);
//	cout<<b3<<endl;
//
//
//}