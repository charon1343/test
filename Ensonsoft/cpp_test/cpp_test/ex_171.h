#ifndef ANT_H
#define ANT_H
#include"ex_170.h"//임의추가
using std::cout;
using std::endl;

class Ant:public Insect{
protected:
	char* lives;
	int kinds;
public:
	Ant(const char* _name="개미",int _regs=6,int _organpart=3,
		const char* _lives="군집생활",int _kinds=3);
	virtual ~Ant(){cout<<"Ant die"<<endl;delete[] lives;}
	char* getLives()const{return lives;}
	int getKinds()const {return kinds;}
	virtual void character();
	
};
Ant::Ant(const char* _name,int _regs,int _organpart,const char* _lives,int _kinds)
	:Insect(_name,_regs,_organpart),kinds(_kinds){
	lives=new char[strlen(_lives)+1];
	strcpy(lives,_lives);
}
void Ant::character(){
	cout<<name<<"는 다리가"<<regs<<"개 이며,"<<"몸은"<<organpart<<"부분으로 나뉜다.\n"
		<<"또한"<<lives<<"을 한다."
		<<kinds<<"종류가 있다."<<endl;
}

#endif