#include <iostream>
#include <stdlib.h>
#include "Decompressor.h"

Decompressor::Decompressor()
{
	currPos = nullptr;
}

Decompressor::~Decompressor()
{
	
}

///
/// Main Function
///
char* Decompressor::decompress()
{
	// the last element to be poped with the final string
	Element first;
	decStack.push(first);

	int openedBrackets = 0;

	// recognising the symbols in the initial string and 
	// arranging them in the elements of stack in the current obejct
	while (*currPos != '\0')
	{
		if (isDigit(*currPos))
			readNumber();
		else if (isLetter(*currPos))
			readLetters();
		else if (*currPos == '(')
		{
			++currPos;
			++openedBrackets;
		}
		else if (*currPos == ')')
		{
			++currPos;
			--openedBrackets;
			Element currEl = decStack.pop();
			addToNextElement(currEl);
		}
		else
			throw std::exception("Unrecognisable symbol encountered!");
	}

	if (openedBrackets != 0)
		throw std::exception("Wrong notation!");

	return createStrFrom(decStack.pop());
}


///
/// Help Functions
///
void Decompressor::readNumber()
{
	Element currEl;
	currEl.times = atoi(currPos);
	decStack.push(currEl);
	skipDigits();
}

void Decompressor::readLetters()
{
	Element& currEl = decStack.top();
	if (currEl.text == nullptr)
		currEl.text = copyLetters();
	else
	{
		char* copied = copyLetters();
		char* temp = concat(currEl.text, copied);
		delete[] currEl.text;
		delete[] copied;
		currEl.text = temp;
	}
}

// adds the already resolved element
// to the one under it in the stack
void Decompressor::addToNextElement(const Element& currEl)
{
	Element& topEl = decStack.top();
	if (topEl.text == nullptr)
	{
		topEl.text = createStrFrom(currEl);
	}
	else
	{
		char* old = createStrFrom(currEl);
		char* tempStr = concat(topEl.text, old);
		delete[] topEl.text;
		delete[] old;
		topEl.text = tempStr;
	}
}

void Decompressor::setString(char* str)
{
	currPos = str;
}

void Decompressor::skipDigits()
{
	while (isDigit(*currPos))
		++currPos;
}

void Decompressor::skipLetters()
{
	while (isLetter(*currPos))
		++currPos;
}

bool Decompressor::isDigit(const char c) const
{
	return c >= '0' && c <= '9';
}

bool Decompressor::isLetter(const char c) const
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

///
/// Functions operating with strings
///
// returns the the following letters on the pointer 'currPos'
char* Decompressor::copyLetters()
{
	char* start = currPos;
	skipLetters();

	int size = (int)(currPos - start);
	char* newStr = new char[size + 1];
	strncpy(newStr, start, size);
	newStr[size] = '\0';
	return newStr;
}

// Extracts string from the 'el' and returns it multiplied by the times in 'el'
char* Decompressor::createStrFrom(const Element& el) const
{
	int currSize = strlen(el.text) * el.times + 1;
	char* currStr = new char[currSize];
	strcpy(currStr, el.text);
	for (int i = 1; i < el.times; ++i)
		strcat(currStr, el.text);
	return currStr;
}

char* Decompressor::concat(const char* firstStr, const char* secondStr) const
{
	int size = strlen(firstStr) + strlen(secondStr) + 1;
	char* newStr = new char[size];
	strcpy(newStr, firstStr);
	strcat(newStr, secondStr);
	return newStr;
}
