#include "CMatrix3.h"

template<typename generic>
inline CMatrix3D::CMatrix3D(generic aa, generic ab, generic ac, generic ba, generic bb, generic bc, generic ca, generic cb, generic cc)
{
	CRMatrix3[0][0] = aa; CRMatrix3[0][1] = ab; CRMatrix3[0][2] = ac;
	CRMatrix3[1][0] = ba; CRMatrix3[1][1] = bb; CRMatrix3[1][2] = bc;
	CRMatrix3[2][0] = ca; CRMatrix3[2][1] = cb; CRMatrix3[2][2] = cc;
}


CMatrix3D::CMatrix3D(
	float aa, float ab, float ac,
	float ba, float bb, float bc,
	float ca, float cb, float cc)
{
	CRMatrix3[0][0] = aa; CRMatrix3[0][1] = ab; CRMatrix3[0][2] = ac;
	CRMatrix3[1][0] = ba; CRMatrix3[1][1] = bb; CRMatrix3[1][2] = bc;
	CRMatrix3[2][0] = ca; CRMatrix3[2][1] = cb; CRMatrix3[2][2] = cc;

}

CMatrix3D::CMatrix3D(const CVector& VectorA, const CVector& VectorB, const CVector& VectorC)
{
	CRMatrix3[0][0] = VectorA.x; CRMatrix3[0][1] = VectorA.y; CRMatrix3[0][2] = VectorA.z;
	CRMatrix3[1][0] = VectorB.x; CRMatrix3[1][1] = VectorB.y; CRMatrix3[1][2] = VectorB.z;
	CRMatrix3[2][0] = VectorC.x; CRMatrix3[2][1] = VectorC.y; CRMatrix3[2][2] = VectorC.z;
}

CMatrix3D CMatrix3D::AddMatrices(const CMatrix3D& MatrixOne, const CMatrix3D& MatrixTwo)
{
	CMatrix3D* Result = new CMatrix3D();

	Result->CRMatrix3[0][0] = MatrixOne.CRMatrix3[0][0] + MatrixTwo.CRMatrix3[0][0];
	Result->CRMatrix3[0][1] = MatrixOne.CRMatrix3[0][1] + MatrixTwo.CRMatrix3[0][1];
	Result->CRMatrix3[0][2] = MatrixOne.CRMatrix3[0][2] + MatrixTwo.CRMatrix3[0][2];

	Result->CRMatrix3[1][0] = MatrixOne.CRMatrix3[1][0] + MatrixTwo.CRMatrix3[1][0];
	Result->CRMatrix3[1][1] = MatrixOne.CRMatrix3[1][1] + MatrixTwo.CRMatrix3[1][1];
	Result->CRMatrix3[1][2] = MatrixOne.CRMatrix3[1][2] + MatrixTwo.CRMatrix3[1][2];

	Result->CRMatrix3[2][0] = MatrixOne.CRMatrix3[2][0] + MatrixTwo.CRMatrix3[2][0];
	Result->CRMatrix3[2][1] = MatrixOne.CRMatrix3[2][1] + MatrixTwo.CRMatrix3[2][1];
	Result->CRMatrix3[2][2] = MatrixOne.CRMatrix3[2][2] + MatrixTwo.CRMatrix3[2][2];

	return *Result;
}

CMatrix3D CMatrix3D::SubtractMatrices(const CMatrix3D& MatrixOne, const CMatrix3D& MatrixTwo)
{
	CMatrix3D* Result = new CMatrix3D();

	Result->CRMatrix3[0][0] = MatrixOne.CRMatrix3[0][0] - MatrixTwo.CRMatrix3[0][0];
	Result->CRMatrix3[0][1] = MatrixOne.CRMatrix3[0][1] - MatrixTwo.CRMatrix3[0][1];
	Result->CRMatrix3[0][2] = MatrixOne.CRMatrix3[0][2] - MatrixTwo.CRMatrix3[0][2];

	Result->CRMatrix3[1][0] = MatrixOne.CRMatrix3[1][0] - MatrixTwo.CRMatrix3[1][0];
	Result->CRMatrix3[1][1] = MatrixOne.CRMatrix3[1][1] - MatrixTwo.CRMatrix3[1][1];
	Result->CRMatrix3[1][2] = MatrixOne.CRMatrix3[1][2] - MatrixTwo.CRMatrix3[1][2];

	Result->CRMatrix3[2][0] = MatrixOne.CRMatrix3[2][0] - MatrixTwo.CRMatrix3[2][0];
	Result->CRMatrix3[2][1] = MatrixOne.CRMatrix3[2][1] - MatrixTwo.CRMatrix3[2][1];
	Result->CRMatrix3[2][2] = MatrixOne.CRMatrix3[2][2] - MatrixTwo.CRMatrix3[2][2];

	return *Result;
}

float CMatrix3D::Determinant(const CMatrix3D& matrix)
{
	return (matrix(0, 0) * matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1)
		+ matrix(0, 1) * matrix(1, 2) * matrix(2, 0) - matrix(1, 0) * matrix(2, 2)
		+ matrix(0, 2) * matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0));
}
