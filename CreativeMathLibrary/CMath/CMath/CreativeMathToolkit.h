#include <math.h>

#pragma once

#ifdef CREATIVE_EXPORTS
	#define CMATH_API __declspec(dllexport)
#else
	#define CMATH_API __declspec(dllimport)
#endif

// Creative Math Macros

// Constant values and useful math components
#define Pi 3.14159265
#define MAXIMUM_NUMBERALLOWED 90000000
#define MINIMUM_NUMBERALLOWED -90000000
#define MAXIMUM_FLOATALLOWED 3.33333333e+39f
#define CR_DELTA 0.00001f

#define NINTY_DEGREES 90.0f
#define ONEEIGHTY_DEGREES 180.0f
#define TWOSEVENTY_DEGREES 270.0f

#define SFFLOAT_SQRT sqrtf
#define DOUBLE_SQRT sqrt
#define SLFLOAT_SQRT sqrtl

#define Absolute_float fabs

class SVector3;

//Different ways of calculating our vectors magnitude, based on precision required.
template<class Generic>
inline float SMagnitude(const Generic& vector)
{
	return (SFFLOAT_SQRT(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

template<class Generic>
inline double DMagnitude(const Generic& vector)
{
	return (DOUBLE_SQRT(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

enum class ETypeOfMagnititude
{ 
	SMagnititude = 1,
	DMagnititude = 2,
	LFMagnititude = 3
};


// Conversion Functions
template<class Generic>
auto RadiansToDegrees(Generic const& RadianValue) -> decltype(RadianValue * (ONEEIGHTY_DEGREES / Pi))
{
	return RadianValue  * (ONEEIGHTY_DEGREES / Pi);
}


template<class Generic>
auto DegreesToRadians(Generic const& DegreeValue) -> decltype(DegreeValue* (Pi / ONEEIGHTY_DEGREES))
{
	return DegreeValue * (Pi / ONEEIGHTY_DEGREES);
}

