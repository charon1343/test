#ifndef INSECT_H
#define INSECT_H
#include<cstdlib>
#include<cstring>
#include<iostream>

using std::cout;
using std::endl;

class Insect{
protected:
	char* name;
	int regs;
	int organpart;
public:
	Insect(const char* _name="����",int _regs=6,int _organpart=3);
	virtual ~Insect(){cout<<"Insect die"<<endl;delete[] name;}
	char* getName()		const{return name;}
	int getRegs()		const{return regs;}
	int getOrganpar()	const{return organpart;}
	virtual void character();
};
Insect::Insect(const char* _name,int _regs,int _organpart):regs(_regs),organpart(_organpart){
	name=new char[strlen(_name)+1];
	strcpy(name,_name);
}
void Insect::character(){
	cout<<name<<"�� �ٸ��� "<<regs<<"���̸�,"<<"����"<<organpart<<"�κ����� ������."<<endl;
}
#endif