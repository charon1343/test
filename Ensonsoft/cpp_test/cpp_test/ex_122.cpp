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
//		cout<<"num과 f가 일치"<<endl;
//	}else{
//		cout<<"num과 f가 불일치"<<endl;
//	}
//
//	tempchar = (char*)memchr(strA, ch, sizeof(strA));
//	cout<<ch<<"이 처음 나온 문자열 이후 ->"<<tempchar<<endl;
//	int location=tempchar-strA+1;		//??그냥 마이너스하면 검색????
//	cout<<ch<<"이"<<strA<<"에서 몇번째 위치 : "<<location<<endl;
//
//	int charcmp = memcmp(strA,tempchar,sizeof(tempchar));
//	if(charcmp==0){
//		cout<<"num과 f가 일치"<<endl;
//	}else if(charcmp>0){
//		cout<<"앞 문자 열이 뒤쪽 알파벳"<<endl;
//	}else if(charcmp<0){
//		cout<<"뒤 문자 열이 뒤쪽 알파벳"<<endl;
//	}
//	memmove(strA+15,strA+0,4);
//	cout<<strA<<endl;
//	cout<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}