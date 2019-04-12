#include<iostream>
#include "Equipments.h"
using namespace std;

equipments::equipments(string _code, string _name, string _brand, string _type, int _date, string _condition, string _status)
{
	code = _code;
	name = _name;
	brand = _brand;
	type = _type;
	date = _date;
	condition = _condition;
	status = _status;
}

equipments::~equipments()
{
}

void equipments::displayB()
{
	cout << code << "|" << name << "|" << brand << "|" << type << "|"
		 << date << "|" << condition << "|" << status << endl;
}

bool equipments::returnStatus()
{
	if (status == "in")
		return true;
	else
		return false;
}

void equipments::changeStatus(string s)
{
	status = s;
}

void stove::displayA()
{
	cout << stoveType << "|" << fuelType << endl;
}

void lantern::displayA()
{
	cout << lanternSize << "|" << lanternType << "|" << fuelType << endl;
}

void tent::displayA()
{
	cout << tentSize << "|" << tentType << "|" << numberOfDoors << "|" << doubleLayer << "|" << colour << endl;
}