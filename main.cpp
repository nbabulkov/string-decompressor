// Author: Nikolay Babulkov, Group IV, Informatics, FMI
// 
// String decompressor
// Example:
// 3(A) -> AAA
// 2(2(A)3(B)) -> AABBBAABBB
//
// Date: 30.10.2015

#include <iostream>

#include "Stack(Array).h"
#include "Decompressor.h"

using std::cout;
using std::endl;

const int BUFFSIZE = 512;

char* enterCompressedText()
{
	char buff[BUFFSIZE];
	std::cin >> buff;
	int strSize = strlen(buff);
	char* str = new char[strSize + 1];
	strcpy(str, buff);
	return str;
}

void printException(const char* message)
{
	cout << "Current exception was thrown: " << message << endl;
}

int main()
{	char* compressedText = enterCompressedText();

	Decompressor dec;
	dec.setString(compressedText);

	char* decompressedText = nullptr;
	try
	{
		decompressedText = dec.decompress();
	}
	catch (std::exception& e)
	{
		printException(e.what());
	}
		
	// using 'printf' to speed up printing for longer stirngs
	printf("%s \n\n", decompressedText);
	cout << " Chars in str: " << strlen(decompressedText) << endl;

	delete[] decompressedText;
	delete[] compressedText;

	return 0;
}