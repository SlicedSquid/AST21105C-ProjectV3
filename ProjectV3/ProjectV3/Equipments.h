#include <iostream>
#ifndef EQUIPMENT_H
class equipments
{
private:
	int code;			// Item code
	string name;		// Item name
	string brand;		// Brand
	string type;		// Equipment Type
	int date;			// Date of Purchase
	string condition;	// Condition
	string status;		// Status
public:
	equipments();
	equipments(equipmentName);
	virtual void displayB();	// Display basic information
	virtual void displayA();	// Display attribute
	bool returnStatus();
	void changeStatus(string s);
}

class stove : public equipments
{
private:
	string type;	// Stove Type (ultralight, lightweight, and table)
	int fuelType;	// Fuel Type (stove gas, screw headed gas, and wax)
public:
	virtual void displayB();	// Display basic information
	virtual void displayA();	// Display attribute
};

class lantern : public equipments
{
private:
	string size;		// Lantern Size (hiking or camping)
	string type;		// Lantern Type (head lamp, table lamp, led lamp, and beam lamp)
	string fuelType;	// Fuel Type (AAbatteries, AAA batteries, C batteries, D batteries, stove gas and screw headed gas)
public:
	virtual void displayB();	// Display basic information
	virtual void displayA();	// Display attribute
};

class tent : public equipments
{
private:
	int size[6] = { 2, 4, 6, 8, 10, 16 };		// # of ppl use (2, 4, 6, 8, 10, and 16)
	string tentType;								// Tent Type (lightweight, family, wall, tunnel, or dome)
	int numberOfDoors[3] = { 1, 2, 4 };			// # of doors (1, 2, and 4)
	bool doubleLayer;							// Double-layer? (true / false)
	string colour;
public:
	virtual void displayB();	// Display basic information
	virtual void displayA();	// Display attribute
};
#endif // !EQUIPMENT_H
