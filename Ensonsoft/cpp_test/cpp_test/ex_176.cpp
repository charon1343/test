//#include "ex_172.h"
//#include<typeinfo>
//void showAnt(Ant* argan){
//	cout<<"\n"<< argan->getName()<<"�� Ư¡"<<endl;
//	argan->character();
//	if(typeid(*argan)==typeid(Ant)){
//		cout<<"��� ��°�?"<<argan->getLives()<<endl;
//		cout<<"����?"<<argan->getKinds()<<endl;
//	}else if(typeid(*argan)==typeid(Termite)){
//		Termite* tan1=dynamic_cast<Termite*>(argan);
//		cout<<"����?"<<tan1->getEats()<<endl;
//		cout<<"��� ��°�?"<<tan1->getLives()<<endl;
//		cout<<"����?"<<tan1->getKinds()<<endl;
//	}
//}
//
//void showAnt2(Ant& argan){
//	cout<<"\n"<<argan.getName()<<"�� Ư¡-++++++"<<endl;
//	argan.character();
//	if(typeid(argan)==typeid(Ant)){
//		cout<<"��� ��°�?"<<argan.getLives()<<endl;
//		cout<<"����?"<<argan.getKinds()<<endl;
//	}else if(typeid(argan)==typeid(Termite)){
//		Termite& tan1=dynamic_cast<Termite&>(argan);
//		cout<<"����?"<<tan1.getEats()<<endl;
//		cout<<"��� ��°�?"<<tan1.getLives()<<endl;
//		cout<<"����?"<<tan1.getKinds()<<endl;
//	}
//}
//
//int main(){
//	Ant* at1= new Termite("���򰳹�",6,3,"���ӿ��� ������Ȱ",4,"���� ���� �����Ѹ�");
//	Termite* t1 = new Termite("�򰳹�",6,3,"������ ������Ȱ",3,"��ĥ�� ���� ����ο���");
//	Ant* at2=t1;
//
//	showAnt(at1);
//	showAnt(t1);
//	
//	Termite t3("���򰳹�");
//	Ant &a3 = t3;
//
//	showAnt(&a3);
//	showAnt2(a3);
//
//	delete t1; delete at1;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}