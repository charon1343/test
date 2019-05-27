//#include<cstdlib>
//#include<cstring>
//#include<iostream>
//#include<iomanip>
//using std::cout;
//using std::endl;
//class Animal{
//public:
//	Animal(){}
//	virtual ~Animal(){}
//	virtual void eat(char* eats){
//		cout<<eats<<"을 먹는다."<<endl;
//	}
//	virtual void drink(){
//		cout<<"물을 마신다."<<endl;
//	}
//};
//class Lion:virtual public Animal{
//public:
//	Lion(){}
//	virtual ~Lion(){}
//	virtual void eat(char* eats){
//		cout<<eats<<"을 물어 뜯어 먹는다."<<endl;
//	}
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
//	virtual void eat(char* eats){
//		cout<<eats<<"을 질겅질겅 씹어 먹는다."<<endl;
//	}
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
//	virtual void eat(char* eats){
//		cout<<eats<<"을 불에 구워서 꿀꺽 삼킨다."<<endl;
//	}
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
//		cout<<"의 세 동물의 모습을 모두 갖는다."<<endl;
//	}
//	void attack(){
//		cout<<"\n----------attack------------"<<endl;
//		roar();
//		shape();
//		cout<<"\n불을 뿜으며 매섭게 공격한다."<<endl;
//	}
//	void eat(char* eats){
//		cout<<"\n----------eat------------"<<endl;
//		Lion::eat(eats);
//		Goat::eat(eats);
//		Dragon::eat(eats);
//	}
//	void drink(){
//		cout<<"피를 마신다."<<endl;
//	}
//};
//int main(){
//	Chimera* chi = new Chimera;
//	//chi->attack();
//	chi->Goat::eat("사슴");
//	chi->eat("영양");
//	chi->drink();
//	Animal* li=chi;
//	li->eat("토깽");
//	//li->roar();
//	Animal* ani = new Chimera();
//	ani->eat("개구리");
//
//	delete ani;
//	delete chi;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
