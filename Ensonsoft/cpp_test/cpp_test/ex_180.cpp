//#include<cstdlib>
//#include<cstring>
//#include<iostream>
//#include<iomanip>
//using std::cout;
//using std::endl;
//class Flyer{
//public:
//	virtual void fly()=0;
//	virtual void landing()=0;
//};
//
//class Bird:public Flyer{
//public:
//	void fly();
//	void landing();
//};
//void Bird::fly(){
//	cout<<"�� ������ �۴��̸� ����"<<endl;
//}
//void Bird::landing(){
//	cout<<"�� ������ ����,"<<"�߰������� ���������� ������ �ɴ´�"<<endl;
//}
//class Airplane:public Flyer{
//public:
//	void fly();
//	void landing();
//};
//void Airplane::fly(){
//	cout<<"�� ������ ������ �̿��Ͽ� ����."<<endl;
//}
//void Airplane::landing(){
//	cout<<"�� ������ ������ ����,"<<"������ �̿��Ͽ� �����Ѵ�."<<endl;
//}
//class FlyInfor{
//public:
//	static void show(Flyer* fly){
//		cout<<"���� ���"<<endl;
//		fly->fly();
//		cout<<"������ ���"<<endl;
//		fly->landing();
//	}
//};
//int main(){
//	Bird* bird = new Bird();
//	Airplane* air = new Airplane();
//
//	cout<<"------------"<<endl;
//	FlyInfor::show(bird);
//	cout<<"--------------"<<endl;
//	 FlyInfor::show(air);
//
//	delete bird;
//	delete air;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
