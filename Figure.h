#ifndef FIGURE_H
#define FIGURE_H
#include "FigureColor.h"
#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

class Figure
{
public:
	Figure(char const* = "Free", FigureColor = true);
	Figure(const Figure&);
	Figure& operator=(const Figure&);
	~Figure();

	void setColor(bool);
	void setName(char const*);

	char* getName() const;
	FigureColor getColor() const;

    void print()const;
	//virtual void move() = 0;
	//Can't use Figure class in Board class because of virtual function ?
private:
	char* name;
	FigureColor color;
	void copy(const Figure& other)
	{
		this->name = new char[strlen(other.name) + 1];
		assert(this->name != NULL);
		strcpy(this->name, other.name);
		this->color = other.color;
	}
	void erase()
	{
		delete[] this->name;
	}
};

#endif // !FIGURE_H
