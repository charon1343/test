//#include<cstdlib>
//#include<iostream>
//#include<string>
//#include<fstream>
//#include"ex_167.h"
//using namespace std;
//class FileSearch{
//public:
//	void store(const Account* acc){
//		string fname="";
//		char tostr[30];
//		itoa(acc->getId(),tostr,10);
//		fname=tostr;
//		fname+=".dat";
//		fstream myFile;
//		myFile.open(fname.c_str(),ios::out|ios::binary);
//		if(myFile.fail()){
//			cout<<"파일 저장에 실패했습니다.";
//			return;
//		}
//		myFile.write((char*)acc,sizeof(Account));
//		myFile.close();
//	}
//
//	void reads(const string ids,Account* acc){
//		string fname="";
//		fname=ids;
//		fname+=".dat";
//		fstream myFile;
//		myFile.open(fname.c_str(),ios::in|ios::binary);
//
//		if(myFile.fail()){
//			cout<<"파일이름을 잘못입력했습니다.";
//			return;
//		}
//		myFile.read((char*)acc,sizeof(Account));
//		myFile.close();
//	}
//};
//int main(){
//	FileSearch *fr=new FileSearch();
//	Account acc1(111,1000.0);
//	Account acc2(112,2000.0);
//	Account acc3(1000);
//	Account acc4(1000);
//
//	acc1.deposit(2000);
//	acc1.withdraw(3000);
//	acc1.withdraw(3000);
//	acc1.deposit(3000);
//	acc1.deposit(3000);
//
//	fr->store(&acc1);
//	fr->reads("111",&acc3);
//	cout<<acc3;
//
//	fr->store(&acc2);
//	fr->reads("112",&acc4);
//	cout<<acc4;
//	 delete fr;
//	 system("PAUSE");
//	return EXIT_SUCCESS;
//}