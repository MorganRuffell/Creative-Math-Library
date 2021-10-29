#pragma once

#include "CreativeMathToolkit.h"
#include "CTransfrom.h"
#include "Parent/CObject.h"
#include "CVector.h"
#include "CPoint.h"

class CVector;

class CMATH_API SPlane4D
{
public:

	float x, y, z, w;


public:

	SPlane4D() = default;

	SPlane4D(float Nrm_x, float Nrm_y, float Nrm_z, float _w);

	SPlane4D(CVector NormalVector, float _w);

	const CVector& GetNormal() const;

	template<class GenericClass>
	float ScalarProduct(const GenericClass& Face, const CVector& Vector);

	float ScalarProduct(const SPlane4D& Face, const CPoint3D& Point);

	bool IntersectLinePlane(const CPoint3D& PointA, const CVector& VectorA, const SPlane4D& Face, CPoint3D* PointB)
	{
		float FloatVector = ScalarProduct(Face, VectorA);

		//This gets the absolute value of the scalar product of the face and the the VectorA -- absolute values are making it positive ;)
		if (fabs(FloatVector) > FLT_MIN)
		{
			//Todo remove one implementation
			*PointB = (PointA - VectorA) * (ScalarProduct(Face, PointA) / FloatVector);
			return(true);
		}

		return(false);
	}

	bool IntersectThreePlanes(const SPlane4D& PlaneA, const SPlane4D& PlaneB, const SPlane4D& PlaneC, CPoint3D* Point)
	{
		const CVector& Normal_1 = PlaneA.GetNormal();
		const CVector& Normal_2 = PlaneB.GetNormal();
		const CVector& Normal_3 = PlaneC.GetNormal();

		auto Normal12 = CVector::CrossProduct(Normal_1, Normal_2);
		float Determinate = ScalarProduct(Normal12, Normal_3);

		if (Absolute_float(Determinate) > FLT_MIN)
		{
			*Point = (CVector::CrossProduct(Normal_3, Normal_2) * PlaneA.w + ScalarProduct(Normal_1, Normal_3) * PlaneB.w - Normal12 * PlaneC.w / Determinate);
			return(true);
		}

		return(false);
	}

	bool IntersectTwoPlanes(const SPlane4D& PlaneA, const SPlane4D& PlaneB, CPoint3D* Plane, SVector3* VectorA)
	{
		const CVector& Normal1 = PlaneA.GetNormal();
		const CVector& Normal2 = PlaneB.GetNormal();

		//Originally this used to be VectorA - Why do none of my member methods show up??
		CVector NewValue = CVector::CrossProduct(Normal1, Normal2);
		float Determinate = CVector::ScalarProduct(NewValue, NewValue);
	}


	friend CVector operator+(CVector& A, float b);

public:

};


//inline SPlane4D operator* (const SPlane4D& Face, const STransform4D& TransformMatrix)
//{
//
//	return(SPlane4D(Face.x * TransformMatrix(0, 0) + Face.y * TransformMatrix(1, 0) + Face.z * TransformMatrix(2, 0),
//					Face.x * TransformMatrix(0, 1) + Face.y * TransformMatrix(1, 1) + Face.z * TransformMatrix(2,1),
//					Face.x * TransformMatrix(0, 2) + Face.y * TransformMatrix(1, 2) + Face.z * TransformMatrix(2, 2),
//					Face.x * TransformMatrix(0, 3) + Face.y * TransformMatrix(1, 3) + Face.z * TransformMatrix(2, 3) + Face.w ));
//}
//

