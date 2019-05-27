#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<cstdlib>
#include<iostream>
#include<ctime>
using std::cout;
using std::endl;
using std::ostream;
class Account{
private:
	int id;
	double balance;
public:
	Account(int _id,double _balance=0.0):id(_id),balance(_balance){
		cout<<*this;
	}
	~Account(){}
	int getID()const{return id;}
	double getBalance()const{return balance;}
	void deposit(double _balance);
	void withdraw(double _balance);
	friend ostream& operator<<(ostream& os,const Account& acc);
};
void Account::deposit(double _balance){
	if(_balance>0){
		balance+=_balance;
		cout<<*this;
	}
}
void Account::withdraw(double _balance){
	if(_balance>0&&(balance-_balance>=0)){
		balance-=_balance;
		cout<<*this;
	}
}
ostream& operator<<(ostream& os,const Account& acc){
	os<<"고객"<<acc.id<<"님의 저축액은 "<<acc.balance<<"원 입니다."<<endl;
	return os;
}
#endif