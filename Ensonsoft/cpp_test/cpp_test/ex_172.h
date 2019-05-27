#ifndef TERMITE_H
#define TERMITE_H
#include"ex_171.h"

using std::cout;
using std::endl;

class Termite:public Ant{
protected:
	char* eats;
public:
	Termite(const char* _name="Termite",int _regs=6,int _organpar=3,
		const char* _lives="군집생활",int _kinds=3,const char* _eats="cellulose");
	~Termite(){cout<<"Termite die"<<endl;delete[] eats;}
	char* getEats() const{return eats;}
	virtual void character();
};
Termite::Termite(const char* _name,int _regs,int _organpart,
	const char* _lives,int _kinds,const char* _eats)
	:Ant(_name,_regs,_organpart,_lives,_kinds){
	eats=new char[strlen(_eats)+1];
	strcpy(eats,_eats);
}
void Termite::character(){
	cout<<name<<"는 다리가 "<< regs<<"개 이며,"<<"몸은"<<organpart<<"부분으로 나뉜다.\n"
		<<"또한"<<lives<<"을 한다."
		<<kinds<<"종류가 있다\n"
		<<eats<<"을 주식으로 한다."<<endl;
}
#endif