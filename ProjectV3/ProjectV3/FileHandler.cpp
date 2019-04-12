#include "FileHandler.h"

using namespace std;



equipments fileHandler::creatEquipment(string reg)
{
	//获取reg中的信息，存入一个equipment类的数据结构并返回
	//输入的值是这样的：T005|4 Persons Dome|Jackal|tent|25092012|good|in|2|dome|1|true|yellow
	//然后信息就会被提取并存储
	//TODO:简化 使之可以重复使用
	int pos1, pos2, date;
	string code, name, brand, type, condition, status, _date;
	pos1 = reg.find("|", 0);
	code = code.assign(reg, 0, pos1);
	pos2 = reg.find("|", pos1+1);
	name = name.assign(reg, pos1 + 1, pos2 - pos1 - 1);
	pos1 = reg.find("|", pos2+1);
	brand = brand.assign(reg, pos2 + 1, pos1 - pos2 - 1);
	pos2 = reg.find("|", pos1+1);
	type = type.assign(reg, pos1 + 1, pos2 - pos1 - 1);
	pos1 = reg.find("|", pos2 + 1);
	date = stoi(_date.assign(reg, pos2 + 1, pos1 - pos2 - 1));
	pos2 = reg.find("|", pos1 + 1);
	condition = condition.assign(reg, pos1 + 1, pos2 - pos1 - 1);
	pos1 = reg.find("|", pos2 + 1);
	status = status.assign(reg, pos2 + 1, pos1 - pos2 - 1);
	pos2 = reg.find("|", pos1 + 1);
	return equipments(code, name, brand, type, date, condition, status);
}

*User fileHandler::creatUser(string reg)
{
	User* user = new user();
	string name, section, address;
	int birth, pos1, pos2;
	//获取reg中的信息，存入一个User类的数据结构并返回
	return user;
}



void fileHandler::displayEquipmentList()
{
	bool status = false, condition = false;
	int counter = 0;
	string reg;
	while (eof(input) != true)
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

bool fileHandler::login(User* user) const
{
	int c1, c2;
	string reg;
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
		if (reg.assign(reg, c1 + 1, c2 - 1) == user->getId())
		{
			c1 = reg.find("|", c2 + 1);
			c2 = reg.find("|", c1 + 1);
			if (reg.assign(reg, c1 + 1, c2 - 1) == user->getPassword())
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
