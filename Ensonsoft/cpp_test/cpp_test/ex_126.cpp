//#include<iostream>
//using namespace std;
//
//class Point {
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
//Point::Point(int _x,int _y):x(_x),y(_y){
//}
//
//Point::~Point(){
//	cout<<"Point die"<<endl;
//}
//
//void Point::showXY(){
//	cout<<"("<<x<<","<<y<<")"<<endl;
//}
//
//void Point::move(int _x,int _y)
//{
//	x+=_x;
//	y+=_y;
//}
//
//int main(){
//	Point p1(3,5);
//	Point *p3=&p1;//얕은복사
//	p1.showXY();
//	p1.move(5,-1);
//	p1.showXY();
//	p3->move(4,7);
//	p3->showXY();
//	p1.showXY();
//	int pt1=sizeof(Point);
//	cout<<"Point의 크기"<<pt1<<"byte"<<endl;
//	cout<<"Point의 주소"<<&p1<<endl;
//	cout<<"Point의 주소"<<&p3<<" "<<p3<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
