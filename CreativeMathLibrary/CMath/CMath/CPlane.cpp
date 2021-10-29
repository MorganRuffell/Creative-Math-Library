#pragma once

#include "CPlane.h"

class CVector;


SPlane4D::SPlane4D(float Nrm_x, float Nrm_y, float Nrm_z, float _w)
{
	x = Nrm_x;
	y = Nrm_y;
	z = Nrm_z;
	w = _w;
}

SPlane4D::SPlane4D(CVector NormalVector, float _w)
{
	x = NormalVector.x;
	y = NormalVector.y;
	z = NormalVector.z;
	w = _w;
}

CVector& SPlane4D::GetNormal() const
{
	return(reinterpret_cast<const CVector&>(x));
}

float SPlane4D::ScalarProduct(const SPlane4D& Face, const CPoint3D& Point)
{
	return (Face.x * Point.x + Face.y * Point.y + Face.z * Point.z);
}

SPlane4D(CVector& NormalVector, float _w)
{
	x = NormalVector.x;
	y = NormalVector.y;
	z = NormalVector.z;
	w = _w;
}

template<class GenericClass>
float SPlane4D::ScalarProduct(const GenericClass& Face, const CVector& Vector)
{
	return (Face.x * Vector.x + Face.y * Vector.y + Face.z * Vector.z);
}
