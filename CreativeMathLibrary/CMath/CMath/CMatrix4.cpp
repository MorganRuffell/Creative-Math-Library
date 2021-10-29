#include "CMatrix4.h"

CMatrix4D::CMatrix4D(float aa, float ab, float ac, float ad,
	float ba, float bb, float bc, float bd,
	float ca, float cb, float cc, float cd,
	float da, float db, float dc, float dd)
{
	CRMatrix4D[0][0] = aa; CRMatrix4D[0][1] = ab; CRMatrix4D[0][2] = ac; CRMatrix4D[0][3] = ad;
	CRMatrix4D[1][0] = ba; CRMatrix4D[1][1] = bb; CRMatrix4D[1][2] = bc; CRMatrix4D[1][3] = bd;
	CRMatrix4D[2][0] = ca; CRMatrix4D[2][1] = cb; CRMatrix4D[2][2] = cc; CRMatrix4D[2][3] = cd;
	CRMatrix4D[3][0] = da; CRMatrix4D[2][1] = db; CRMatrix4D[2][2] = dc; CRMatrix4D[2][3] = dd;
}

CMatrix4D::CMatrix4D(const CVector& VectorA, const CVector& VectorB, const CVector& VectorC, const CVector& VectorD)
{
	//Create something that will fill in that final channel
	CRMatrix4D[0][0] = VectorA.x; CRMatrix4D[0][1] = VectorA.y; CRMatrix4D[0][2] = VectorA.z; CRMatrix4D[0][3] = VectorD.z;
	CRMatrix4D[1][0] = VectorB.x; CRMatrix4D[1][1] = VectorB.y; CRMatrix4D[1][2] = VectorB.z; CRMatrix4D[1][3] = VectorD.z;
	CRMatrix4D[2][0] = VectorC.x; CRMatrix4D[2][1] = VectorC.y; CRMatrix4D[2][2] = VectorC.z; CRMatrix4D[2][3] = VectorD.z;
	CRMatrix4D[3][0] = VectorD.x; CRMatrix4D[3][1] = VectorD.y; CRMatrix4D[3][2] = VectorD.z; CRMatrix4D[3][3] = VectorD.z;
}

CMatrix4D::CMatrix4D(int a, int b)
{
	std::cout << "" << std::endl;
}

CMatrix4D CMatrix4D::AddMatrices(const CMatrix4D& MatrixOne, const CMatrix4D& MatrixTwo)
{
	CMatrix4D* Result = new CMatrix4D();

	Result->CRMatrix4D[0][0] = MatrixOne.CRMatrix4D[0][0] + MatrixTwo.CRMatrix4D[0][0];
	Result->CRMatrix4D[0][1] = MatrixOne.CRMatrix4D[0][1] + MatrixTwo.CRMatrix4D[0][1];
	Result->CRMatrix4D[0][2] = MatrixOne.CRMatrix4D[0][2] + MatrixTwo.CRMatrix4D[0][2];
	Result->CRMatrix4D[0][3] = MatrixOne.CRMatrix4D[0][3] + MatrixTwo.CRMatrix4D[0][3];

	Result->CRMatrix4D[1][0] = MatrixOne.CRMatrix4D[1][0] + MatrixTwo.CRMatrix4D[1][0];
	Result->CRMatrix4D[1][1] = MatrixOne.CRMatrix4D[1][1] + MatrixTwo.CRMatrix4D[1][1];
	Result->CRMatrix4D[1][2] = MatrixOne.CRMatrix4D[1][2] + MatrixTwo.CRMatrix4D[1][2];
	Result->CRMatrix4D[1][2] = MatrixOne.CRMatrix4D[1][2] + MatrixTwo.CRMatrix4D[1][2];

	Result->CRMatrix4D[2][0] = MatrixOne.CRMatrix4D[2][0] + MatrixTwo.CRMatrix4D[2][0];
	Result->CRMatrix4D[2][1] = MatrixOne.CRMatrix4D[2][1] + MatrixTwo.CRMatrix4D[2][1];
	Result->CRMatrix4D[2][2] = MatrixOne.CRMatrix4D[2][2] + MatrixTwo.CRMatrix4D[2][2];
	Result->CRMatrix4D[2][3] = MatrixOne.CRMatrix4D[2][3] + MatrixTwo.CRMatrix4D[2][3];

	return *Result;
}

