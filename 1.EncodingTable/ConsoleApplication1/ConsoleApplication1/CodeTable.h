#pragma once
#include <stdexcept>

typedef unsigned char byte;
template<class T>
class CodeTable
{
	T lBound;
	T hBound;
	T *array;
public:
	CodeTable(T low, T high, T * iniTable = 0) {
		if ((hBound = high) < (lBound = low))
			throw std::out_of_range("lower bound is higher than upper one");
		array = new T[high - low + 1];

		for (byte code = lBound; code < hBound; ++code)
			array[code - lBound] = code;

		if (iniTable)
			for (int i = 0; i < high - lBound && iniTable[i]; ++i)
				array[i] = iniTable[i];

	}
	CodeTable(const CodeTable & s) {
		array = new T[(hBound = s.hBound) - (lBound = s.lBound) + 1];

		for (T code = lBound; code < hBound; ++code)
			array[code - lBound] = s.array[code - lBound];
	}


	virtual ~CodeTable() {

		delete[]array;
	}

	T& operator[](T index) {
		if (index < lBound || index > hBound)
			throw std::out_of_range("index of range");
		return array[index - lBound];
	}

};

