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
//	cout<<"두 날개를 퍼덕이며 난다"<<endl;
//}
//void Bird::landing(){
//	cout<<"두 날개를 적고,"<<"발가락으로 나무가지를 잡으며 앉는다"<<endl;
//}
//class Airplane:public Flyer{
//public:
//	void fly();
//	void landing();
//};
//void Airplane::fly(){
//	cout<<"두 날개의 엔진을 이용하여 난다."<<endl;
//}
//void Airplane::landing(){
//	cout<<"두 날개를 엔진을 끄고,"<<"바퀴를 이용하여 착륙한다."<<endl;
//}
//class FlyInfor{
//public:
//	static void show(Flyer* fly){
//		cout<<"나는 방법"<<endl;
//		fly->fly();
//		cout<<"내리는 방법"<<endl;
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
