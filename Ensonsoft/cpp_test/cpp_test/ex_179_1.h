#ifndef BOAT_H
#define BOAT_H
#include"ex_179.h"
class Boat:public Ship{
private:
	char* name;
public:
	Boat(char* _name="천금",int _people=0,int _arms=0):Ship(_people,_arms){
		name = new char[strlen(_name)+1];
		strcpy(name,_name);
	}
	~Boat(){delete[] name;}
	int carry() const{return people;}
	int move() const{return people*5+arms;}
	char* getName()const{return name;}
	void show();
};

void Boat::show(){
	cout<<"보트명 : "<<name<<std::setw(5)<<carry()<<std::setw(5)<<move()<<endl;
}

#endif