#include "FileHandler.h"

using namespace std;



equipments fileHandler::creatEquipment(string equipmentID)
{
	//获取reg中的信息，存入一个equipment类的数据结构并返回
	//输入的值是这样的：T005|4 Persons Dome|Jackal|tent|25092012|good|in|2|dome|1|true|yellow
	//然后信息就会被提取并存储
	//TODO:简化 使之可以重复使用
	int pos1, pos2, date;
	string code, name, brand, type, condition, status, _date, reg;
	input.open("camp_equipment.txt");
	while (!input.eof())
	{
		do
		{
			getline(input, reg);
		} while (reg.length() == 0);
		if (reg.assign(0,3)==equipmentID)
		{
			pos1 = 4;
			code = code.assign(reg, 0, 3);
			pos2 = reg.find("|", pos1 + 1);
			name = name.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			pos1 = reg.find("|", pos2 + 1);
			brand = brand.assign(reg, pos2 + 1, pos1 - pos2 - 1);
			pos2 = reg.find("|", pos1 + 1);
			type = type.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			pos1 = reg.find("|", pos2 + 1);
			date = stoi(_date.assign(reg, pos2 + 1, pos1 - pos2 - 1));
			pos2 = reg.find("|", pos1 + 1);
			condition = condition.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			pos1 = reg.find("|", pos2 + 1);
			status = status.assign(reg, pos2 + 1, pos1 - pos2 - 1);
			pos2 = reg.find("|", pos1 + 1);
			equipments *a = new equipments(code, name, brand, type, date, condition, status);
			return a;
		}
	}
}

*User fileHandler::creatUser(string reg)
{
	string id, code, name, section, address, rank;
	int birth, pos1, pos2;
	code = reg.assign(reg, 0, 2);
	id = reg.assign(reg, 0, 5);
	pos1 = reg.find("|", 7);
	name = reg.assign(reg, 7, pos1 - 1);
	pos2 = reg.find("|", pos1 + 1);
	section = reg.assign(reg, pos1 + 1, pos2 - 1);
	pos1 = reg.find("|", pos2 + 1);
	birth = stoi(reg.assign(reg, pos2 + 1, pos1 - 1));
	pos2 = reg.find("|", pos1 + 1);
	address = reg.assign(reg, pos1 + 1, pos2 - 1);
	
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
		rank = reg.assign(reg, pos2 + 1, reg.length() - 1);
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
	bool status = false, condition = false;
	int counter = 0;
	string reg;
	input.open("camp_equipments.txt");
	while (!eof(input))
	{
		//get equipment info stored in reg1, ignore empty line
		do
		{
			getline(input, reg);
		} while (reg.length() == 0);
		//check the condition and status of equipment
		for (int i = 0; i < reg.length(); i++)
		{
			if (reg[i] == '|';)
			{
				counter++;
			}
			if (counter == 5)
			{
				if (reg[i + 1] == 'g')
				{
					condition = true;
				}
			}
			if (counter == 6)
			{
				if (reg[i + 1] == 'i')
				{
					status = true;
				}
			}
			if (status && condition)
			{
				equipments aE = creatEquipment(reg);
				aE.displayB();
			}
		}
	}
}

bool fileHandler::login(string id, string password, User* user) const
{
	int c1, c2;
	string reg;
	input.open(user.txt);
	while (true)
	{
		do
		{
			getline(input, reg);
		} while (reg.length() == 0);
		if (input.eof())
		{
			return false;
		}
		c1 = reg.find("|", 0);
		c2 = reg.find("|", c1 + 1);
		if (reg.assign(reg, c1 + 1, c2 - 1) == id)
		{
			c1 = reg.find("|", c2 + 1);
			c2 = reg.find("|", c1 + 1);
			if (reg.assign(reg, c1 + 1, c2 - 1) == password)
			{
				user = creatUser(reg);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
