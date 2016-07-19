#pragma once
#include "Element.h"
#include "Stack(Array).h"

class Decompressor
{
private:
	char* currPos;
	StackA decStack;

public:
	Decompressor();
	~Decompressor();

public:
	char* decompress();

public:
	void readNumber();
	void readLetters();
	void addToNextElement(const Element&);

public:
	void setString(char*);

	bool isDigit(const char) const;
	bool isLetter(const char) const;
	void skipDigits();
	void skipLetters();

	char* copyLetters();
	char* createStrFrom(const Element&) const;
	char* concat(const char*, const char*) const;
};

