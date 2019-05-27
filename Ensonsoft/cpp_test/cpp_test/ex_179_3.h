#ifndef SHIP_INFOR_H
#define SHIP_INFOR_H
#include"ex_179.h"
class ShipInfor{
public:
	static void printinfor(Ship& sh);
	};
	void ShipInfor::printinfor(Ship& sh){
		sh.show();
	}
#endif