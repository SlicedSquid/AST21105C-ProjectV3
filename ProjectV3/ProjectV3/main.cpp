#include <iostream>
#include "users.h"
#include "fileHandler.h"
using namespace std;


int getMainMenu()
{
	int choice;
	bool run;
	do {
		cout << "------------------------------------" << endl;
		cout << "1) Display available camp equipments" << endl;
		cout << "2) Display loan record" << endl;
		cout << "3) Make equipment loan" << endl;
		cout << "4) Return equipment" << endl;
		cout << "5) Exit" << endl;
		cout << "------------------------------------" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
		cout << "------------------------------------" << endl;
		// Run the program when the "choice" is correct
		run = true;
		if (choice < 1 || choice > 5)
			run = false;
	} while (!run);
	return choice;
}

int main()
{
	User user* = new User;
	string id, password;
	admin administrator();
	fileHandler fH();
	loanControl lC();
	cout << "Welcome to camp equipments borrow system!" << endl;
	while ()
	{
		cout << "Please enter user ID: ";
		cin >> id;
		cout << "Please enter password: ";
		cin >> password;
		user.setId(id);
		user.setPassword(password);
		if (fH.login(user))
		{
			cout << "You're successfully logged in." << endl;
			*user = fH.creatUser(userID);
			switch (getMainMenu())
			{
			case 1:
				fH.displayEquipmentList();
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
				cout << "Thanks for using!" << endl;
				break;
			}
			break;
		}
		else
		{
			cout >> "Your account or password was entered incorrectly. Please try again.";
		}
	}
	system("pause");
	return 0;
}