//#include<iostream>
//using namespace std;
//
//class Point{
//private:
//	int x;
//	int y;
//public:
//	Point(int _x,int _y):x(_x),y(_y){}
//	Point():x(0),y(0){}
//
//	~Point(){cout<<"Point die"<<endl;}
//
//	Point(const Point &p);
//	Point(const Point *p);
//
//	void showXY();
//	void move(int _x,int _y);
//	int getX() const {return x;}
//	int getY() const {return y;}
//	Point operator+(const Point &p2);
//	Point operator-(const Point &p2);
//};
//
//Point::Point(const Point &p){
//	x=p.getX();
//	y=p.getY();
//}
//
//Point::Point(const Point *p){
//	x=p->getX();
//	y=p->getY();
//}
//void Point::move(int _x,int _y){
//	x+=x;
//	y+=y;
//}
//Point Point::operator+(const Point &p2){
//	return Point(x+p2.getX(),y+p2.getY());
//}
//Point Point::operator-(const Point &p2){
//	return Point(x-p2.getX(),y-p2.getY());
//}
//int main(){
//	Point p5(5,8);
//	Point p6(2,7);
//	Point p7;
//	p7=p5+p6;	//소멸자 원인
//	Point p8=p5-p6;
//	cout<<"("<<p5.getX()<<" "<<p5.getY()<<")"<<endl;
//	cout<<"("<<p6.getX()<<" "<<p6.getY()<<")"<<endl;
//	cout<<"("<<p7.getX()<<" "<<p7.getY()<<")"<<endl;
//	cout<<"("<<p8.getX()<<" "<<p8.getY()<<")"<<endl;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}