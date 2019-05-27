#ifndef INSUFFIEXCEPTION_H
#define INSUFFIEXCEPTION_H
#include<iostream>
#include<string>
#include "ex_184.h"
using std::cout;
using std::endl;
class InsufficientException:public Exception{
private:
	int money;
public:
	InsufficientException(int _money,const string& _str="원이 모자랍니다.")
		:Exception(_str),money(_money){
			char ta[100];
			itoa(_money,ta,10);
			str="";
			str.append(ta);
			str.append(_str);
	}
	void printError(){
		cout<<"InsufficientException occur!!"<<str<<endl;
	}
};

#endif