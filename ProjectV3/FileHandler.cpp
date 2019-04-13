#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Equipments.h"
#include "Users.h"
using namespace std;



equipments* fileHandler::creatEquipment(string equipmentID)
{
	ifstream input;
	int pos1, pos2, date;
	string code, name, brand, type, condition, status, _date, reg,r;
	input.clear();
	input.open("camp_equipment.txt");
	while (!input.eof())
	{
		while (getline(input,reg))
		{
			if (reg.length() == 0)
			{
			}
			else
			{
				break;
			}
		}
		if (r.assign(reg, 0, 4)==equipmentID)
		{
			pos1 = 4;
			code.assign(reg, 0, 4);
			pos2 = reg.find("|", pos1 + 1);
			name.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			pos1 = reg.find("|", pos2 + 1);
			brand.assign(reg, pos2 + 1, pos1 - pos2 - 1);
			pos2 = reg.find("|", pos1 + 1);
			type.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			pos1 = reg.find("|", pos2 + 1);
			date = stoi(_date.assign(reg, pos2 + 1, pos1 - pos2 - 1));
			pos2 = reg.find("|", pos1 + 1);
			condition.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			pos1 = reg.find("|", pos2 + 1);
			status.assign(reg, pos2 + 1, pos1 - pos2 - 1);
			pos2 = reg.find("|", pos1 + 1);
			equipments *a = new equipments(code, name, brand, type, date, condition, status);
			input.close();
			return a;
		}
	}
	return nullptr;
}

User *fileHandler::creatUser(string id)
{
	ifstream input;
	string code, name, section, address, rank, reg, r;
	int birth, pos1, pos2;
	input.open("user.txt",ios::beg);
	while (!input.eof())
	{
		getline(input, reg);
		if (r.assign(reg,0,6) == id)
		{
			break;
		}
	}
	code = r.assign(reg, 0, 3);
	id = r.assign(reg, 0, 6);
	pos1 = reg.find("|", 7);
	name = r.assign(reg, 7, pos1-7);
	pos2 = reg.find("|", pos1 + 1);
	section = r.assign(reg, pos1 + 1, pos2 - pos1 -1);
	pos1 = reg.find("|", pos2 + 1);
	birth = stoi(r.assign(reg, pos2 + 1, pos1 - pos2 -1));
	pos2 = reg.find("|", pos1 + 1);
	address = r.assign(reg, pos1 + 1, pos2 -pos1- 1);
	if (code == "VEN"||code == "ROV")
	{
		if (code == "VEN")
		{
			User* user = new VentureScout(id,name,section,address,birth);
			return user;
		}
		else
		{
			User* user = new RoverScout(id, name, section, address, birth);
			return user;
		}
	}
	else
	{
		rank = r.assign(reg, pos2 + 1, reg.length() -pos2 -1);
		if (code=="SCT")
		{
			User* user = new Scout(id, name, section, address, birth, rank);
			return user;
		}
		else
		{
			User* user = new Scouter(id, name, section, address, birth, rank);
			return user;
		}
	}
}



void fileHandler::displayEquipmentList()
{
	ifstream input;
	int pos1,pos2;
	string reg,r;
	input.open("camp_equipment.txt",ios::beg);
	//get equipment info stored in reg1, ignore empty line
	while (!input.eof())
	{
		getline(input, reg);
		if (reg.length() == 0)
		{

		}
		else
		{
			pos1 = reg.find("|", 5);
			pos2 = reg.find("|", pos1 + 1);
			pos1 = reg.find("|", pos2 + 1);
			pos2 = reg.find("|", pos1 + 1);
			pos1 = reg.find("|", pos2 + 1);
			r.assign(reg, pos2 + 1, pos1 - pos2 - 1);
			if (r == "good")
			{
				pos2 = reg.find("|", pos1 + 1);
				r.assign(reg, pos1 + 1, pos2 - pos1 - 1);
				if (r == "in")
				{
					r = reg.assign(reg, 0, 4);
					equipments *e = creatEquipment(r);
					e->displayB();
				}
			}
		}
	}
	input.close();
}

bool fileHandler::login(string id, string password) 
{
	ifstream input;
	int c1, c2;
	string reg, r;
	input.open("user.txt",ios::beg);
	while (!input.eof())
	{
		getline(input, reg);
		if (reg.length()==0)
		{
			getline(input, reg);
		}

		c1 = reg.find("|", 0);
		c2 = reg.find("|", c1 + 1);
		if (r.assign(reg,0,6) == id)
		{
			c1 = reg.find("|", c2 + 1);
			c2 = reg.find("|", c1 + 1);
			if (r.assign(reg,c1+1,c2-c1-1) == password)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

void fileHandler::changeLoanStatus(User* user)
{
	ifstream input;
	string reg,r;
	int pos1, pos2, counter;
	counter = 0;
	input.open("loan_record.txt",ios::beg);
	while (!input.eof())
	{
		do
		{
			getline(input, reg);
		} while (reg.length() == 0);
		pos1 = reg.find("|", 0);
		pos2 = reg.find("|", pos1 + 1);
		pos1 = reg.find("|", pos2 + 1);
		pos2 = reg.find("|", pos1 + 1);
		if (r.assign(pos1 + 1, pos2 - pos1 -1) == user->getName())
		{
			pos1 = reg.find("|", pos2 + 1);
			if (r.assign(reg,pos1+1, reg.length()-pos1-2) == "returned")
			{

			}
			else
			{
				counter++;
			}
		}
	}
	if (counter == 0)
	{
		user->setLoanStatus(false);
	}
	else
	{
		user->setLoanStatus(true);
		user->setLoanNumber(counter);
	}
}
