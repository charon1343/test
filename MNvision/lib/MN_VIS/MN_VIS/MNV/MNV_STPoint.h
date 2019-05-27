#pragma once
#include <math.h>
struct MNV_STRectAffine {
	double dCenterX;
	double dCenterY;
	double dWidth;
	double dHeight;
	double dRotate;
};

class CMNV_STPoint {
#define DIV(A, B)	(A) / ((B) == 0 ? 1 : (B))
public:
	double m_dX;
	double m_dY;
	double m_dR;

	double GetX() { return m_dX; }
	double GetY() { return m_dY; }
	void Get(double & __dX, double & __dY) { __dX = m_dX; __dY = m_dY; }
	void SetX(double __dX) { m_dX = __dX; }
	void SetY(double __dY) { m_dY = __dY; }
	void Set(double __dX, double __dY) { m_dX = __dX; m_dY = __dY; }

	CMNV_STPoint() { m_dX = 0; m_dY = 0; m_dR = 0; }
	CMNV_STPoint(double __dX, double __dY) { m_dX = __dX; m_dY = __dY; m_dR = 0; }
	CMNV_STPoint(double __dX, double __dY, double __dR) { m_dX = __dX; m_dY = __dY; m_dR = __dR; }

	static void Exchange(CMNV_STPoint &__V1, CMNV_STPoint &__V2) {
		double Temp;
		Temp = __V1.GetX(); __V1.SetX(__V2.GetX()); __V2.SetX(Temp);
		Temp = __V1.GetY(); __V1.SetY(__V2.GetY()); __V2.SetY(Temp);
	}
	void Rotation(CMNV_STPoint __Origin, double __Radi) {
		double dCosR = cos(__Radi);
		double dSinR = sin(__Radi);
		double dTX = m_dX - __Origin.GetX();
		double dTY = m_dY - __Origin.GetY();
		m_dX = dTX * dCosR - dTY * dSinR + __Origin.GetX();
		m_dY = dTY * dCosR + dTX * dSinR + __Origin.GetY();
	}
	void Rotation(double __OriginX, double __OriginY, double __Radi) {
		double dCosR = cos(__Radi);
		double dSinR = sin(__Radi);
		double dTX = m_dX - __OriginX;
		double dTY = m_dY - __OriginY;
		m_dX = dTX * dCosR - dTY * dSinR + __OriginX;
		m_dY = dTY * dCosR + dTX * dSinR + __OriginY;
	}
	void Rotation(double __Radi) {
		double dCosR = cos(__Radi);
		double dSinR = sin(__Radi);
		double dTX = m_dX;
		double dTY = m_dY;
		m_dX = dTX * dCosR - dTY * dSinR;
		m_dY = dTY * dCosR + dTX * dSinR;
	}

	double Distance(CMNV_STPoint __V1) { 
		CMNV_STPoint Local(m_dX, m_dY);
		Local -= __V1;
		return sqrt(Local.GetX() * Local.GetX() + Local.GetY() * Local.GetY());
	}

	static double Distance (CMNV_STPoint __V1, CMNV_STPoint __V2, CMNV_STPoint __Resolution) {
		CMNV_STPoint Local = __V1;
		Local -= __V2;
		Local *= __Resolution;
		return sqrt(Local.GetX() * Local.GetX() + Local.GetY() * Local.GetY());
	}
	static double Distance (CMNV_STPoint __V1, CMNV_STPoint __V2, double __ResolutionX, double __ResolutionY) {
		CMNV_STPoint Local = __V1;
		Local -= __V2;
		Local *= CMNV_STPoint(__ResolutionX, __ResolutionY);
		return sqrt(Local.GetX() * Local.GetX() + Local.GetY() * Local.GetY());
	}
	static double Distance (CMNV_STPoint __V1, CMNV_STPoint __V2) {
		CMNV_STPoint Local = __V1;
		Local -= __V2;
		return sqrt(Local.GetX() * Local.GetX() + Local.GetY() * Local.GetY());
	}

	CMNV_STPoint operator + (CMNV_STPoint __Cord) { return CMNV_STPoint(m_dX + __Cord.GetX(), m_dY + __Cord.GetY()); }
	CMNV_STPoint operator - (CMNV_STPoint __Cord) { return CMNV_STPoint(m_dX - __Cord.GetX(), m_dY - __Cord.GetY()); }
	CMNV_STPoint operator * (CMNV_STPoint __Cord) { return CMNV_STPoint(m_dX * __Cord.GetX(), m_dY * __Cord.GetY()); }
	CMNV_STPoint operator / (CMNV_STPoint __Cord) { return CMNV_STPoint(DIV(m_dX, __Cord.GetX()), DIV(m_dY, __Cord.GetY())); }

	CMNV_STPoint operator + (double __Val) { return CMNV_STPoint(m_dX + __Val, m_dY + __Val); }
	CMNV_STPoint operator - (double __Val) { return CMNV_STPoint(m_dX - __Val, m_dY - __Val); }
	CMNV_STPoint operator * (double __Val) { return CMNV_STPoint(m_dX * __Val, m_dY * __Val); }
	CMNV_STPoint operator / (double __Val) { return CMNV_STPoint(DIV(m_dX, __Val), DIV(m_dY,__Val)); }

	void operator = (CMNV_STPoint __Cord) { m_dX = __Cord.GetX(); m_dY = __Cord.GetY(); m_dR = __Cord.m_dR; }
	void operator += (CMNV_STPoint __Cord) { m_dX += __Cord.GetX(); m_dY += __Cord.GetY(); }
	void operator -= (CMNV_STPoint __Cord) { m_dX -= __Cord.GetX(); m_dY -= __Cord.GetY(); }
	void operator *= (CMNV_STPoint __Cord) { m_dX *= __Cord.GetX(); m_dY *= __Cord.GetY(); }
	void operator /= (CMNV_STPoint __Cord) { m_dX = DIV(m_dX, __Cord.GetX()); m_dY = DIV(m_dY, __Cord.GetY()); }
};

