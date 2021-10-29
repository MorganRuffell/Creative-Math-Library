#pragma once
#include "CVector.h"
#include "CMatrix3.h"
#include "CPoint.h"
#include "Parent/CObject.h"
#include "CRTypes.h"


class CMATH_API CQuat
{
public:

	// Do not modify these unless you know quarterions like the back of your hand! -- You don't!
	float x, y, z, w;


public:

	CQuat() = default;

	//W is the scalar we multiply by.
	CQuat(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	CQuat(const CVector & VectorToMultiplyByScalar, float Scalar)
	{
		x = VectorToMultiplyByScalar.x; y = VectorToMultiplyByScalar.y; z = VectorToMultiplyByScalar.z;
		w = Scalar;
	}

	[[nodiscard]] const CVector& GetVectorPart(void) const
	{
		return (reinterpret_cast<const CVector&>(x));
	}


public:

	CMatrix3D GetRotationMatrix(void);
	void SetRotationMatrix(const CMatrix3D & Matrix);


public:
	[[nodiscard]] CVector Transform(const CVector& VectorA, const CQuat& QuaternionA) const
	{
		const auto* VectorB = new CVector(QuaternionA.GetVectorPart());

		float b2 = VectorB->x * VectorB->x + VectorB->y * VectorB->y + VectorB->z * VectorB->z;

		return (VectorA * (QuaternionA.w + QuaternionA.w - b2) + *VectorB * (CVector::ScalarProduct(VectorA, *VectorB) * 2.0f)
			+ CVector::CrossProduct(*VectorB, VectorA) * (QuaternionA.w * 2.0f));

		delete(VectorB);
	}

};


inline CMatrix3D CQuat::GetRotationMatrix(void)
{
	const float x2 = x * x;
	const float y2 = y * y;
	const float z2 = z * z;
	const float xy = x * y;
	const float xz = x * z;
	const float yz = y * z;
	const float wx = w * x;
	const float wy = w * y;
	const float wz = w * z;

	return (CMatrix3D(
		1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy),
		2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx),
		2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2)));

}

inline void CQuat::SetRotationMatrix(const CMatrix3D& Matrix)
{
	constexpr float divisor = 0.5f;
	constexpr float QuarterDivisor = 0.25f;

	const float SubMatrix0 = Matrix(0, 0);
	float SubMatrix1 = Matrix(1, 1);
	float SubMatrix2 = Matrix(2, 2);


	const float SumOfSubMatrixes = SubMatrix1 + SubMatrix2;

	if (SumOfSubMatrixes < 0.0f)
	{
		w = SFFLOAT_SQRT(SumOfSubMatrixes + 1.0f) * 0.5f;
		const float f = QuarterDivisor / w;

		x = (Matrix(2, 1) - Matrix(1, 2)) * f;
		y = (Matrix(0, 2) - Matrix(2, 0)) * f;
		z = (Matrix(1, 0) - Matrix(0, 1)) * f;
	}

	else if ((SubMatrix0 > SubMatrix1) && (SubMatrix0 > SubMatrix2))
	{
		x = SFFLOAT_SQRT(SubMatrix0 - SubMatrix1 - SubMatrix2 + 1.0f) * divisor;

		const float f = QuarterDivisor / x;

		y = (Matrix(1, 0) + Matrix(0, 1)) * f;
		z = (Matrix(0, 2) + Matrix(1, 2)) * f;
		w = (Matrix(2, 1) + Matrix(1, 2)) * f;

	}
	else if (SubMatrix1 > SubMatrix2)
	{
		y = SFFLOAT_SQRT(SubMatrix1 - SubMatrix0 - SubMatrix2 + 1.0f) * divisor;

		const float f = QuarterDivisor / y;

		x = (Matrix(0, 2) + Matrix(2, 0)) * f;
		y = (Matrix(2, 1) + Matrix(1, 2)) * f;
		w = (Matrix(1, 0) + Matrix(0, 1)) * f;
	}
	else
	{
		z = SFFLOAT_SQRT(SubMatrix2 - SubMatrix0 - SubMatrix1 + 1.0f) * divisor;
		const float f = QuarterDivisor / z;

		x = (Matrix(0, 2) + Matrix(2, 0)) * f;
		y = (Matrix(2, 1) + Matrix(1, 2)) * f;
		w = (Matrix(1, 0) + Matrix(0, 1)) * f;

	}

}

inline CQuat operator* (const CQuat& QuarternionOne, const CQuat& QuarternionTwo)
{
	return (CQuat(
		QuarternionOne.w * QuarternionTwo.x + QuarternionOne.x * QuarternionTwo.w + QuarternionOne.y * QuarternionTwo.z - QuarternionOne.z * QuarternionTwo.y,
		QuarternionOne.w * QuarternionTwo.y - QuarternionOne.x * QuarternionTwo.z + QuarternionOne.y * QuarternionTwo.w + QuarternionOne.z * QuarternionTwo.x,
		QuarternionOne.w * QuarternionTwo.z + QuarternionOne.x * QuarternionTwo.y + QuarternionOne.y * QuarternionTwo.x + QuarternionOne.z * QuarternionTwo.w,
		QuarternionOne.w * QuarternionTwo.w - QuarternionOne.x * QuarternionTwo.x + QuarternionOne.y * QuarternionTwo.y - QuarternionOne.z * QuarternionTwo.z));
}


