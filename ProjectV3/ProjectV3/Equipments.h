#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <iostream>
using namespace std;

class equipments
{
private:
	string code;		// Item code
	string name;		// Item name
	string brand;		// Brand
	string type;		// Equipment Type
	int date;			// Date of Purchase
	string condition;	// Condition
	string status;		// Status
public:
	equipments(string _code, string _name, string _brand, string _type, 
			   int _date, string _condition, string _status);
	~equipments();
	void displayB();				// Display basic information
	virtual void displayA() = 0;	// Display attribute
	bool returnStatus();
	void changeStatus(string s);
}

class stove : public equipments
{
private:
	string stoveType;	// Stove Type (ultralight, lightweight, and table)
	string fuelType;	// Fuel Type (stove gas, screw headed gas, and wax)
public:
	virtual void displayA();	// Display attribute
};

class lantern : public equipments
{
private:
	string lanternSize;	// Lantern Size (hiking or camping)
	string lanternType;	// Lantern Type (head lamp, table lamp, led lamp, and beam lamp)
	string fuelType;	// Fuel Type (AAbatteries, AAA batteries, C batteries, D batteries, stove gas and screw headed gas)
public:
	virtual void displayA();	// Display attribute
};

class tent : public equipments
{
private:
	int tentSize;		// # of ppl use (2, 4, 6, 8, 10, and 16)
	string tentType;	// Tent Type (lightweight, family, wall, tunnel, or dome)
	int numberOfDoors;	// # of doors (1, 2, and 4)
	bool doubleLayer;	// Double-layer? (true / false)
	string colour;		// Colour
public:
	virtual void displayA();	// Display attribute
};

#endif // !EQUIPMENT_H