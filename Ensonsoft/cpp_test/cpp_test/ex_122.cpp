//#include<iostream>
//#include<cstring>
//using namespace std;
//int main()
//{
//	char strA[]="Hello! Nice to meet you.";
//	char strB[100];
//	char ch='N';
//	char *tempchar;
//	memcpy(strB,strA,sizeof(strA));
//	cout<<"123456789012345678901234567890"<<endl;
//	cout<<strA<<endl<<endl;
//	if(memcmp(strA,strB,sizeof(strA))==0){
//		cout<<"num�� f�� ��ġ"<<endl;
//	}else{
//		cout<<"num�� f�� ����ġ"<<endl;
//	}
//
//	tempchar = (char*)memchr(strA, ch, sizeof(strA));
//	cout<<ch<<"�� ó�� ���� ���ڿ� ���� ->"<<tempchar<<endl;
//	int location=tempchar-strA+1;		//??�׳� ���̳ʽ��ϸ� �˻�????
//	cout<<ch<<"��"<<strA<<"���� ���° ��ġ : "<<location<<endl;
//
//	int charcmp = memcmp(strA,tempchar,sizeof(tempchar));
//	if(charcmp==0){
//		cout<<"num�� f�� ��ġ"<<endl;
//	}else if(charcmp>0){
//		cout<<"�� ���� ���� ���� ���ĺ�"<<endl;
//	}else if(charcmp<0){
//		cout<<"�� ���� ���� ���� ���ĺ�"<<endl;
//	}
//	memmove(strA+15,strA+0,4);
//	cout<<strA<<endl;
//	cout<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}