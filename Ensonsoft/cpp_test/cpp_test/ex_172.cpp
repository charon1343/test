#include"ex_172.h"

int main(){
	Ant *ant1 = new Ant("ºÓÀº °³¹Ì",6,3);
	Termite* ter1 = new Termite("Èò°³¹Ì",6,3,"³ª¹«¿¡ ±ºÁı»ıÈ°"
		,3,"°¨Ä¥¸À ³ª´Â ¼¿·ê·Î¿ìÁî");

	Insect insec1("¹ú",6,3);
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