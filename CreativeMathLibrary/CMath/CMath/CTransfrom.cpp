#include "CTransfrom.h"

STransform4D::STransform4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23)
{
	CRMatrix4D[0][0] = n00; CRMatrix4D[0][1] = n10; CRMatrix4D[0][2] = n20;
	CRMatrix4D[1][0] = n01; CRMatrix4D[1][1] = n11; CRMatrix4D[1][2] = n21;
	CRMatrix4D[2][0] = n02; CRMatrix4D[2][1] = n12; CRMatrix4D[2][2] = n22;
	CRMatrix4D[3][0] = n03; CRMatrix4D[3][1] = n13; CRMatrix4D[3][2] = n23;


	CRMatrix4D[0][3] = CRMatrix4D[1][3] = CRMatrix4D[2][3] = 0.0f;
	CRMatrix4D[3][3] = 1.0f;
}

STransform4D::STransform4D(const CVector& VectorA, const CVector& VectorB, const CVector& VectorC, const CPoint3D& Point)
{
	CRMatrix4D[0][0] = VectorA.x; CRMatrix4D[0][1] = VectorA.y; CRMatrix4D[0][2] = VectorA.z;
	CRMatrix4D[1][0] = VectorB.x; CRMatrix4D[1][1] = VectorB.y; CRMatrix4D[1][2] = VectorB.z;
	CRMatrix4D[2][0] = VectorC.x; CRMatrix4D[2][1] = VectorC.y; CRMatrix4D[2][2] = VectorC.z;
	CRMatrix4D[3][0] = Point.x; CRMatrix4D[3][1] = Point.y; CRMatrix4D[3][2] = Point.z;

	CRMatrix4D[0][3] = CRMatrix4D[1][3] = CRMatrix4D[2][3] = 0.0f;
	CRMatrix4D[3][3] = 1.0f;
}

STransform4D::STransform4D(int a, int b)
{
}

CVector& STransform4D::operator[](int j)
{
	return (*reinterpret_cast<CVector*>(CRMatrix4D[j]));
}

const CVector& STransform4D::operator[](int j) const
{
	return (*reinterpret_cast<const CVector*>(CRMatrix4D[j]));
}

CPoint3D STransform4D::GetTranslation(void) const
{
	return (*reinterpret_cast<const CPoint3D*>(CRMatrix4D[3]));
}

void STransform4D::SetTranslation(const CPoint3D& Point)
{
	CRMatrix4D[3][0] = Point.x;
	CRMatrix4D[3][1] = Point.y;
	CRMatrix4D[3][2] = Point.z;
}

STransform4D STransform4D::MakeReflection(const SPlane4D& Face)
{
	return STransform4D();
}

STransform4D STransform4D::Inverse(const STransform4D& H)
{
	const CVector& VectorA = H[0];
	const CVector& VectorB = H[1];
	const CVector& VectorC = H[2];
	const CVector& VectorD = H[3];


	CVector S = CVector::CrossProduct(VectorA, VectorB);
	CVector t = CVector::CrossProduct(VectorC, VectorD);

	const float InvDet = 1.0f / CVector::ScalarProduct(S, VectorC);

	S *= InvDet;
	t *= InvDet;

	const CVector Vector = VectorC * InvDet;

	CVector R0 = CVector::CrossProduct(VectorB, Vector);
	CVector R1 = CVector::CrossProduct(Vector, VectorA);

	return(STransform4D(R0.x, R0.y, R0.z, -CVector::ScalarProduct(VectorB, t),
		R1.x, R1.y, R1.z, static_cast<float>(CVector::ScalarProduct(VectorA, t)),
		S.x, S.y, S.z, -CVector::ScalarProduct(VectorD, S)));
}

CVector operator*(const CVector& Normal, const STransform4D& Matrix)
{
	return CVector();
}

CVector operator*(const STransform4D& TransformA, const CVector& VectorA)
{
	return CVector();
}

STransform4D operator*(const STransform4D& TransformA, const STransform4D& TransfromB)
{
	return STransform4D();
}

CPoint3D operator*(const STransform4D& TransformA, const CPoint3D& PointA)
{
	return CPoint3D();
}
