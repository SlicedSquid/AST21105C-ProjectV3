#include "admin.h"
using namespace std;

void admin::displayLoanRecord(string userName)
{
	ifstream input;
	string reg;
	int pos1, pos2, counter;
	input.open("loan_record.txt");
	while (!eof(input))
	{
		do
		{
			getline(input, reg);
		} while (reg.length() == 0);
		pos1 = reg.find("|", 0);
		pos2 = reg.find("|", pos1 + 1);
		pos1 = reg.find("|", pos2 + 1);
		pos2 = reg.find("|", pos1 + 1);
		if (reg.assign(pos1 + 1, pos2 - 1) == userName)
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
	ifstream input;
	ofstream output;
	string reg, _reg;
	input.open("camp_equipments.txt");
	output.open("tmp.txt");
	while (!input.eof())
	{
		getline(input, reg);
		if (reg.assign(0, 3) == eID)
		{
			//���еĸĶ�
			if (status == "out")
			{
				int pos = reg.find("|in|", 0);
				_reg = reg.assign(pos + 3, reg.length() - 1);
				reg = reg.assign(0, pos);
				reg = reg.append("out");
				reg = reg.append(_reg);
			}
			else
			{
				int pos = reg.find("|out|", 0);
				_reg = reg.assign(pos + 3, reg.length() - 1);
				reg = reg.assign(0, pos);
				reg = reg.append("in");
				reg = reg.append(_reg);
			}
		}
		output << reg << endl;
	}
	input.close();
	output.close();
	input.open("tmp.txt");
	output.open("camp_equipments.txt");
	//�Ķ�����ļ�д��equipments.txt
	while (!input.eof())
	{
		getline(input, reg);
		output << reg << endl;
	}
	//��Ʒ״̬�������
	input.close();
	output.close();
}

void admin::updateLoanStatus(string eID, string status)
{
	ifstream input;
	ofstream output;
	string reg;
	int pos;
	input.open("loan_record.txt");
	output.open("tmp.txt");
	while (!input.eof())
	{
		getline(input,reg);
		pos = reg.find("|", 0);
		if (reg.assign(pos1+1,pos1+4) == eID)
		{
			pos = reg.find("|out of loan", 0);
			reg = reg.assign(0, pos);
			reg = reg.append("returned");
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
	string reg, eID;
	equipments* e;
	ifstream input("camp_equipments.txt");
	while (true)
	{
		if (user->getStatus())
		{
			cout << "Please input the equipment ID(input -1 to get back):";
			cin >> eID;
			while (!input.eof())
			{
				getline(input,reg);
				if (reg.assign(0,3) == eID)
				{
					e = fH.creatEquipment(reg);
				}
			}
			if (eID != "-1")
			{
				if (lC.check(user, e);)
				{
					//����������£������û��Լ���Ʒ��״̬��дloan record
					//��˿�����һ�������൱֮��
					//�����û�״̬
					user->borrowItem();
					//������Ʒ״̬
					updateEquipmentCondition(eID, "out");
					//��������¼
					output.open("loan_record.txt", ios::app);
					output << "2019/4/13|" << eID << "|" << e->returnName() << "|" << user->getName() << "|" << "2019/5/02" << "|" << "out of loan" << endl;
				}
			}
			else
			{
				break;
			}
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
	//����Ʒ��Ҫʲô��
	//��Ʒ�����״̬ �û���״̬ ���н���¼�ĸ���
	//����Ҫ֪����ʲô���� �ܲ��ܻ�
	string eID, reg;
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
				if (eID == reg.assign(pos1+1,pos2-1))
				{
					pos1 = reg.find("|", pos2 + 1);
					pos2 = reg.find("|", pos1 + 1);
					if (user->getName() == reg.assign(pos1+1,pos2-1))
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
