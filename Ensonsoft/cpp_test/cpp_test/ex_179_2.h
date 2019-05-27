#ifndef CRUISE_H
#define CRUISE_H
#include"ex_179.h"
class Cruiser: public Ship{
private:
	char* name;
public:
	Cruiser(char* _name="Ãµ±Ý",int _people=0,int _arms=0):Ship(_people,_arms){
		name = new char[strlen(_name)+1];
		strcpy(name,_name);
	}
	~Cruiser(){delete[] name;}
	int carry() const{return people;}
	int move() const{return people*5+arms;}
	char* getName() const{return name;}
	void show();
};

void Cruiser::show(){
	cout<<"Cruise¸í :"<<name<<std::setw(5)<<carry()<<std::setw(5)<<move()<<endl;
}
#endif