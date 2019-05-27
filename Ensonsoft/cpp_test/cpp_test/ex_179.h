#ifndef SHIP_H
#define SHIP_H
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<iomanip>

using std::cout;
using std::endl;
class Ship{
protected:
	int people;
	int arms;
public:
	Ship(int _people=0,int _arms=0):people(_people),arms(_arms){}
	virtual ~Ship(){}
	virtual int carry() const=0;
	virtual int move() const=0;
	virtual void show();
};

void Ship::show(){
	cout<<carry()<<" "<<move()<<endl;
}
#endif