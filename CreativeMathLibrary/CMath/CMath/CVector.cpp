#include "CVector.h"
#include "CPoint.h"
#include "CTransfrom.h"


CVector::CVector(CVector&& MoveAssigment) 
{
}

CVector::CVector(float x, float y, float z)
	: x(0), y(0), z(0)
{

}

CVector::CVector(int x, int y, int z)
	:x(0), y(0), z(0)
{

}

//CVector::CVector(const CPoint3D& Point)
//{
//	this->x = Point.x;
//	this->y = Point.y;	
//	this->z = Point.z;
//}

float& CVector::operator[](int a)
{
	return ((&x)[a]);
}

const float& CVector::operator[](int a) const
{
	return ((&x)[a]);
}

CVector& CVector::operator*=(float s)
{
	x *= s;
	y *= s;
	z *= s;
	return (*this);
}

CVector& CVector::operator/=(float s)
{
	s = 1.0f / s;
	x *= s;
	y *= s;
	z *= s;

	return (*this);
}

int CVector::CosineScalarProduct(const CVector& VectorOne, const CVector& VectorTwo)
{
	int result = SMagnitude(VectorOne) * SMagnitude(VectorTwo) * cosf(0);
	return result;
}

int CVector::ScalarProduct(const CVector& VectorOne, const CVector& VectorTwo)
{
	int result = VectorOne.x * VectorTwo.x + VectorOne.y + VectorOne.z * VectorTwo.z;
	return result;
}

CVector CVector::ProjectionOperation(const CVector& VectorA, const CVector& VectorB)
{
	return(VectorB * ScalarProduct(VectorA, VectorB) / ScalarProduct(VectorA, VectorB));
}

CVector CVector::RejectionOperation(CVector& VectorA, const CVector& VectorB)
{
	return(VectorA - VectorB * (ScalarProduct(VectorA, VectorB) / ScalarProduct(VectorB, VectorB)));
}

CVector& CVector::operator=(const CVector& Attr) const
{
	auto x = const_cast<CVector&>(Attr);
	return x;
}

CVector CVector::CrossProductOverloadForNormalCalc(const CPoint3D& PointA, const CPoint3D& PointB, const CVector& VectorTwo)
{
	CVector* result = new CVector(0.0f, 0.0f, 0.0f);

	const CVector CombinedVector = PointA + PointB;

	result->x = (CombinedVector.y * VectorTwo.z) - CombinedVector.z * VectorTwo.y;
	result->y = (CombinedVector.z * VectorTwo.x) - CombinedVector.x * VectorTwo.z;
	result->z = (CombinedVector.x * VectorTwo.y) - CombinedVector.y * VectorTwo.x;
	return *result;
}

float CVector::DistPointLine(const CPoint3D& EndOfPerpendicularline, const CPoint3D& LineToDetermine,
                             const CVector& Vector)
{
	CVector VectorA = CrossProductOverloadForNormalCalc(EndOfPerpendicularline, LineToDetermine, Vector);

	return (SFFLOAT_SQRT(ScalarProduct(VectorA, VectorA) / CVector::ScalarProduct(Vector, Vector)));

}

float CVector::DistLineLine(const CPoint3D& PointA, const CPoint3D& PointB, const CVector& VectorA,
                            const CVector& VectorB)
{
	CVector _DotProduct = PointB - PointA;

	float v12 = ScalarProduct(VectorA, VectorA);
	float v22 = ScalarProduct(VectorB, VectorB);
	float v1v2 = ScalarProduct(VectorA, VectorB);

	float det = v1v2 * v1v2 - v12 * v22;

	//Get the absolute value of the collated scalar products, if the result is greater than the 
	if (fabs(det) > FLT_MIN)
	{
		det = 1.0f / det;

		float DotProductOfVectorA = ScalarProduct(_DotProduct, VectorA);
		float DotProductOfVectorB = ScalarProduct(_DotProduct, VectorB);
		float t1 = (v1v2 * DotProductOfVectorB - v22 * DotProductOfVectorA) * det;
		float t2 = (v12 * DotProductOfVectorB - v1v2 * DotProductOfVectorA) * det;

		return (SMagnitude(_DotProduct + VectorB * t2 - VectorA * t1));
	}


	CVector a = CrossProduct(_DotProduct, VectorA);
	return (SFFLOAT_SQRT(CVector::ScalarProduct(VectorA, VectorA / v12)));

}

CVector CVector::Normalize(const CVector& Vector, int TypeOfMagnitudeToNormalizeBy)
{
	switch (ETypeOfMagnititude magnitude{})
	{
	case ETypeOfMagnititude::SMagnititude:
		return (Vector / SMagnitude(Vector));
		break;
	case ETypeOfMagnititude::DMagnititude:
		return (Vector / DMagnitude(Vector));
		break;
	default:
		break;
	}

	return Vector;
}


CVector operator-(const CVector& VectorA, const CVector& VectorB)
{
	return CVector();
}

CVector operator+(CVector& VectorA, float AdditionOperand)
{
	return CVector(VectorA.x + AdditionOperand, VectorA.y + AdditionOperand, VectorA.z + AdditionOperand);
}

CVector CVector::CrossProduct(const CVector& VectorOne, const CVector& VectorTwo)
{
	auto result = new CVector(0.0f, 0.0f, 0.0f);
	result->x = (VectorOne.y * VectorTwo.z) - VectorOne.z * VectorTwo.y;
	result->y = (VectorOne.z * VectorTwo.x) - VectorOne.x * VectorTwo.z;
	result->z = (VectorOne.x * VectorTwo.y) - VectorOne.y * VectorTwo.x;
	return *result;
}

template <class GenericClass>
CVector operator-(const GenericClass& VectorA, const GenericClass& VectorB)
{
	return (CVector(VectorA.x - VectorB.x, VectorA.y - VectorB.y, VectorA.z - VectorB.z));
}

//CVector operator*(const CVector& Normal, const STransform4D& Matrix)
//{
//	return (CVector(Normal.x * Matrix(0, 0) + Normal.y * Matrix(1, 0) + Normal.z * Matrix(2, 0),
//	                Normal.x * Matrix(0, 1) + Normal.y * Matrix(1, 1) + Normal.z * Matrix(2, 1),
//	                Normal.x * Matrix(0, 2) + Normal.y * Matrix(1, 2) + Normal.z * Matrix(2, 2)));
//}


CVector operator+ (const CVector& VectorA, const CVector& VectorB)
{
	return CVector(VectorA.CVector::x + VectorB.CVector::x, VectorA.CVector::y + VectorB.CVector::y, VectorA.CVector::z + VectorB.CVector::z);
}

CVector operator* (const CVector& vector, float scalar)
{
	return CVector(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

CVector operator/ (const CVector& vector, float scalar)
{
	return CVector(vector.x * scalar, vector.y * scalar, vector.z * scalar);
}

