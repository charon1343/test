#include"ex_172.h"

int main(){
	Ant *ant1 = new Ant("���� ����",6,3);
	Termite* ter1 = new Termite("�򰳹�",6,3,"������ ������Ȱ"
		,3,"��ĥ�� ���� ����ο���");

	Insect insec1("��",6,3);
	cout<<"--"<<endl;
	ter1->character();
	cout<<"---"<<endl;
	insec1.character();
	cout<<insec1.getName()<<endl;
	ant1->character();

	delete ant1;delete ter1;
	system("PAUSE"); 
	return EXIT_SUCCESS;
}