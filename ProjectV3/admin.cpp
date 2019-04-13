#include "admin.h"
using namespace std;

void admin::displayLoanRecord(string userName)
{
	ifstream input;
	string reg,r;
	int pos1, pos2, counter;
	counter = 0;
	input.clear();
	input.open("loan_record.txt");
	while (!input.eof())
	{
		getline(input, reg);
		if (reg.length()==0)
		{
			break;
		}
		pos1 = reg.find("|", 0);
		pos2 = reg.find("|", pos1 + 1);
		pos1 = reg.find("|", pos2 + 1);
		pos2 = reg.find("|", pos1 + 1);
		if (r.assign(reg, pos1 + 1, pos2- pos1 - 1) == userName)
		{
			cout << reg << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "No loan is made yet." << endl;
	}
}

void admin::updateEquipmentCondition(string eID, string status)
{
	ifstream in;
	ofstream out;
	in.clear();
	out.clear();
	string reg, _reg,r;
	in.open("camp_equipment.txt");
	out.open("tmp.txt");
	//为何读出来是个空的字符串？
	while (!in.eof())
	{
		getline(in, reg);
		if (reg.length() == 0)
		{

		}
		else
		{
			if (r.assign(reg, 0, 3) == eID)
			{
				//该行的改动
				if (status == "out")
				{
					int pos = reg.find("|in|", 0);
					_reg = reg.assign(reg, pos + 3, reg.length() - pos - 4);
					reg = reg.assign(reg, 0, pos);
					reg = reg.append("out");
					reg = reg.append(_reg);
				}
				else
				{
					int pos = reg.find("|out|", 0);
					_reg = reg.assign(reg, pos + 3, reg.length() - pos - 4);
					reg = reg.assign(reg, 0, pos);
					reg = reg.append("in");
					reg = reg.append(_reg);
				}
			}
			out << reg << endl;
		}
	}
	in.close();
	out.close();
	in.open("tmp.txt",ios::beg);
	out.open("camp_equipment.txt");
	//改动后的文件写回equipments.txt
	while (!in.eof())
	{
		getline(in, reg);
		out << reg << endl;
	}
	//物品状态更新完成
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
	input.open("loan_record.txt", ios::out);
	output.open("tmp.txt");
	while (!input.eof())
	{
		getline(input,reg);
		pos = reg.find("|", 0);
		if (r.assign(reg,pos + 1 ,4) == eID)
		{
			if (status == "returned")
			{
				pos = reg.find("|out of loan", 0);
				reg.assign(reg, 0, pos+1);
				reg.append("returned");
			}
			else
			{
				pos = reg.find("|returned", 0);
				reg.assign(reg, 0, pos+1);
				reg.append("out of loan");
			}
		}
		output << reg << endl;
	}
	input.close();
	output.close();
	input.open("tmp.txt");
	output.open("loan_record.txt");
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
	ifstream input;
	ofstream output;
	while (true)
	{
		if (user->getStatus())
		{
			for (int i = 0; i < user->getLoanNumber(); )
			{
				cout << "Please input the equipment ID(input -1 to get back):";
				cin >> eID;
				e = fH.creatEquipment(eID);
				if (eID == "-1")
				{
					break;
				}
				if (user->getStatus() && e->returnStatus())
				{
					input.clear();
					input.open("camp_equipment.txt");
					while (!input.eof())
					{
						getline(input, reg);
						if (reg.length() == 0)
						{

						}
						else
						{
							if (r.assign(reg, 0, 4) == eID)
							{
								e = fH.creatEquipment(r.assign(reg, 0, 4));
								break;
							}
						}
					}
					user->borrowItem();
					input.close();
					updateEquipmentCondition(eID, "out");
					output.clear();
					output.open("loan_record.txt", ios::app);
					output << "2019/4/13|" << eID << "|" << e->returnName() << "|" << user->getName() << "|" << "2019/5/02" << "|" << "out of loan" << endl;
					i++;
					cout << "Loan has been made!" << endl;
				}
				else
				{
					cout << "That equipment is not available!" << endl;
				}
			}
			break;
		}
		else
		{
			cout << "Sorry, this option is not available!" << endl;
			break;
		}
	}
}

void admin::returnEquipments(User * user)
{
	string eID, reg, r;
	int pos1, pos2;
	ifstream input;
	while (true)
	{
		if (user->getStatus())
		{

		}
		else
		{
			cout << "You have nothing to return!" << endl;
			break;
		}
		cout << "Please input the Equipment ID(input -1 to get back):";
		cin >> eID;
		if (eID != "-1")
		{
			input.open("loan_record.txt");
			while (!input.eof())
			{
				getline(input, reg);
				pos1 = reg.find("|", 0);
				pos2 = reg.find("|", pos1 + 1);
				if (eID == r.assign(reg,pos1+1,pos2-pos1-1))
				{
					pos1 = reg.find("|", pos2 + 1);
					pos2 = reg.find("|", pos1 + 1);
					if (user->getName() == r.assign(reg,pos1+1,pos2-pos1-1))
					{
						user->returnItem();
						updateEquipmentCondition(eID,"in");
						updateLoanStatus(eID,"returned");
					}
					else
					{
						cout << "Please enter correct equipment ID!" << endl;
						break;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
}
