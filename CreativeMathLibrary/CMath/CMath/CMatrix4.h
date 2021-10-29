#pragma once

#include <iostream>
#include "CMatrix3.h"
#include "CreativeMathToolkit.h"
#include "CMatrix3.h"
#include "CVector.h"
#include "CPlane.h"

class CMatrix3D;
class CVector;

//Will look at using dependency injection to solve the inheritance problem!
class CMATH_API CMatrix4D
{
public:
	float CRMatrix4D[4][4]{};

public:

	CMatrix4D() = default;

	CMatrix4D(
		float aa, float ab, float ac, float ad,
		float ba, float bb, float bc, float bd,
		float ca, float cb, float cc, float cd,
		float da, float db, float dc, float dd);

	CMatrix4D(const CVector& VectorA, const CVector& VectorB, const CVector& VectorC, const CVector& VectorD);

	CMatrix4D(int a, int b);


	const int& operator() (int i, int j) const
	{
		return (CRMatrix4D[j][i]);
	}

	int operator()(int a, int b)
	{
		return (CRMatrix4D[a][b]);
	}

	CVector& operator [](int j)
	{
		return (*reinterpret_cast<CVector*>(CRMatrix4D[j]));
	}

	const CVector& operator [] (int j) const
	{
		return (*reinterpret_cast<const CVector*>(CRMatrix4D[j]));
	}

public:

	//Method for adding two matrices together.
	static CMatrix4D AddMatrices(const CMatrix4D& MatrixOne, const CMatrix4D& MatrixTwo);

	static CMatrix4D SubtractMatrices(const CMatrix3D& MatrixOne, const CMatrix3D& MatrixTwo);

public:
	static float Determinant(const CMatrix4D& matrix);


	CMatrix3D Inverse(const CMatrix4D& matrix) const;


public:

	CMatrix4D Inverse4D(const CMatrix4D& matrix) const;
};