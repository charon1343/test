//#include<iostream>
//using namespace std;
//
//class Point {
//private:
//	int x;
//	int y;
//public:
//	Point(int _x,int _y):x(_x),y(_y){}
//	~Point(){
//	cout<<"Point die"<<endl;
//	}
//	Point(const Point &p);
//	Point(const Point *p);
//	void showXY();
//	void move(int _x,int _y);
//	int getX() const {return x;}
//	int getY() const {return y;}
//};
//Point::Point(const Point &p){
//	x=p.getX();
//	y=p.getY();
//}
//Point::Point(const Point *p){
//	x=p->getX();
//	y=p->getY();
//}
//void Point::showXY(){
//	cout<<"("<<x<<","<<y<<")"<<endl;
//}
//void Point::move(int _x,int _y){
//	x+=_x;
//	y+=_y;
//}
//int main(){
//	Point p5(5,8);
//	Point p6(p5);
//	Point p7=p5;
//	Point *p8=new Point(2,7);
//	Point *p9=new Point(p8);
//	cout<<"p5.showXY";	p5.showXY();
//	p5.move(4,5);
//	cout<<"p5.showXY";	p5.showXY();
//	p6.move(3,6);
//	cout<<"p5.showXY";	p5.showXY();
//	cout<<"p6.showXY";	p6.showXY();
//	cout<<"p7.showXY";	p7.showXY();
//	p8->move(3,6);
//	p9->move(2,-3);
//	cout<<"p8.showXY";	p8->showXY();
//	delete p8,p9;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}