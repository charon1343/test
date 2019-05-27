//#include<iostream>
//using namespace std;
//
//class Point{
//private:
//	int x;
//	int y;
//public:
//	Point(int _x,int _y);
//	~Point();
//	void showXY();
//	void move(int _x,int _y);
//};
//
//Point::Point(int _x,int _y):x(_x),y(_y){}
//Point::~Point(){
//	cout<<"Point die"<<endl;
//}
//
//void Point::showXY(){
//	cout<<"("<<x<<","<<y<<")"<<endl;
//}
//
//void Point::move(int _x,int _y){
//	x+=_x;
//	y+=_y;
//}
//
//int main(){
//	Point *p2= new Point(5,8);
//	Point *p4;
//	p4=p2;
//	p2->showXY();
//	p2->move(4,5);
//	p2->showXY();
//	p4->move(3,6);
//	p2->showXY();
//	int pt2=sizeof(Point);
//	cout<<"Point의 크기"<<pt2<<"byte"<<endl;
//	cout<<"Point의 주소"<<&p2<<" "<<p2<<endl;
//
//	delete p2;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}