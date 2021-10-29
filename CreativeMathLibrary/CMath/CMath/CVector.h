#pragma once
#include <cfloat>
#include <memory>
#include "CreativeMathToolkit.h"

class CPoint3D;

//Replace implementations with these!
//enum class ETypeOfMagnititude;
//class _ETypeOfMagnitude
//{
//	ETypeOfMagnititude* magnititude_;
//	std::shared_ptr<ETypeOfMagnititude> SolveTwo;
//};
//
//class STransform4D;
//class _STransform4D
//{
//	STransform4D* Class;
//	std::shared_ptr<STransform4D> Solve;
//};
//
//class CPoint;
//class _CPoint
//{
//	CPoint* Class;
//	std::shared_ptr<CPoint> Solve;
//};

class CMATH_API CVector
{
public:

	float x;
	float y;
	float z;

public:

	CVector()
	{
		x = 0, y = 0, z = 0;
	}

	CVector(CVector&& MoveAssignment);
	CVector& operator=(CVector&& other) = default;

	CVector(const CVector& Vector) = default;

	~CVector() = default;

public:

	CVector(float x, float y, float z);

	CVector(int x, int y, int z);

public:

	float& operator[] (int a);

	const float& operator[] (int a) const;

public:

	CVector& operator *=(float s);

	CVector& operator /= (float s);


public:
	static int CosineScalarProduct(const CVector& VectorOne, const CVector& VectorTwo);

	static int ScalarProduct(const CVector& VectorOne, const CVector& VectorTwo);


public:

	//Projection operation.
	CVector ProjectionOperation(const CVector& VectorA, const CVector& VectorB);

	//Rejection Operation
	CVector RejectionOperation(CVector& VectorA, const CVector& VectorB);

	friend CVector operator+ (const CVector& VectorA, const CVector& VectorB);

	friend CVector operator* (const CVector& vector, float scalar);

	friend CVector operator/ (const CVector& vector, float scalar);

	CVector& operator=(const CVector& Attr) const;

	CVector CrossProductOverloadForNormalCalc(const CPoint3D& PointA, const CPoint3D& PointB, const CVector& VectorTwo);

public:


	float DistPointLine(const CPoint3D& EndOfPerpendicularline, const CPoint3D& LineToDetermine, const CVector& Vector);

	float DistLineLine(const CPoint3D& PointA, const CPoint3D& PointB, const CVector& VectorA, const CVector& VectorB);


	friend CVector operator- (const CVector& VectorA, const CVector& VectorB);


	CVector Normalize(const CVector& Vector, int TypeOfMagnitudeToNormalizeBy);

public:

	friend CVector operator+ (CVector& VectorA, float AdditionOperand);


public:

	static CVector CrossProduct(const CVector& VectorOne, const CVector& VectorTwo);
};


