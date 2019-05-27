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
	void dates(char c);
public :
	Account(int _id,double _balance = 0.0):id(_id),balance(_balance){
		dates(' ');
		cout<<*this;
	}
	~Account(){}
	int getId()const{return id;}
	double getBalance()const{return balance;}
	void deposit(double _dalance);
	void withdraw(double _balance);
	friend ostream& operator<<(ostream& os,const Account& acc);
};
void Account::deposit(double _balance){
	if(_balance>0){
		balance+=_balance;
		dates('+');
		cout<<*this;
	}
}
void Account::dates(char c){
	time_t now =time(NULL);
	struct tm t =*localtime(&now);
	cout<<c<<"["<<(t.tm_year+1900)<<"/"<<(t.tm_mon+1)<<"/"
		<<(t.tm_mday)<<"/"<<(t.tm_hour)<<":"<<(t.tm_min)<<":"<<(t.tm_sec)<<"]";
}
void Account::withdraw(double _balance){
	if(_balance>0&&(balance-_balance>=0)){
		balance-=_balance;
		dates('-');
		cout<<*this;
	}
}
ostream& operator<<(ostream& os,const Account& acc){
	os<<"고객"<<acc.id<<"님의 저축액은"<<acc.balance<<"원 입니다."<<endl;
	return os;
}
#endif
