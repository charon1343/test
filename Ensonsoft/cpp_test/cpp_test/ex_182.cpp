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
//		cout<<eats<<"�� �Դ´�."<<endl;
//	}
//	virtual void drink(){
//		cout<<"���� ���Ŵ�."<<endl;
//	}
//};
//class Lion:virtual public Animal{
//public:
//	Lion(){}
//	virtual ~Lion(){}
//	virtual void eat(char* eats){
//		cout<<eats<<"�� ���� ��� �Դ´�."<<endl;
//	}
//	virtual void roar(){
//		cout<<"���� ����ó�� ������"<<endl;
//	}
//	virtual void shape(){
//		cout<<"���� ����"<<endl;
//	}
//};
//class Goat{
//public:
//	Goat(){}
//	virtual ~Goat(){}
//	virtual void eat(char* eats){
//		cout<<eats<<"�� �������� �þ� �Դ´�."<<endl;
//	}
//	virtual void roar(){
//		cout<<"�߾��ϴ� ����ó�� �޿�"<<endl;
//	}
//	virtual void shape(){
//		cout<<"�߾��ϴ� ����"<<endl;
//	}
//};
//class Dragon{
//public:
//	Dragon(){}
//	virtual ~Dragon(){}
//	virtual void eat(char* eats){
//		cout<<eats<<"�� �ҿ� ������ �ܲ� ��Ų��."<<endl;
//	}
//	virtual void roar(){
//		cout<<"�ż��� ���� ���ֵ� ī��"<<endl;
//	}
//	virtual void shape(){
//		cout<<"�ż��� ��"<<endl;
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
//		cout<<"�ϸ鼭"<<"\n�� ������ ���� ���ù����ϰ� ��ȿ�Ѵ�."<<endl;
//	}
//	void shape(){
//		cout<<"\n----------shape------------"<<endl;
//		Lion::shape();
//		Goat::shape();
//		Dragon::shape();
//		cout<<"�� �� ������ ����� ��� ���´�."<<endl;
//	}
//	void attack(){
//		cout<<"\n----------attack------------"<<endl;
//		roar();
//		shape();
//		cout<<"\n���� ������ �ż��� �����Ѵ�."<<endl;
//	}
//	void eat(char* eats){
//		cout<<"\n----------eat------------"<<endl;
//		Lion::eat(eats);
//		Goat::eat(eats);
//		Dragon::eat(eats);
//	}
//	void drink(){
//		cout<<"�Ǹ� ���Ŵ�."<<endl;
//	}
//};
//int main(){
//	Chimera* chi = new Chimera;
//	//chi->attack();
//	chi->Goat::eat("�罿");
//	chi->eat("����");
//	chi->drink();
//	Animal* li=chi;
//	li->eat("�䲤");
//	//li->roar();
//	Animal* ani = new Chimera();
//	ani->eat("������");
//
//	delete ani;
//	delete chi;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
