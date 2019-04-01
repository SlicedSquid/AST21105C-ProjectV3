#ifndef TENT_H
#define TENT_H
#include <iostream>
using namespace std;

/* BASE CLASS */
class Tent
{
private:
	int size[6] = { 2, 4, 6, 8, 10, 16 };		// # of ppl use (2, 4, 6, 8, 10, and 16)
	string tentType;								// Tent Type (lightweight, family, wall, tunnel, or dome)
	int numberOfDoors[3] = { 1, 2, 4 };			// # of doors (1, 2, and 4)
	string doubleLayer;							// Double-layer? (true / false)
	string colour;								// Colour

public:
	Tent();
	virtual ~Tent();

	void displayB();	// Display basic information
	void displayA();	// Display attribute

	int code;			// Item code
	string name;		// Item name
	string brand;		// Brand
	string type;		// Equipment Type
	int date;			// Date of Purchase
	string condition;	// Condition
	string status;		// Status
};

#endif