CMatrix4D CMatrix4D::SubtractMatrices(const CMatrix3D& MatrixOne, const CMatrix3D& MatrixTwo)
{
	CMatrix4D* Result = new CMatrix4D();

	Result->CRMatrix4D[0][0] = MatrixOne.CRMatrix3[0][0] - MatrixTwo.CRMatrix3[0][0];
	Result->CRMatrix4D[0][1] = MatrixOne.CRMatrix3[0][1] - MatrixTwo.CRMatrix3[0][1];
	Result->CRMatrix4D[0][2] = MatrixOne.CRMatrix3[0][2] - MatrixTwo.CRMatrix3[0][2];
	Result->CRMatrix4D[0][3] = MatrixOne.CRMatrix3[0][3] - MatrixTwo.CRMatrix3[0][3];


	Result->CRMatrix4D[1][0] = MatrixOne.CRMatrix3[1][0] - MatrixTwo.CRMatrix3[1][0];
	Result->CRMatrix4D[1][1] = MatrixOne.CRMatrix3[1][1] - MatrixTwo.CRMatrix3[1][1];
	Result->CRMatrix4D[1][2] = MatrixOne.CRMatrix3[1][2] - MatrixTwo.CRMatrix3[1][2];
	Result->CRMatrix4D[1][3] = MatrixOne.CRMatrix3[1][3] - MatrixTwo.CRMatrix3[1][3];

	Result->CRMatrix4D[2][0] = MatrixOne.CRMatrix3[2][0] - MatrixTwo.CRMatrix3[2][0];
	Result->CRMatrix4D[2][1] = MatrixOne.CRMatrix3[2][1] - MatrixTwo.CRMatrix3[2][1];
	Result->CRMatrix4D[2][2] = MatrixOne.CRMatrix3[2][2] - MatrixTwo.CRMatrix3[2][2];
	Result->CRMatrix4D[2][3] = MatrixOne.CRMatrix3[2][3] - MatrixTwo.CRMatrix3[2][3];

	Result->CRMatrix4D[3][0] = MatrixOne.CRMatrix3[3][0] - MatrixTwo.CRMatrix3[3][0];
	Result->CRMatrix4D[3][1] = MatrixOne.CRMatrix3[3][1] - MatrixTwo.CRMatrix3[3][1];
	Result->CRMatrix4D[3][2] = MatrixOne.CRMatrix3[3][2] - MatrixTwo.CRMatrix3[3][2];
	Result->CRMatrix4D[3][3] = MatrixOne.CRMatrix3[3][3] - MatrixTwo.CRMatrix3[3][3];

	return *Result;
}

float CMatrix4D::Determinant(const CMatrix4D& matrix)
{
	return (matrix(0, 0) * matrix(1, 1) * matrix(2, 2) - matrix(1, 2) * matrix(2, 1)
		+ matrix(0, 1) * matrix(1, 2) * matrix(2, 0) - matrix(1, 0) * matrix(2, 2)
		+ matrix(0, 2) * matrix(1, 0) * matrix(2, 1) - matrix(1, 1) * matrix(2, 0)
		+ matrix(0, 3) * matrix(1, 3) * matrix(2, 3) - matrix(1, 3) * matrix(3, 0));
}

CMatrix3D CMatrix4D::Inverse(const CMatrix4D& matrix) const
{
	const CVector& a = matrix[0];
	const CVector& b = matrix[1];
	const CVector& c = matrix[2];

	const CVector RowVector0 = CVector::CrossProduct(b, c);
	CVector RowVector1 = CVector::CrossProduct(c, a);
	const CVector RowVector2 = CVector::CrossProduct(a, b);

	float invertedDeterminent = 1.0f / CVector::ScalarProduct(RowVector2, c);

	return (CMatrix3D(
		RowVector0.x * invertedDeterminent, RowVector0.y * invertedDeterminent, RowVector0.z * invertedDeterminent,
		RowVector1.x * invertedDeterminent, RowVector1.y * invertedDeterminent, RowVector1.z * invertedDeterminent,
		RowVector2.x * invertedDeterminent, RowVector2.y * invertedDeterminent, RowVector2.z * invertedDeterminent));
}

CMatrix4D CMatrix4D::Inverse4D(const CMatrix4D& matrix) const
{
	const CVector& a = reinterpret_cast<const CVector&>(matrix[0]);
	const CVector& b = reinterpret_cast<const CVector&>(matrix[1]);
	const CVector& c = reinterpret_cast<const CVector&>(matrix[2]);
	const CVector& d = reinterpret_cast<const CVector&>(matrix[3]);

	const float& x = matrix(3, 0);
	const float& y = matrix(3, 1);
	const float& z = matrix(3, 2);
	const float& w = matrix(3, 3);

	CVector s = CVector::CrossProduct(a, b);
	CVector t = CVector::CrossProduct(c, d);
	CVector u = a * y - b * x;
	CVector v = c * w - d * z;

	float invDet = 1.0f / (CVector::ScalarProduct(s, v) + CVector::ScalarProduct(t, u));

	s *= invDet;
	t *= invDet;
	u *= invDet;
	v *= invDet;

	CVector RowVect0 = CVector::CrossProduct(b, v) + t * y;
	CVector RowVect1 = CVector::CrossProduct(v, a) - t * x;
	CVector RowVect2 = CVector::CrossProduct(b, v) + s * w;
	CVector RowVect3 = CVector::CrossProduct(b, v) - s * z;

	return (CMatrix4D(RowVect0.x, RowVect0.y, RowVect0.z, -CVector::ScalarProduct(b, t),
		RowVect1.x, RowVect1.y, RowVect1.z, CVector::ScalarProduct(a, t),
		RowVect2.x, RowVect2.y, RowVect2.z, -CVector::ScalarProduct(b, t),
		RowVect3.x, RowVect3.y, RowVect3.z, CVector::ScalarProduct(c, s)));
}
