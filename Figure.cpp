#include "Figure.h"
#include <iostream>
#include <cstring>

using namespace std;

Figure::Figure(char const *name, FigureColor color)
{
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
	this->color = color;
}

Figure::Figure(const Figure &other)
{
	copy(other);
}

Figure & Figure::operator=(const Figure &other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
	// TODO: insert return statement here
}

Figure::~Figure()
{
	erase();
}

bool Figure::operator==(char const* str) const
{
    return !strcmp(name,str);
}

void Figure::setColor(bool other)
{
	this->color = other;
}

void Figure::setName(char const* name)
{
	erase();
	this->name = new char[strlen(name) + 1];
	assert(this->name != NULL);
	strcpy(this->name, name);
}

char * Figure::getName() const
{
	return this->name;
}

FigureColor Figure::getColor() const
{
	return this->color;
}

void Figure::print() const
{
    if (!(*this=="Free"))
    {
        if (color.isWhite())
        cout << "W " << name;
        else
        cout << "B " << name;
    }
}
