#include "CMath.h"
#include <exception>
#include <iostream>

CMath::CMath()
= default;

CMath::~CMath()
= default;

int CMath::Multiply(int x, int result[], int resultSize)
{
	auto Carry = 0;


	for (int i = 0; i < resultSize; i++)
	{
		int Product = result[i] * x + Carry;
		result[i] = Product % 10;

		Carry = Product / 10;
	}

	while (Carry)
	{
		result[resultSize] = Carry % 10;
		Carry = Carry / 10;
		resultSize++;
	}

	return resultSize;

}


template <typename Generic>
Generic CMath::CRaiseByPower(Generic ValueToRaise, Generic ExponentInteger)
{
	if (ValueToRaise == 0)
	{
		std::cout << "Value is equal to zero. You cannot multiply 0 by an integer!";
		return -1;
	}

	Generic result[MAXIMUM_NUMBERALLOWED];
	Generic resultSize = 0;
	Generic temp = ValueToRaise;

	while (temp != 0)
	{
		result[resultSize++] = temp % 10;
		temp = temp / 10;
	}

	return result;
}
