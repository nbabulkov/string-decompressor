#pragma once
struct Element
{
public:
	int times;
	char* text;

public:
	Element();
	~Element();
	Element(const Element&);
	const Element& operator=(const Element&);

private:
	void copy(const Element&);
};

