//#include<iostream>
//#include<cstring>
//using namespace std;
//
//int main()
//{
//	cout<<"--���� �ڸ��� 3,6,9�ΰ�--\n"<<endl;
//	cout<<"������ �Է��Ͻÿ�\n"<<endl;
//	int num =0;
//	char* c369;
//	char* copys1="�� ���� �ڸ��� 3 �Ǵ� 6�Ǵ� 9��.";
//	char* copys2="�� ���� �ڸ��� 3 �Ǵ� 6�Ǵ� 9�� �ƴϴ�.";
//	char cc369[100]={'\0'};
//	cin>>num;
//	c369=(num%10!=0&&(num%10)%3==0)?
//		strcpy(cc369,copys1):
//		strcpy(cc369,copys2);
//	cout<<"1: "<<num<<c369<<endl;
//	cout<<"2: "<<num<<cc369<<endl;
//	cout<<num;
//	while(*c369!='\0'){
//		cout<<*c369;
//		c369++;
//	}
//
//	cout<<endl;
//	cout<<num;
//	for(int i=0;*(cc369+i)!='\0';i++){
//		cout<<cc369[i];
//	}
//	cout<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}