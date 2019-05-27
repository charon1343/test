//#include"ex_172.h"
//
//int main(){
//	Ant* at1 = new Termite("뉴흰개미",6,3,"땅속에서 군집생활",4,"질긴나무 나무뿌리");
//	Termite* t1 = new Termite("흰개미",6,3,"나무에서 군집생활",4,"감칠맛 나는 셀룰로우즈");
//	Ant* at2=t1;//프로모션,업캐스팅,암시적 캐스팅
//
//	cout<<"\n==================개미타입으로 흰개미 생성"<<endl;
//	at1->character();
//	cout<<"어디서 사는가?"<<at1->getLives()<<endl;
//	cout<<"종류?"<<at1->getKinds()<<endl;
//	//cout<<"먹이?"<<at1->getEats()<<endl;
//	cout<<"\n=============개미타입으로 흰개미를 받음"<<endl;
//	at2->character();
//	cout<<"어디서 사는가?"<<at2->getLives()<<endl;
//	cout<<"종류?"<<at2->getKinds()<<endl;
//	//cout<<"먹이?"<<at2->getEats()<<endl;
//	cout<<"\n----cross castring(down casting)========"<<endl;
//	Termite* t3=(Termite*)at2;
//	//Termite* t4=(Termite*)at1;//가능
//	Termite* t4=dynamic_cast<Termite*>(at1);//권장
//	t3->character();
//	cout<<"먹이?"<<t3->getEats()<<endl;
//	cout<<"-----------"<<endl;
//	t4->character();
//	cout<<"먹이?"<<t4->getEats()<<endl;
//
//	delete t1; delete at1;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}