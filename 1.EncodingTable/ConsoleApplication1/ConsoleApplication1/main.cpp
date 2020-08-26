// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "CodeTable.h"

template<class T>
void doCode(byte * src, byte * dst, CodeTable<T> &ct) {
	for (int i = 0; src[i]; ++i)
		dst[i] = ct[src[i]];
}

int main()
{
	CodeTable<byte> ct(32, 255);
	CodeTable<byte> ct0(32, 255);
	for (int i = 0; i < 32; ++i) {
		byte b = ct['a' + i];
		ct['a' + i] = ct['z' - i];
		ct['z' - 1] = b;
	}

	byte *src = (byte*)"Hello, World!";
	byte *dst = new byte[std::strlen((char*)src) + 1];
	memset(dst, 0, std::strlen((char*)src) + 1);
	doCode(src, dst, ct);
	std::cout << "Source str: " << src << "\n"
		<< "Destination str: " << dst << "\n";
	doCode(dst, dst, ct);
	std::cout << "Source str: " << src << "\n"
		<< "Destination str: " << dst << "\n";
    return 0;
}

