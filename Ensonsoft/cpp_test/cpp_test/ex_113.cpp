//#include<iostream>
//#include<cstring>
//using namespace std;
//int findString(char cs[],char c[]);
//int findChar(char cs[],char c);
//void appendString(char cs[],char c[]);
//void appendString(char cs[],char c[],int after);
//int stringCompare(char cs[],char c[]);
//
//int main()
//{
//	char insa[] = "Hello my nickname is honny.";
//	char sear[]="ni";
//	char target[]="please, do copy and paste.";
//	char app[30]={'\0'};
//	cout<<"0\t  1\t    2\t      3"<<endl;
//	cout<<"0123456789012345678901234567890"<<endl;
//	int index=findString(insa,sear);
//	cout<<"1: "<<index<<endl;
//	cout<<"2: "<<findChar(insa,'i')<<endl;
//	appendString(app,sear);
//	cout<<"3: "<<app<<endl;
//	appendString(app,insa,5);
//	cout<<"4: "<<app<<endl;
//	cout<<"5: "<<stringCompare(app,sear)<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
//
//int findString(char cs[],char c[]){
//	return strcspn(cs,c)+1;
//}
//int findChar(char cs[],char c){
//	char *tmpChar;
//	tmpChar = strchr(cs,c);
//	return tmpChar - cs + 1;
//}
//void appendString(char cs[],char c[]){
//	strcat(cs,c);
//}
//void appendString(char cs[],char c[],int after){
//	strncat(cs,c,after);
//}
//int stringCompare(char cs[],char c[]){
//	return strcmp(cs,c);
//}
