#include "CTranslationMatrix.h"

CTranslationMatrix::CTranslationMatrix()
{
}

CTranslationMatrix::~CTranslationMatrix()
{
}

CTranslationMatrix::CTranslationMatrix(CTranslationMatrix& copyConstructor)
{
}

CTranslationMatrix::CTranslationMatrix(CTranslationMatrix&&)
{
}

template <>
CMatrix3D CTranslationMatrix::MakeRotation<float>(float translationUnit, const CVector& VectorA)
{
	const float cosineOfTranslationUnit = cos(translationUnit);
	float sineOfTranslationUnit = sin(translationUnit);
	const float OneMinusCosine = CosineExponent - cosineOfTranslationUnit;

	float x = VectorA.x * OneMinusCosine;
	float y = VectorA.y * OneMinusCosine;
	float z = VectorA.z * OneMinusCosine;

	float xy = x * VectorA.y;
	float xz = x * VectorA.z;
	float yz = y * VectorA.z;


	return CMatrix3D(cosineOfTranslationUnit + x * VectorA.x, xy - sineOfTranslationUnit * VectorA.z, xz + sineOfTranslationUnit * VectorA.y,
	                 xy + sineOfTranslationUnit * VectorA.z, cosineOfTranslationUnit + y * VectorA.y, yz - sineOfTranslationUnit * VectorA.x,
	                 xz - sineOfTranslationUnit * VectorA.y, yz + sineOfTranslationUnit * VectorA.x, cosineOfTranslationUnit + z * VectorA.z);
}

CMatrix3D CTranslationMatrix::MakeRotationX(float TranslationUnit)
{
	const float CosineOfTranslationUnit = static_cast<float>(cos(TranslationUnit));
	const float SineOfTranslationUnit = static_cast<float>(sin(TranslationUnit));

	return (CMatrix3D(1.0f, 0.0f, 0.0f,
	                  0.0f, CosineOfTranslationUnit, -SineOfTranslationUnit,
	                  0.0f, SineOfTranslationUnit, CosineOfTranslationUnit));
}

CMatrix3D CTranslationMatrix::MakeRotationY(float TranslationUnit)
{
	const float CosineOfTranslationUnit = cos(TranslationUnit);
	const float SineOfTranslationUnit = sin(TranslationUnit);

	return(CMatrix3D(CosineOfTranslationUnit, 0.0f, SineOfTranslationUnit,
	                 0.0f, 1.0f, 0.0f,
	                 -SineOfTranslationUnit, 0.0f, 1.0f));
}

CMatrix3D CTranslationMatrix::MakeRotationZ(float TranslationUnit)
{
	const float CosineOfTranslationUnit = cos(TranslationUnit);
	const float SineOfTransaltionUnit = sin(TranslationUnit);

	return (CMatrix3D(CosineOfTranslationUnit, 0.0f, 0.0f,
	                  0.0f, 1.0f, 0.0f,
	                  -SineOfTransaltionUnit, 0.0f, 1.0f));
}

CMatrix3D CTranslationMatrix::MakeReflection(const CVector& VectorA) const
{
	float x = VectorA.x * ReflectionExponent;
	float y = VectorA.y * ReflectionExponent;
	float z = VectorA.z * ReflectionExponent;
	float xy = x * VectorA.y;
	float xz = x * VectorA.z;
	float yz = y * VectorA.z;

	return (CMatrix3D(x * VectorA.x + 1.0f, xy, xz,
	                  xy, y * VectorA.y + 1.0f, yz,
	                  xz, yz, z * VectorA.z + 1.0f));
}

CMatrix3D CTranslationMatrix::MakeInvolution(const CVector& VectorA) const
{
	float x = VectorA.x * InvolutionExponent;
	float y = VectorA.y * InvolutionExponent;
	float z = VectorA.z * InvolutionExponent;
	float xy = x * VectorA.y;
	float xz = x * VectorA.z;
	float yz = y * VectorA.z;


	return (CMatrix3D(x * VectorA.x - 1.0f, xy, xz,
	                  xy, y * VectorA.y - 1.0f, yz,
	                  xz, yz, z * VectorA.z - 1.0f));
}

template <typename generic, typename GenericVector>
CMatrix3D CTranslationMatrix::MakeRotation(generic translationUnit, const GenericVector& VectorA)
{
	constexpr float cosineOfTranslationUnit = cos(translationUnit);
	float sineOfTranslationUnit = sin(translationUnit);
	const float OneMinusCosine = CosineExponent - cosineOfTranslationUnit;

	float x = VectorA.x * OneMinusCosine;
	float y = VectorA.y * OneMinusCosine;
	float z = VectorA.z * OneMinusCosine;

	float xy = x * VectorA.y;
	float xz = x * VectorA.z;
	float yz = y * VectorA.z;


	return CMatrix3D(cosineOfTranslationUnit + x * VectorA.x, xy - sineOfTranslationUnit * VectorA.z, xz + sineOfTranslationUnit * VectorA.y,
		xy + sineOfTranslationUnit * VectorA.z, cosineOfTranslationUnit + y * VectorA.y, yz - sineOfTranslationUnit * VectorA.x,
		xz - sineOfTranslationUnit * VectorA.y, yz + sineOfTranslationUnit * VectorA.x, cosineOfTranslationUnit + z * VectorA.z);
}

template <typename generic>
CMatrix3D CTranslationMatrix::MakeRotation(generic translationUnit, const CVector& VectorA)
{
	const float cosineOfTranslationUnit = cos(translationUnit);
	float sineOfTranslationUnit = sin(translationUnit);
	const float OneMinusCosine = CosineExponent - cosineOfTranslationUnit;

	float x = VectorA.x * OneMinusCosine;
	float y = VectorA.y * OneMinusCosine;
	float z = VectorA.z * OneMinusCosine;

	float xy = x * VectorA.y;
	float xz = x * VectorA.z;
	float yz = y * VectorA.z;


	return CMatrix3D(cosineOfTranslationUnit + x * VectorA.x, xy - sineOfTranslationUnit * VectorA.z, xz + sineOfTranslationUnit * VectorA.y,
	                 xy + sineOfTranslationUnit * VectorA.z, cosineOfTranslationUnit + y * VectorA.y, yz - sineOfTranslationUnit * VectorA.x,
	                 xz - sineOfTranslationUnit * VectorA.y, yz + sineOfTranslationUnit * VectorA.x, cosineOfTranslationUnit + z * VectorA.z);
}
