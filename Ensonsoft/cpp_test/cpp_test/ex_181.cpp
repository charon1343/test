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
//	}
//	void attack(){
//		cout<<"\n----------attack------------"<<endl;
//		roar();
//		shape();
//		cout<<"\n���� ������ �ż��� �����Ѵ�."<<endl;
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