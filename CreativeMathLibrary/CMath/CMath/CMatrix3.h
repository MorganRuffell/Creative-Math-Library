#pragma once

#include "CVector.h"
#include "CreativeMathToolkit.h"

class CMATH_API CMatrix3D
{
public:
	float CRMatrix3[3][3];

public:

	CMatrix3D() = default;

	template <typename generic>
	CMatrix3D(
		generic aa, generic ab, generic ac,
		generic ba, generic bb, generic bc,
		generic ca, generic cb, generic cc);


	CMatrix3D(
		float aa, float ab, float ac,
		float ba, float bb, float bc,
		float ca, float cb, float cc);

	CMatrix3D(const CVector& VectorA, const CVector& VectorB, const CVector& VectorC);

	float& operator() (int i, int j)
	{
		return (CRMatrix3[j][i]);
	}

	const float& operator() (int i, int j) const
	{
		return (CRMatrix3[j][i]);
	}

	CVector& operator [](int j)
	{
		return (*reinterpret_cast<CVector*>(CRMatrix3[j]));
	}

	const CVector& operator [] (int j) const
	{
		return (*reinterpret_cast<const CVector*>(CRMatrix3[j]));
	}

public:

	//Method for adding two matrices together.
	CMatrix3D AddMatrices(const CMatrix3D & MatrixOne, const CMatrix3D & MatrixTwo);

	static CMatrix3D SubtractMatrices(const CMatrix3D& MatrixOne, const CMatrix3D& MatrixTwo);

public:

	static float Determinant(const CMatrix3D& matrix);

};

