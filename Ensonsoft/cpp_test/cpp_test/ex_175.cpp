//#include"ex_172.h"
//
//int main(){
//	Ant* at1 = new Termite("���򰳹�",6,3,"���ӿ��� ������Ȱ",4,"���䳪�� �����Ѹ�");
//	Termite* t1 = new Termite("�򰳹�",6,3,"�������� ������Ȱ",4,"��ĥ�� ���� ����ο���");
//	Ant* at2=t1;//���θ��,��ĳ����,�Ͻ��� ĳ����
//
//	cout<<"\n==================����Ÿ������ �򰳹� ����"<<endl;
//	at1->character();
//	cout<<"��� ��°�?"<<at1->getLives()<<endl;
//	cout<<"����?"<<at1->getKinds()<<endl;
//	//cout<<"����?"<<at1->getEats()<<endl;
//	cout<<"\n=============����Ÿ������ �򰳹̸� ����"<<endl;
//	at2->character();
//	cout<<"��� ��°�?"<<at2->getLives()<<endl;
//	cout<<"����?"<<at2->getKinds()<<endl;
//	//cout<<"����?"<<at2->getEats()<<endl;
//	cout<<"\n----cross castring(down casting)========"<<endl;
//	Termite* t3=(Termite*)at2;
//	//Termite* t4=(Termite*)at1;//����
//	Termite* t4=dynamic_cast<Termite*>(at1);//����
//	t3->character();
//	cout<<"����?"<<t3->getEats()<<endl;
//	cout<<"-----------"<<endl;
//	t4->character();
//	cout<<"����?"<<t4->getEats()<<endl;
//
//	delete t1; delete at1;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}