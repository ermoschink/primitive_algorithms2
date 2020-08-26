// 2.Dynamic array.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DynamicArray.h"
#include <iostream>


int main()
{
	DynamicArray<int> arrInt;

	for (int i = 0; i < 20; ++i) {
		arrInt.Add(i + 50);
	}
	for (int i = 0; i < arrInt.size(); ++i) {
		std::cout << arrInt[i] << std::endl;
	}
	DynamicArray<char> arrChar;

	for (int i = 0; i < 20; ++i) {
		arrChar.Add('a' + i);
	}
	for (int i = 0; i < arrChar.size(); ++i) {
		std::cout << arrChar[i] << std::endl;
	}

	std::getchar();

    return 0;
}

