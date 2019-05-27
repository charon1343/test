//#include"ex_172.h"
//
//int main(){
//	Ant* a1 = new Ant("붉은 개미",6,3,"사람의 집에서 몰래 군집생활",3);
//	Termite* t1 = new Termite("흰개미",6,3,"나무에 군집생활",3,"감칠맛 나는 셀룰로우즈");
//	Ant* at1 = new Termite("뉴흰개미",6,3,"땅속에서 군집생활",4,"질긴 나무 나무뿌리");
//	cout<<"\n-------개미"<<endl;
//	a1->character();
//	cout<<"어디서 사는가? : "<<a1->getLives()<<endl;
//	cout<<"개미의 종류는? : "<<a1->getKinds()<<endl;
//	cout<<"\n-------흰개미"<<endl;
//	t1->character();
//	cout<<"무엇을 먹는가? : "<<t1->getEats()<<endl;
//	cout<<"어디서 사는가? : "<<t1->getLives()<<endl;
//	cout<<"흰 개미 종류는? : "<<t1->getKinds()<<endl;
//
//	cout<<"\n----개미의 타입의 흰개미 -----"<<endl;
//	at1->character();
//	//사용못합 cout<<"무엇을 먹는가?"<<at1->getEats();
//	cout<<"어디서 사는가? : "<<at1->getLives()<<endl;
//	cout<<"뉴흰개미 종류는? : "<<at1->getKinds()<<endl;
//
//	delete a1;delete t1;delete at1;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}
