#ifndef GRADE_H
#define GRADE_H
#include<cstdlib>
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::ostream;

class Grade{
private:
	char* id;
	double kor;
	double eng;
	double math;
	double total;
	double mean;
public:
	Grade(char* _de="0000",double _kor=0,
		double _eng=0,double _math=0);
	Grade(const Grade& grd);
	~Grade();
	Grade& operator=(const Grade &g);

	char* getId()const{return id;}
	double getKor()const{return this->kor;}
	double getEng()const{return this->eng;}
	double getMath()const{return this->math;}
	double getTotal();
	double getMean();

	void setKor(double _kor){kor=_kor;}
	void setEng(double _eng){eng=_eng;}
	void setMath(double _math){math=_math;}

	void PintGrade(){
		getMean();
		cout<<id<<"/"<<kor<<"/"<<eng<<"/"<<math<<"/"<<total<<"/"<<mean<<endl;
	}
	bool operator>(Grade& g){
		return this->getMean()>g.getMean();
	}
	bool operator<(Grade& g){
		return this->getMean()<g.getMean();
	}
		bool operator==(Grade& g){
		return this->getMean()==g.getMean();
	}
		bool operator!=(Grade& g){
		return this->getMean()!=g.getMean();
	}
};
Grade::Grade(char* _id,double _kor,double _eng,double _math)
	:kor(_kor),eng(_eng),math(_math){
		id=new char[30];
		strcpy(id,_id);
		getMean();
}
Grade::Grade(const Grade& grd){
	id=new char[30];
	strcpy(id,grd.getId());
	kor=grd.getKor();
	eng=grd.getEng();
	math=grd.getMath();
	getMean();
}
Grade::~Grade(){
	delete[] id;
}
Grade& Grade::operator =(const Grade &g){
	strcpy(id,g.getId());
	this->kor=g.getKor();
	this->eng=g.getEng();
	this->math=g.getMath();
	return *this;
}
double Grade::getTotal(){
	total=(kor+eng+math);
	return total;
}
double Grade::getMean(){
	getTotal();
	mean=total/3.0;
	return mean;
}
#endif