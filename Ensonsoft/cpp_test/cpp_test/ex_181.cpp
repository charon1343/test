//#include<cstdlib>
//#include<cstring>
//#include<iostream>
//#include<iomanip>
//using std::cout;
//using std::endl;
//class Lion{
//public:
//	Lion(){}
//	virtual ~Lion(){}
//	virtual void roar(){
//		cout<<"성난 사자처럼 으르렁"<<endl;
//	}
//	virtual void shape(){
//		cout<<"성난 사자"<<endl;
//	}
//};
//class Goat{
//public:
//	Goat(){}
//	virtual ~Goat(){}
//	virtual void roar(){
//		cout<<"발악하는 염소처럼 메에"<<endl;
//	}
//	virtual void shape(){
//		cout<<"발악하는 염소"<<endl;
//	}
//};
//class Dragon{
//public:
//	Dragon(){}
//	virtual ~Dragon(){}
//	virtual void roar(){
//		cout<<"매서운 용이 겁주듯 카악"<<endl;
//	}
//	virtual void shape(){
//		cout<<"매서운 용"<<endl;
//	}
//};
//class Chimera:public Lion,public Goat,public Dragon{
//public:
//	Chimera(){}
//	~Chimera(){}
//	void roar(){
//		cout<<"\n----------roar------------"<<endl;
//		Lion::roar();
//		Goat::roar();
//		Dragon::roar();
//		cout<<"하면서"<<"\n세 동물이 같이 무시무시하게 포효한다."<<endl;
//	}
//	void shape(){
//		cout<<"\n----------shape------------"<<endl;
//		Lion::shape();
//		Goat::shape();
//		Dragon::shape();
//	}
//	void attack(){
//		cout<<"\n----------attack------------"<<endl;
//		roar();
//		shape();
//		cout<<"\n불을 뿜으며 매섭게 공격한다."<<endl;
//	}
//};
//int main(){
//	Chimera* chi= new Chimera;
//	chi->attack();
//
//	Lion* li = chi;
//	li->roar();
//
//	delete chi;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}