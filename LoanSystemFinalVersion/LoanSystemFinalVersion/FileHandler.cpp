/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

#include "FileHandler.h"
using namespace std;

equipments* fileHandler::creatEquipment(string equipmentID)
{
	ifstream input; // initialize the function of ifstream
	int pos1, pos2, date;
	string code, name, brand, type, condition, status, _date, reg,r;
	input.clear();
	input.open("camp_equipment.txt"); // open the target file
	while (!input.eof())
	{
		// Get the content of the file in each line
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
		// Find the location of "|" and get the information between two"|"
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
	ifstream input; // initialize the function of ifstream
	string code, name, section, address, rank, reg, r;
	int birth, pos1, pos2;
	User* user;
	input.open("user.txt",ios::beg);// Open the target file
	while (!input.eof())
	{
		// Get the content of the file in each line
		getline(input, reg);
		if (r.assign(reg,0,6) == id)
		{
			break;
		}
	}
	// Find the location of "|" and get the information between two"|"
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
	// Determine the limits of authority which are VEN and ROV
	if (code == "VEN"||code == "ROV")
	{
		if (code == "VEN")
		{
			user = new VentureScout(id,name,section,address,birth);
		}
		else
		{
			user = new RoverScout(id, name, section, address, birth);
		}
	}
	else
	{
		rank = r.assign(reg, pos2 + 1, reg.length() -pos2 -1);
		// Determine the limits of authority which is SCT
		if (code=="SCT")
		{
			user = new Scout(id, name, section, address, birth, rank);
		}
		else
		{
			user = new Scouter(id, name, section, address, birth, rank);
		}
	}
	input.close();
	input.open("loan_record.txt"); // open the target file
	input.clear();
	// Build up a loop
	while (!input.eof())
	{
		getline(input,reg);
		// Find the location of "|" and get the information between two"|"
		if (reg.length()!=0)
		{
			pos1 = reg.find("|", 0);
			pos2 = reg.find("|", pos1 + 1);
			pos1 = reg.find("|", pos2 + 1);
			pos2 = reg.find("|", pos1 + 1);
			r.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			if (r == name)
			{
				pos1 = reg.find("|", pos2 + 1);
				r.assign(reg, pos1 + 1, reg.length() - 1 - pos1);
				if (r == "out of loan")
				{
					user->borrowItem();
				}
			}
		}
	}
	return user;
}



void fileHandler::displayEquipmentList()
{
	ifstream input; // initialize the function of ifstream
	int pos1,pos2;
	string reg,r;
	input.open("camp_equipment.txt",ios::beg); // open the target file
	// Get equipment info stored in reg1, ignore empty line
	while (!input.eof())
	{
		// Find the location of "|" and get the information between two"|"
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
			// Judge the condition of equipment,if it is good and in, bulid a instance and print the basic infomation of this equipment
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

void fileHandler::displayAllEquipmentList()
{
	ifstream input; // initialize the function of ifstream
	string reg, r;
	string name[3] = { "tent","stove","lantern" };
	string print[3] = { "Tents:","Stoves:","Lanterns:" };
	int pos1, pos2;
	input.open("camp_equipment.txt");// Open the target file
	input.clear();
	// Print out equipments by categories
	// Check tents first, then stoves, then lanterns
	for (int i = 0; i < 3; i++)
	{
		input.clear();
		input.seekg(SEEK_SET);
		cout << print[i] << endl;
		// Check the correction of id and password
		while (!input.eof())
		{
			do
			{
				getline(input, reg);
				if (input.eof())
				{
					break;
				}
			} while (reg.length()==0);
			pos1 = reg.find("|", 0);
			pos2 = reg.find("|", pos1 + 1);
			pos1 = reg.find("|", pos2 + 1);
			pos2 = reg.find("|", pos1 + 1);
			r.assign(reg, pos1 + 1, pos2 - pos1 - 1);
			if (r == name[i] && pos2!=0)
			{
				cout << reg << endl;
			}
		}
	}
	input.close();
}

bool fileHandler::login(string id, string password)
{
	ifstream input; // initialize the function of ifstream
	input.clear();
	int c1, c2;
	string reg, r;
	input.open("user.txt",ios::beg);// open the target file
	while (!input.eof())
	{
		do
		{
			// Find the location of "|" and get the information between two"|"
			getline(input,reg);
			if (input.eof())
				break;
		} while (reg.length()==0);

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
	ifstream input; // initialize the function of ifstream
	string reg,r;
	int pos1, pos2, counter;
	counter = 0;
	input.clear();
	input.open("loan_record.txt",ios::beg); // open the target file
	while (!input.eof())
	{
		do
		{
			// Find the location of "|" and get the information between two"|"
			getline(input, reg);
		} while (reg.length() == 0);
		pos1 = reg.find("|", 0);
		pos2 = reg.find("|", pos1 + 1);
		pos1 = reg.find("|", pos2 + 1);
		pos2 = reg.find("|", pos1 + 1);
		// Switch the condition of loan to the returned
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

void fileHandler::insertFiles()
{
	ifstream input;		// initialize the function of ifstream
	ofstream output;	// initialize the function of ofstream
	int type;
	string fileName, reg;
	cout << "Please input the tabulated file name:";
	cin >> fileName;
	input.open(fileName); // open the target file
	input.clear();
	cout << "Which type of file is it?" << endl;
	cout << "1) camp equipments list" << endl;
	cout << "2) user list" << endl;
	cout << "enter your choice:";
	cin >> type;
	if (type == 1)
	{
		output.open("camp_equipment.txt");
		output.clear();
	}
	else
	{
		output.open("user.txt");
		output.clear();
	}
	while (!input.eof())
	{
		getline(input, reg);
		output << reg << endl;
	}
	input.close();
	output.close();
}
