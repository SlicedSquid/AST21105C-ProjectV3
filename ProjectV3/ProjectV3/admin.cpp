#include "admin.h"
using namespace std;

void admin::displayLoanRecord(string userName)
{
	string reg;
	int pos1, pos2, counter;
	input.open("loan.txt");
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

void admin::makeLoan(User* user)
{
	loanControl lH;
	string eID;
	cout << "Please input the equipment ID(input -1 to last menu):" << endl;
	cin >> eID;
	if (eID != -1)
	{
		if (lH.check(user, eID);)
		{
			//可租借的情况下，更新用户以及物品的状态，写loan record
			//如此看来这一个功能相当之难
			user->borrowItem();//更新用户状态 是不需要txt文件的 但是剩下的两项需要
		}
	}
}
