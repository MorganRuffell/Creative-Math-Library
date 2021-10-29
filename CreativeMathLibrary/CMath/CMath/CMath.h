// Creative Engine 2021 (c) Ruffell Interactive -- All Rights reserved   
#pragma once

#include "CreativeMathToolkit.h"


#pragma once

class CMATH_API CMath
{

public:

	//Constructor and destructor
	CMath();
	~CMath();

public:

	template <typename Generic>
	Generic CFloor(Generic ValueToFloor);

	template <typename Generic>
	Generic* CFloor(Generic* ValueToFloor);

	template<>
	float CFloor(float ValueToFloor);

	template<>
	int CFloor(int ValueToFloor);

public:

	int Multiply(int x, int result[], int resultSize);

	template<typename Generic>
	Generic CRaiseByPower(Generic ValueToRaise, Generic ExponentInteger);

	template<>
	int CRaiseByPower(int ValueToRaise, int ExponentInteger);

	template<>
	float CRaiseByPower(float ValueToRaise, float ExponentInteger);


};


