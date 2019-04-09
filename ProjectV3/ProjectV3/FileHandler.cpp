#include "FileHandler.h"

using namespace std;

equipments fileHandler::creatEquipment(string reg)
{
	//将reg中的信息提取出来 存入一个equipments类型的data structrue中并返回
	return equipments();
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
				
			}
		}
	}
}

bool fileHandler::login(string id, string password) const
{
	string reg;
	do
	{
		getline(input,reg);
	} while (reg.length()==0);
}
