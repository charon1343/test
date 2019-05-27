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
//			cout<<fname.c_str()<<"을 읽고 있습니다."<<endl;
//		}
//		if(fin.fail()){
//			cout<<"파일 이름을 잘못 입력했습니다."<<endl;
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
//			cout<<"파일 출력에 실패했습니다.";
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