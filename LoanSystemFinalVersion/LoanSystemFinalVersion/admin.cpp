/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

#include "admin.h"
using namespace std;

// DisplayLoanRecord
void admin::displayLoanRecord(string userName)
{
	ifstream input;
	string reg,r;
	int pos1, pos2, counter;
	counter = 0;
	input.open("loan_record.txt");
    // Program refresh textbook and start to read information.
	input.clear();
    
    // Detecting whether the program read the last line
	while (!input.eof())
	{
        // Every time programmable read only one line
		getline(input, reg);
        // When the "|" is encountered, the string in front of the vertical line is canned.
		if (reg.length()!=0)
		{
			pos1 = reg.find("|", 0);
			pos2 = reg.find("|", pos1 + 1);
			pos1 = reg.find("|", pos2 + 1);
			pos2 = reg.find("|", pos1 + 1);
			if (r.assign(reg, pos1 + 1, pos2 - pos1 - 1) == userName)
			{
				cout << reg << endl;
                // Count the number of things this user loaned
				counter++;
			}
		}
	}
	if (counter == 0)
	{
		cout << "No loan is made yet." << endl;
	}
}

void admin::displayLoanRecord()
{
	ifstream input;
	string reg;
	int counter = 0;
	input.open("loan_record.txt");
	input.clear();
	while (!input.eof())
	{
		getline(input, reg);
		if (reg.length!=0)
		{
			cout << reg << endl;
            // Count the number of things all users loaned
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "No loan is made yet." << endl;
	}
	input.close();
}

void admin::updateEquipmentCondition(string eID, string status)
{
	ifstream in;
	ofstream out;
	ofstream output;
	in.clear();
	out.clear();
	output.clear();
	string reg, _reg,r;
	// Change the original file, save it to another txt file first
	in.open("camp_equipment.txt");
	out.open("tmp.txt");
	output.open("updated_equipment.txt");
	in.clear();
	out.clear();
	output.clear();
	while (!in.eof())
	{
		getline(in, reg);
		if (reg.length() == 0)
		{
			// Ignore empty line
		}
		else
		{
			// Find the line need change
			if (r.assign(reg, 0, 4) == eID)
			{
				// Change status
				if (status == "out")
				{
                    // Equipment situation set as "on" when equipment returned.
					int pos = reg.find("|in|", 0);
					_reg.assign(reg, pos + 3, reg.length() - pos - 3);
					reg.assign(reg, 0, pos+1);
					reg.append("out");
					reg.append(_reg);
				}
				else
				{
                    // Equipment situation set as "off" when equipment loaned.
					int pos = reg.find("|out|", 0);
					_reg.assign(reg, pos + 4, reg.length() - pos -1);
					reg.assign(reg, 0, pos+1);
					reg.append("in");
					reg.append(_reg);
				}
			}
			out << reg << endl;
			output << reg << endl;
		}
	}
	in.close();
	out.close();
	output.close();
	// Write changed file back to original file
	in.open("tmp.txt",ios::beg);
	out.open("camp_equipment.txt",ios::beg);
	in.clear();
	out.clear();
	while (!in.eof())
	{
		getline(in, reg);
		out << reg << endl;
	}
	in.close();
	out.close();
}

void admin::updateLoanStatus(string eID, string status)
{
	ifstream input;
	ofstream output;
	string reg,r;
	int pos;
	input.clear();
	output.clear();
	input.open("loan_record.txt");
	output.open("tmp.txt");
	while (!input.eof())
	{
		getline(input,reg);
		if (reg.length()!=0)
		{
			pos = reg.find("|", 0);
            // Query the equipment condition by the equipment id
			if (r.assign(reg, pos + 1, 4) == eID)
			{
				if (status == "returned")
				{
                    // Change status
					pos = reg.find("|out of loan", 0);
					if (pos != -1)
					{
						reg.assign(reg, 0, pos + 1);
						reg.append("returned");
					}
				}
				else
				{
                    // Oppsite
					pos = reg.find("|returned", 0);
					if (pos != -1)
					{
						reg.assign(reg, 0, pos + 1);
						reg.append("out of loan");
					}
				}
			}
			output << reg << endl;
		}
	}
	input.close();
	output.close();
	input.open("tmp.txt");
	output.open("loan_record.txt");
	input.clear();
	output.clear();
	while (!input.eof())
	{
		getline(input,reg);
		output << reg << endl;
	}
	input.close();
	output.close();
}


void admin::makeLoan(User* user)
{
	fileHandler fH;
	string reg, eID, r;
	equipments* e = nullptr;
	ofstream output;
	
	if (!user->getStatus())
	{
		while (user->getLoanNumber() != 0)
		{
			cout << "Please input the equipment ID(input -1 to get back):";
			cin >> eID;
			if (eID == "-1")
			{
				break;
			}
			e = fH.creatEquipment(eID);
            // Bool type: if equipment rent out then return true, else return false
			if (e->returnStatus())
			{
				user->borrowItem();
				updateEquipmentCondition(eID, "out");
				output.clear();
				output.open("loan_record.txt", ios::app);
				output.clear();
                // The loan time is April 13, 2019.
				output << "2019/4/13|" << eID << "|" << e->returnName() << "|" << user->getName() << "|" << "2019/5/02" << "|" << "out of loan" << endl;
				cout << "Loan has been made!" << endl;
			}
			else
			{
				cout << "That equipment is not available!" << endl;
			}
		}
	}
	else
	{
		cout << "Sorry, this option is not available!" << endl;
	}
	output.close();
	delete e;
}

void admin::returnEquipments(User * user)
{
	string eID, reg, r;
	int pos1, pos2, counter;
	ifstream input;
	input.open("loan_record.txt");
	while (true)
	{
		input.clear();
		input.seekg(SEEK_SET);
        
		if (!user->getStatus())
		{
			cout << "You have nothing to return now!" << endl;
			break;
		}
		cout << "Please input the Equipment ID(input -1 to get back):";
		cin >> eID;
		if (eID != "-1")
		{
			counter = 0;
			while (!input.eof())
			{
				getline(input, reg);
				if (reg.length()!=0)
				{
                    
					pos1 = reg.find("|", 0);
					pos2 = reg.find("|", pos1 + 1);
                    // Query the equipment condition by the equipment id
					if (eID == r.assign(reg, pos1 + 1, pos2 - pos1 - 1))
					{
						pos1 = reg.find("|", pos2 + 1);
						pos2 = reg.find("|", pos1 + 1);
                        // Find the renter of the same name in the record and change the status
						if (user->getName() == r.assign(reg, pos1 + 1, pos2 - pos1 - 1))
						{
							user->returnItem();
							updateEquipmentCondition(eID, "in");
							updateLoanStatus(eID, "returned");
							cout << "Successfully returned!" << endl;
							counter++;
						}
					}
				}
			}
			if (counter == 0)
			{
				cout << "Please enter available equipment!" << endl;
			}
			
		}
		else
		{
			break;
		}
	}
	input.close();
}