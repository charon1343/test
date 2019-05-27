//#include<iostream>
//#include<ctype.h>
//using namespace std;
//
//int main(){
//
//	char inString[50]={'\0'};
////	char nextChar;
////	char tokens[10]={'\0'};
//	cout<<"\n===문자열처리(문수 문자 제외)===\n";
//	cout<<"영어로 50자 미만을 입력하세요. 숫자포함 : ";
//	cin.getline(inString,50,'\n');
//	int leng=strlen(inString);
//	int countSpace=0,countAlpha=0,countUpper=0;
//	int countDigit=0,countLower=0;
//	for(int i=0;i<leng;i++){
//		if(isspace(inString[i])){
//			countSpace++;
//		}else if(isalpha(inString[i])){
//			countAlpha++;
//			if(isupper(inString[i])){
//					countUpper++;
//				}else if(islower(inString[i])){
//					countLower++;
//				}
//		}else if(isdigit(inString[i])){
//			countDigit++;
//		}
//	}
//
//	cout<<inString<<"의 길이 :"<<leng<<endl;
//	cout<<"알파벳 수 :"<<countAlpha<<endl;
//	cout<<"알파벳 중 대문자 수 :"<<countUpper<<endl;
//	cout<<"알파벳 중 소문자 수 :"<<countLower<<endl;
//	cout<<"공백의 수 : "<<countSpace<<endl;
//	cout<<"숫자의 수 : "<<countDigit<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
//
