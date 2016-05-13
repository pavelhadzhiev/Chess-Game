#include "FigureColor.h"
#include <iostream>

using namespace std;

FigureColor::FigureColor(bool White)
{
	this->White = White;
}

bool FigureColor::isWhite() const
{
	return this->White;
}
