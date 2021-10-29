#pragma once

#include "CreativeMathToolkit.h"
#include "CVector.h"

class CMATH_API CPoint3D : public CVector
{
public:

	float x, y, z;

public:

	CPoint3D() = default;

	~CPoint3D()
	{
		delete(this);
	}

	CPoint3D(float x, float y, float z)
	{
		CPoint3D* Point = new CPoint3D(x, y, z);
	}

	template<class GenericClass>
	CPoint3D(const GenericClass& VectorToPoint)
	{
		CPoint3D* Point = new CPoint3D(VectorToPoint);
	}


};

inline CPoint3D operator+ (const CPoint3D& PointA, const CPoint3D& PointB)
{
	return(CPoint3D(PointA.x + PointB.x, PointA.y + PointB.y, PointA.z + PointB.z));
}

inline CPoint3D operator- (const CPoint3D& PointA, const CPoint3D& PointB)
{
	return(CPoint3D(PointA.x - PointB.x, PointA.y - PointB.y, PointA.z - PointB.z));
}

inline CPoint3D operator* (const CPoint3D& PointA, float A)
{
	return(CPoint3D(PointA.x * A, PointA.y * A, PointA.z * A));
}



