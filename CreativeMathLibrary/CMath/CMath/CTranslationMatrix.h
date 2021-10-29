#pragma once
#include "CMatrix3.h"


class CTranslationMatrix : public CMatrix3D
{
	CTranslationMatrix();
	~CTranslationMatrix();

	CTranslationMatrix(CTranslationMatrix & copyConstructor);
	CTranslationMatrix(CTranslationMatrix&&);

public:

	const float CosineExponent = 1.0f;
	const float ReflectionExponent = -2.0f;
	const float InvolutionExponent = 2.0f;

public:

	//Instance for Vec
	template <typename generic, typename GenericVector>
	CMatrix3D MakeRotation(generic translationUnit, const GenericVector & VectorA);


	template <typename generic>
	CMatrix3D MakeRotation(generic translationUnit, const CVector & VectorA);

	template<>
	CMatrix3D MakeRotation(float translationUnit, const CVector & VectorA);

public:
	static CMatrix3D MakeRotationX(float TranslationUnit);

	static CMatrix3D MakeRotationY(float TranslationUnit);

	static CMatrix3D MakeRotationZ(float TranslationUnit);

public:

	[[nodiscard]] CMatrix3D MakeReflection(const CVector & VectorA) const;

	//This makes an involution from a vector (When a function is it's own inverse - math function, not C++ function)
	[[nodiscard]] CMatrix3D MakeInvolution(const CVector & VectorA) const;
};


