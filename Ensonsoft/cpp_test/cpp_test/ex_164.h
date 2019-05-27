#ifndef CAR_H
#define CAR_H
#include<cstdlib>
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
class Car{
private:
	int speed;
public:
	Car(int _speed=0):speed(_speed){}
	~Car(){}
	void speedUp(int _speed=10);
	void speedDown(int _speed=10);
	int currentSpeed() const;
	friend ostream& operator<<(ostream& os,const Car& car);
};
void Car::speedUp(int _speed){
	if((speed+_speed)<=200&&_speed>0&&_speed<30){
		speed+=_speed;
	}
}
void Car::speedDown(int _speed){
	if((speed-_speed)>=0&&_speed>0&&_speed<30){
		speed-=_speed;
	}else if((speed-_speed)<0&&_speed>0&&_speed<30){
		speed=0;
	}
}

int Car::currentSpeed() const{
	return speed;
}

ostream&operator<<(ostream& os,const Car& car){
	if(car.currentSpeed()>0){
		os<<"�� �ڵ����� ���� "<<car.speed<<"km/h"<<"�� �޸��� �ֽ��ϴ�"<<endl;
	}else{
		os<<"�� �ڵ����� ���� ������ �ֽ��ϴ�"<<endl;
	}
	return os;
}
#endif