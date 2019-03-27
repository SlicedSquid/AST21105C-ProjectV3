#include "Tent.h"

Tent::Tent()
{
}


Tent::~Tent()
{
}

void Tent::displayB()
{
	cout << code << "|" << name << "|" << brand << "|" << name << "|" 
		 << type << "|" << date << "|" << condition << "|" << status << "|";
}

void Tent::displayA()
{
	cout << size << "|" << tentType << "|" << numberOfDoors << "|"
		 << doubleLayer << "|" << colour << endl;
}
