#pragma once

#include "Source/CMath/CMatrix3.h"


class CScaleMatrix
{

	CScaleMatrix() = default;
	~CScaleMatrix() = default;

	CScaleMatrix(CScaleMatrix& copyConstructor) = delete;
	CScaleMatrix(CScaleMatrix&&) = delete;

public:

	template<typename Generic>
	static CMatrix3D MakeScaleByEcludian(Generic x, Generic y, Generic z)
	{
		return(CMatrix3D(x, 0.0f, 0.0f, 0.0f, y, 0.0f, 0.0f, z));
	}

	template<typename Generic>
	static CMatrix3D MakeScale(Generic Scalar, const CVector& VectorA)
	{
		Scalar -= 1;

		const Generic x = VectorA.x * Scalar;
		const Generic y = VectorA.y * Scalar;
		const Generic z = VectorA.z * Scalar;
		float xy = x * VectorA.y;
		float xz = x * VectorA.z;
		float yz = y * VectorA.z;

		return (CMatrix3D(x * VectorA.z + 1, xy, xz,
			xy, y * VectorA.y + 1, yz,
			xz, yz, z * VectorA.z + 1));
	}

	template<>
	static CMatrix3D MakeScale(float Scalar, const CVector& VectorA)
	{
		Scalar -= 1.0f;

		float x = VectorA.x * Scalar;
		float y = VectorA.y * Scalar;
		float z = VectorA.z * Scalar;
		float xy = x * VectorA.y;
		float xz = x * VectorA.z;
		float yz = y * VectorA.z;

		return (CMatrix3D(x * VectorA.z + 1.0f, xy, xz,
			xy, y * VectorA.y + 1.0f, yz,
			xz, yz, z * VectorA.z + 1.0f));
	}

	template<>
	static CMatrix3D MakeScale(int Scalar, const CVector& VectorA)
	{
		Scalar -= 1;

		int x = VectorA.x * Scalar;
		int y = VectorA.y * Scalar;
		int z = VectorA.z * Scalar;
		float xy = x * VectorA.y;
		float xz = x * VectorA.z;
		float yz = y * VectorA.z;

		return (CMatrix3D(x * VectorA.z + 1, xy, xz,
			xy, y * VectorA.y + 1, yz,
			xz, yz, z * VectorA.z + 1));
	}


public:

	//This is a skew scale transformation, we scale along the skew angle transformation

	template<typename GenericIntegral>
	CMatrix3D MakeSkew(GenericIntegral SkewAngle, const CVector& VectorA, const CVector& VectorB, bool UseDoublePrecision)
	{
		if (UseDoublePrecision)
		{
			SkewAngle = tan(SkewAngle);
		}
		else
		{
			SkewAngle = tanf(SkewAngle);
		}

		GenericIntegral x = VectorA.x * SkewAngle;
		GenericIntegral y = VectorA.y * SkewAngle;
		GenericIntegral z = VectorA.z * SkewAngle;

		return CMatrix3D(x * VectorB.x + 1.0f, x * VectorB.y, x * VectorB.z,
			y * VectorB.y, y * VectorB.y + 1.0f, y * VectorB.z,
			z * VectorB.x, z * VectorB.y, z * VectorB.z + 1.0f);
	}

	template<>
	CMatrix3D MakeSkew(float SkewAngle, const CVector& VectorA, const CVector& VectorB, bool UseDoublePrecision)
	{
		if (UseDoublePrecision)
		{
			SkewAngle = tan(SkewAngle);
		}
		else
		{
			SkewAngle = tanf(SkewAngle);
		}

		float x = VectorA.x * SkewAngle;
		float y = VectorA.y * SkewAngle;
		float z = VectorA.z * SkewAngle;

		return CMatrix3D(x * VectorB.x + 1.0f, x * VectorB.y, x * VectorB.z,
			y * VectorB.y, y * VectorB.y + 1.0f, y * VectorB.z,
			z * VectorB.x, z * VectorB.y, z * VectorB.z + 1.0f);
	}

	template<>
	CMatrix3D MakeSkew(double SkewAngle, const CVector& VectorA, const CVector& VectorB, bool UseDoublePrecision)
	{
		if (UseDoublePrecision)
		{
			SkewAngle = tan(SkewAngle);
		}
		else
		{
			SkewAngle = tanf(SkewAngle);
		}

		double x = VectorA.x * SkewAngle;
		double y = VectorA.y * SkewAngle;
		double z = VectorA.z * SkewAngle;

		return CMatrix3D(x * VectorB.x + 1.0f, x * VectorB.y, x * VectorB.z,
			y * VectorB.y, y * VectorB.y + 1.0f, y * VectorB.z,
			z * VectorB.x, z * VectorB.y, z * VectorB.z + 1.0f);
	}


};

