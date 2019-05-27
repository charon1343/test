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
public:
	Account(int _id,double _balance=0.0):id(_id),balance(_balance){
		dates(' ');
		cout<<*this;
	}
	Account(const Account& acc){
		id=acc.getId();
		balance=acc.getBalance();
	}
	~Account(){}
	int getId()const{return id;}
	double getBalance()const{return balance;}
	void deposit(double _balance);
	void withdraw(double _balance);
	friend ostream& operator<<(ostream& os,const Account& acc);
	Account& operator +=(double _balance);
	Account& operator -=(double _balance);
	bool operator ==(const Account& acc);
	bool operator !=(const Account& acc);
};
Account& Account::operator+=(double _balance){
	if(_balance>0){
		balance+=_balance;
		dates('+');
		cout<<*this;
		return *this;
	}else{
		dates('?');
		cout<<"입금에 실패했습니다."<<endl;
		return *this;
	}
}
Account& Account::operator-=(double _balance){
	if(_balance>0&&(balance-_balance>=0)){
		balance-=_balance;
		dates('-');
		cout<<*this;
		return *this;
	}else{
		dates('?');
		cout<<"입금에 실패했습니다."<<endl;
		return *this;
	}
}
void Account::dates(char c){
	time_t now=time(NULL);
	struct tm t=*localtime(&now);
	cout<<c<<"["<<(t.tm_year+1900)<<"/"<<(t.tm_mon+1)<<"/"<<(t.tm_mday)<<"/"<<(t.tm_hour)<<":"<<(t.tm_min)<<":"<<(t.tm_sec)<<"]";
}
void Account::deposit(double _balance){
	if(_balance>0){
		balance+=_balance;
		dates('+');
		cout<<*this;
	}
}
void Account::withdraw(double _balance){
	if(_balance>0&&(balance-_balance>=0)){
		balance-=_balance;
		dates('-');
		cout<<*this;
	}
}
bool Account::operator==(const Account& acc){
	if(id==acc.getId()){
		return true;
	}else return false;
}
bool Account::operator!=(const Account& acc){
	if(id!=acc.getId()){
		return true;
	}else return false;
}
ostream& operator<<(ostream& os,const Account& acc){
	os<<"고객"<<acc.id<<"님의 저축액은 "<<acc.balance<<"원 입니다."<<endl;
	return os;
}
#endif