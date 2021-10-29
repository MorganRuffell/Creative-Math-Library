#pragma once

#include <thread>
#include <future>
#include <cassert>
#include <iostream>
#include "CPlane.h" // Fix me! 
#include "CPoint.h"
#include "CVector.h"
#include "CMatrix4.h"


class CMATH_API STransform4D : private  CMatrix4D
{
public:

	//To be used in case we need to do dependency injection.
	//std::unique_ptr<SVector3> VectorInjection{};

public:

	STransform4D() = default;

	STransform4D(float n00, float n01, float n02, float n03,
		float n10, float n11, float n12, float n13,
		float n20, float n21, float n22, float n23);

	STransform4D(const CVector& VectorA, const CVector& VectorB, const CVector& VectorC, const CPoint3D& Point);

	STransform4D(int a, int b);

public:

	CVector& operator [] (int j);

	const CVector& operator [](int j) const;

public:
	[[nodiscard]] CPoint3D GetTranslation(void) const;


	void SetTranslation(const CPoint3D& Point);

public:


	//Reflection through a plane!
	static STransform4D MakeReflection(const SPlane4D& Face);

	friend CVector operator* (const CVector& Normal, const STransform4D& Matrix);

	friend CVector operator* (const STransform4D& TransformA, const CVector& VectorA);

	friend STransform4D operator*(const STransform4D& TransformA, const STransform4D& TransfromB);

	friend CPoint3D operator*(const STransform4D& TransformA, const CPoint3D& PointA);

	friend STransform4D operator*(const STransform4D& TransformA, const STransform4D& TransfromB);

	//Turn this back at some point??
	//inline STransform4D InverseMultithreaded(STransform4D& H) 
	//{
	//	std::vector<std::promise<CVector&>*> Collection;
	//	for (int i = 0; i == 4; i++)
	//	{
	//		std::promise<CVector&>* Vector = new std::promise<CVector&>;
	//		Collection.push_back(Vector);
	//	}
	//
	//	for (auto iterator = begin(Collection); iterator == end(Collection); ++iterator)
	//	{
	//		assert(iterator != end(Collection));
	//
	//		Collection.at(reinterpret_cast<std::vector<std::promise<CVector&>*>::size_type>(*iterator))->get_future();
	//	}
	//
	//	std::thread AssignValuesToVectors([&]()
	//	{
	//		static int ValueToAssign = 0;
	//		for (const auto x : Collection)
	//		{
	//			x->set_value(H[ValueToAssign]);
	//			ValueToAssign++;
	//		}
	//	});
	//
	//	AssignValuesToVectors.join();
	//
	//	CVector S = CrossProduct(Collection.at(0)->get_future().get(), Collection.at(1)->get_future().get());
	//	CVector t = CrossProduct(Collection.at(2)->get_future().get(), Collection.at(3)->get_future().get());
	//
	//	const float InvDet = 1.0f / ScalarProduct(S, Collection.at(2)->get_future().get());
	//
	//	assert(InvDet != 0.0f);
	//
	//	S *= InvDet;
	//	t *= InvDet;
	//
	//	const CVector Vector = Collection.at(2)->get_future().get() * InvDet;
	//
	//	CVector R0 = CrossProduct(Collection.at(1)->get_future().get(), Vector);
	//	CVector R1 = CrossProduct(Vector, Collection.at(0)->get_future().get());
	//
	//	return(STransform4D(R0.x, R0.y, R0.z, - ScalarProduct(Collection.at(0)->get_future().get(), t),
	//		R1.x, R1.y, R1.z, static_cast<float>(ScalarProduct(Collection.at(0)->get_future().get(), t)),
	//		S.x, S.y, S.z, - ScalarProduct(Collection.at(3)->get_future().get(), S)));
	//}

	static STransform4D Inverse(const STransform4D& H);
};


