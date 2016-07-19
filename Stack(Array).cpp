#include "Stack(Array).h"

StackA::StackA()
{
	size = 0;
	cap = 4;
	data = new Element[cap];
}

StackA::~StackA()
{
	delete[] data;
}

StackA::StackA(const StackA& other)
{
	copy(other);
}

const StackA& StackA::operator=(const StackA& other)
{
	if (this != &other)
	{
		delete[] data;
		copy(other);
	}
	return *this;
}

void StackA::copy(const StackA& other)
{
	cap = other.cap;
	size = other.size;
	data = new Element[cap];
	for (int i = 0; i < size; ++i)
		data[i] = other.data[i];
}

void StackA::resize(int newCap)
{
	cap = newCap;
	Element* newData = new Element[cap];
	for (int i = 0; i < size; ++i)
		newData[i] = data[i];
	delete[] data;
	data = newData;
}


Element StackA::pop()
{
	return data[--size];
}

void StackA::push(const Element& el)
{
	if (size == cap)
		resize(cap * 2);
	data[size++] = el;
}

Element& StackA::top()
{
	return data[size - 1];
}

int StackA::getSize() const
{
	return size;
}