//class TPCoordinate2D {
//public:
//	double dX;
//	double dY;
//	TPCoordinate2D() { dX = 0; dY = 0; }
//	TPCoordinate2D(double __dx, double __dY) { dX = __dx; dY = __dY; }
//	void Set(double __dx, double __dY) { dX = __dx; dY = __dY; }
//	void operator = (TPCoordinate2D __Value) { dX = __Value.dX; dY = __Value.dY; }
//	static void Exchange(TPCoordinate2D &__V1, TPCoordinate2D &__V2) {
//		double Temp;
//		Temp = __V1.dX; __V1.dX = __V2.dX; __V2.dX = Temp;
//		Temp = __V1.dY; __V1.dY = __V2.dY; __V2.dY = Temp;
//	}
//	void operator -= (TPCoordinate2D __Value) { 
//		dX -= __Value.dX;
//		dY -= __Value.dY;
//	}
//	void operator += (TPCoordinate2D __Value) { 
//		dX += __Value.dX;
//		dY += __Value.dY;
//	}
//	void operator *= (TPCoordinate2D __Value) {
//		dX *= __Value.dX;
//		dY *= __Value.dY;
//	}
//	void operator /= (TPCoordinate2D __Value) {
//		dX /= ((__Value.dX == 0) ? 1 : __Value.dX);
//		dY /= ((__Value.dY == 0) ? 1 : __Value.dY);
//	}
//	TPCoordinate2D operator - (TPCoordinate2D __Value) {
//		TPCoordinate2D Temp(*this);
//		Temp -= __Value;
//		return Temp;
//	}
//	TPCoordinate2D operator + (TPCoordinate2D __Value) {
//		TPCoordinate2D Temp(*this);
//		Temp += __Value;
//		return Temp;
//	}
//	TPCoordinate2D operator * (TPCoordinate2D __Value) {
//		TPCoordinate2D Temp(*this);
//		Temp *= __Value;
//		return Temp;
//	}
//	TPCoordinate2D operator / (TPCoordinate2D __Value) {
//		TPCoordinate2D Temp(*this);
//		Temp /= __Value;
//		return Temp;
//	}
//	void Rotation(TPCoordinate2D __Origin, double __Radi) {
//		double dCosR = cos(__Radi);
//		double dSinR = sin(__Radi);
//		double dTX = dX - __Origin.dX;
//		double dTY = dY - __Origin.dY;
//		dX = dTX * dCosR - dTY * dSinR + __Origin.dX;
//		dY = dTY * dCosR + dTX * dSinR + __Origin.dY;
//	}
//	void Rotation(double __Radi) {
//		double dCosR = cos(__Radi);
//		double dSinR = sin(__Radi);
//		double dTX = dX;
//		double dTY = dY;
//		dX = dTX * dCosR - dTY * dSinR;
//		dY = dTY * dCosR + dTX * dSinR;
//	}
//	void ReRotation(double __Radi) {
//		double dCosR = cos(__Radi);
//		double dSinR = sin(__Radi);
//		double dTX = dX;
//		double dTY = dY;
//		dX = dTX * dCosR + dTY * dSinR;
//		dY = dTY * dCosR - dTX * dSinR;
//	}
//	double Angle() {
//		return (dX != 0) ? atan(dY / dX) : (PI / 2);
//	}
//	double Angle90() {
//		return (dY != 0) ? atan(dX / dY) : (PI / 2);
//	}
//	static TPCoordinate2D Rotation(double __Radi, TPCoordinate2D __Source, TPCoordinate2D __Origin) {
//		TPCoordinate2D Temp(__Source);
//		double dCosR = cos(__Radi);
//		double dSinR = sin(__Radi);
//		double dTX = Temp.dX - __Origin.dX;
//		double dTY = Temp.dY - __Origin.dY;
//		Temp.dX = dTX * dCosR - dTY * dSinR + __Origin.dX;
//		Temp.dY = dTY * dCosR + dTX * dSinR + __Origin.dY;
//	}
//	static TPCoordinate2D Rotation(double __Radi, TPCoordinate2D __Source) {
//		TPCoordinate2D Temp(__Source);
//		double dCosR = cos(__Radi);
//		double dSinR = sin(__Radi);
//		double dTX = Temp.dX;
//		double dTY = Temp.dY;
//		Temp.dX = dTX * dCosR - dTY * dSinR;
//		Temp.dY = dTY * dCosR + dTX * dSinR;
//		return Temp;
//	}
//	static double Distance (TPCoordinate2D __V1, TPCoordinate2D __V2, TPCoordinate2D __Resolution) {
//		TPCoordinate2D Local = __V1;
//		Local -= __V2;
//		Local *= __Resolution;
//		return sqrt(Local.dX * Local.dX + Local.dY * Local.dY);
//	}
//	static double Distance (TPCoordinate2D __V1, TPCoordinate2D __V2, double __ResolutionX, double __ResolutionY) {
//		TPCoordinate2D Local = __V1;
//		Local -= __V2;
//		Local *= TPCoordinate2D(__ResolutionX, __ResolutionY);
//		return sqrt(Local.dX * Local.dX + Local.dY * Local.dY);
//	}
//	static double Distance (TPCoordinate2D __V1, TPCoordinate2D __V2) {
//		TPCoordinate2D Local = __V1;
//		Local -= __V2;
//		return sqrt(Local.dX * Local.dX + Local.dY * Local.dY);
//	}
//};
