#include<iostream>
#include "Equipments.h"
using namespace std;

equipments::equipments()
{
}

equipments::equipments(equipmentName)
{
}

void equipments::displayB()
{
	cout << code << "|" << name << "|" << brand << "|" << type << "|"
		 << date << "|" << condition << "|" << status << "|";
}

bool equipments::returnStatus()
{
	return false;
}

void equipments::changeStatus(string s)
{
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
