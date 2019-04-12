#include<string>
#include <fstream>
#include <iostream>
#include "admin.h"
using namespace std;

void admin::displayAvailableEquipment() const
{

}

void admin::displayLoanRecord(users a) const
{

	ifstream myfile;
	myfile.open("user.txt");
	string a;

	if (myfile.is_open())
	{
		while (getline(myfile, a))
		{
			cout << a << endl;

		}
		cout << endl;
		myfile.close();
	}

}

void admin::makeLoan(users a) const
{
	ifstream file;
	file.open("camp_equipment.txt");
	string b;
	if (file.is_open())
	{
		while (getline(file, b))
		{
			cout << b << endl;
		}
		file.close();
	}
}

void admin::returnEquipment(users a) const
{
}


