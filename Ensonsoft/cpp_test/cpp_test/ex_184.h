#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

class Exception{
protected:
	string str;
public:
	Exception(const string& _str="에러발생!"):str(_str){}
	Exception(const Exception& alle){
		str = alle.getMesseage();
	}
	virtual ~Exception(){}
	virtual string getMesseage() const{return str;}
	virtual const char* what(){return str.c_str();}
};

#endif
