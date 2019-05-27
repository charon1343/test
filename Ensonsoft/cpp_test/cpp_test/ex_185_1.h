#ifndef WRONGEXCEPTION_H
#define WRONGEXCEPTION_H
#include<iostream>
#include<string>
#include<cstdlib>
#include"ex_184.h"
using std::cout;
using std::endl;
class WrongMoneyException:public Exception{
private:
	int money;
public:
	WrongMoneyException(int _money,const string& _str="원은 잘못된 금액입니다.")
		:Exception(_str),money(_money){
			char ta[100];
			itoa(_money,ta,10);
			str="";
			str.append(ta);
			str.append(_str);
	}
	void printError(){
		cout<<"WrongMoneyException occur!!"<<str<<endl;
	}
};

#endif