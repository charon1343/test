#ifndef ANT_H
#define ANT_H
#include"ex_170.h"//�����߰�
using std::cout;
using std::endl;

class Ant:public Insect{
protected:
	char* lives;
	int kinds;
public:
	Ant(const char* _name="����",int _regs=6,int _organpart=3,
		const char* _lives="������Ȱ",int _kinds=3);
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
	cout<<name<<"�� �ٸ���"<<regs<<"�� �̸�,"<<"����"<<organpart<<"�κ����� ������.\n"
		<<"����"<<lives<<"�� �Ѵ�."
		<<kinds<<"������ �ִ�."<<endl;
}

#endif