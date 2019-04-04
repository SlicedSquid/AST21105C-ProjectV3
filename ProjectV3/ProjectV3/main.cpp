#include <iostream>
using namespace std;

int getMainMenu() 
{
	int choice;
	cout << "-----------------------------------" << endl;
	cout << "1.Display available camp equipments" << endl;
	cout << "2.Display loan record" << endl;
	cout << "3.Make equipment loan" << endl;
	cout << "4.Return equipment" << endl;
	cout << "5.Exit" << endl;
	cout << "-----------------------------------"
	cout << "Enter your choice:";
	cin >> choice;
	return choice;
}

int main() 
{
	string userID, password;
	admin administrator();
	loanControl lC();
	cout << "Welcome to camp equipments borrow system!" << endl;
	while ()
	{
		cout << "Please enter your userID: ";
		cin >> userID;
		cout << "Please enter your password: ";
		cin >> password;
		if (administrator.login(userID, password);)
		{
			cout << "Login successed!" << endl;
			users a(userID);
			switch (getMainMenu())
			{
			case 1:
				administrator.displayAvailableEquipment();
				break;
			case 2:
				administrator.displayLoanRecord(a);
				break;
			case 3:
				administrator.makeLoan(a);
				break;
			case 4:
				administrator.returnEquipment(a);
				break;
			case 5:
				cout << "Thanks for using." << endl;
				break;
			}
			break;
		}
		else
		{
			cout >> "Invalid user ID or password. Please try again.";
			continue;
		}
		system("pause");
		return 0;
	}
}