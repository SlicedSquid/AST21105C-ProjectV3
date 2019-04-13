#include <iostream>
#include <string>
#include <fstream>
#include "Users.h"
#include "fileHandler.h"
#include "admin.h"
#include "FileHandler.h"
#include "LoanControl.h"
#include "Equipments.h"
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
	string id, password;
	admin administrator;
	fileHandler fH;
	cout << "Welcome to camp equipments borrow system!" << endl;
	while (true)
	{
		cout << "Please enter user ID: ";
		cin >> id;
		cout << "Please enter password: ";
		cin >> password;
		if (fH.login(id, password))
		{
			cout << "You're successfully logged in." << endl;
			User *user = fH.creatUser(id);
			cout << "Welcome! " << user->getName() << endl;
			while (true)
			{
				switch (getMainMenu())
				{
				case 1:
					fH.displayEquipmentList();
					break;
				case 2:
					administrator.displayLoanRecord(user->getName());
					break;
				case 3:
					administrator.makeLoan(user);
					break;
				case 4:
					administrator.returnEquipments(user);
					break;
				case 5:
					cout << "Thanks for using!" << endl;
					system("pause");
					return 0;
					break;
				}
			}
		}
		else
		{
			cout << "Your account or password was entered incorrectly. Please try again." << endl;
		}
	}
	return 0;
}