#include <iostream>
#include "Element.h"

Element::Element()
{
	times = 1;
	text = nullptr;
}

Element::~Element()
{
	delete[] text; 
}

Element::Element(const Element& other)
{
	copy(other);
}

const Element& Element::operator=(const Element& other)
{
	if (this != &other)
	{
		delete[] text;
		copy(other);
	}
	return *this;
}

void Element::copy(const Element& other)
{
	times = other.times;
	if (other.text != nullptr)
	{
		int size = strlen(other.text) + 1;
		text = new char[size];
		strcpy(text, other.text);
	}
	else
		text = nullptr;
}

