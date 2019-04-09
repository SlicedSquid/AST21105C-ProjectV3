#include <iostream>
#include <string>
#include <fstream>
#include "FileHandler.h"
using namespace std;

void fileHandler::displayEquipmentList() const
{
	bool status = false, condition = false;
	int counter = 0;
	string reg1;
	while (eof(input) != true)
	{
		//get equipment info stored in reg1, ignore empty line
		do
		{
			getline(input, reg1);
		} while (reg.length() == 0);
		//check the condition and status of equipment
		for (int i = 0; i < reg1.length(); i++)
		{
			if (reg1[i] == '|';)
			{
				counter++;
			}
			if (counter == 5)
			{
				if (reg1[i + 1] == 'g')
				{
					condition = true;
				}
			}
			if (counter == 6)
			{
				if (reg1[i + 1] == 'i')
				{
					status = true;
				}
			}
			if (status && condition)
			{
				cout << reg1 << endl;
				break;
			}
		}
	}
}
