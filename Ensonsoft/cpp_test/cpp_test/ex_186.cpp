//#include<cstdlib>
//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//class FileRW{
//public:
//	void read(const string& fname){
//
//		char str[200];
//
//		ifstream fin;
//		fin.open(fname.c_str());
//		if(fin.good()){
//			cout<<fname.c_str()<<"�� �а� �ֽ��ϴ�."<<endl;
//		}
//		if(fin.fail()){
//			cout<<"���� �̸��� �߸� �Է��߽��ϴ�."<<endl;
//		}
//		while((fin.getline(str,150))!=NULL){
//			cout<<str<<endl;
//		}
//		fin.close();
//	}
//	void write(const string& fname,bool append=true,const char* chs="hello."){
//		ofstream fout;
//		if(append){
//			fout.open(fname.c_str(),ios_base::app);
//		}else{
//			fout.open(fname.c_str());
//		}
//
//		if(fout.fail()){
//			cout<<"���� ��¿� �����߽��ϴ�.";
//			return;
//		}
//		fout<<chs<<endl;
//
//		fout.close();
//	}
//};
//int main(){
//
//	char chs[]="void write(){";
//	FileRW* fr= new FileRW;
//
//	fr->read("main.cpp");
//	fr->write("a.txt",true,chs);
//	delete fr;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}