//#include "ex_172.h"
//#include<typeinfo>
//void showAnt(Ant* argan){
//	cout<<"\n"<< argan->getName()<<"의 특징"<<endl;
//	argan->character();
//	if(typeid(*argan)==typeid(Ant)){
//		cout<<"어디서 사는가?"<<argan->getLives()<<endl;
//		cout<<"종류?"<<argan->getKinds()<<endl;
//	}else if(typeid(*argan)==typeid(Termite)){
//		Termite* tan1=dynamic_cast<Termite*>(argan);
//		cout<<"먹이?"<<tan1->getEats()<<endl;
//		cout<<"어디서 사는가?"<<tan1->getLives()<<endl;
//		cout<<"종류?"<<tan1->getKinds()<<endl;
//	}
//}
//
//void showAnt2(Ant& argan){
//	cout<<"\n"<<argan.getName()<<"의 특징-++++++"<<endl;
//	argan.character();
//	if(typeid(argan)==typeid(Ant)){
//		cout<<"어디서 사는가?"<<argan.getLives()<<endl;
//		cout<<"종류?"<<argan.getKinds()<<endl;
//	}else if(typeid(argan)==typeid(Termite)){
//		Termite& tan1=dynamic_cast<Termite&>(argan);
//		cout<<"먹이?"<<tan1.getEats()<<endl;
//		cout<<"어디서 사는가?"<<tan1.getLives()<<endl;
//		cout<<"종류?"<<tan1.getKinds()<<endl;
//	}
//}
//
//int main(){
//	Ant* at1= new Termite("뉴흰개미",6,3,"땅속에서 군집생활",4,"질긴 나무 나무뿌리");
//	Termite* t1 = new Termite("흰개미",6,3,"나무에 군집생활",3,"감칠맛 나는 셀룰로우즈");
//	Ant* at2=t1;
//
//	showAnt(at1);
//	showAnt(t1);
//	
//	Termite t3("쑥흰개미");
//	Ant &a3 = t3;
//
//	showAnt(&a3);
//	showAnt2(a3);
//
//	delete t1; delete at1;
//	system("PAUSE");
//	return EXIT_SUCCESS;
//}