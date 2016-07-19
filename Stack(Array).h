#pragma once
#include "Element.h"

class StackA
{
private:
	int size;
	int cap;
	Element* data;

public:
	StackA();
	~StackA();
	StackA(const StackA&);
	const StackA& operator=(const StackA&);

public:
	Element pop();
	void push(const Element&);
	Element& top();
	int getSize() const;

private:
	void copy(const StackA&);
	void resize(int);
};

