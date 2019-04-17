/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

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
	// Select a function that user want to use
	int choice;
	do
	{
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
	} while (choice < 1 || choice > 5);
	return choice;
}

int getAdminMenu()
{
	// Enter the admin, choose a function for administrator
	int choice;
	do
	{
		cout << "************************************" << endl;
		cout << "*                                  *" << endl;
		cout << "*      Welcome! Administrator      *" << endl;
		cout << "*                                  *" << endl;
		cout << "************************************" << endl;
		cout << "1) Insert files" << endl;
		cout << "2) Display loan record" << endl;
		cout << "3) Display equipments list" << endl;
		cout << "4) Update equipment condition" << endl;
		cout << "5) Produce txt to store updated data" << endl;
		cout << "6) Exit" << endl;
		cout << "Please enter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice > 6);
	return choice;
}

int main()
{
	// Store the ID and password
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
		// Enter system as a administrator
		if (id == "admin" && password == "admin")
		{
			// Run the purpose funciton
			while (true)
			{
				string eID, status;
				switch (getAdminMenu())
				{
				case 1:
					fH.insertFiles();
					break;
				case 2:
					administrator.displayLoanRecord();
					break;
				case 3:
					fH.displayAllEquipmentList();
					break;
				// Change the condition of equipment
				case 4:
					cout << "Please enter the equipment ID:";
					cin >> eID;
					equipments *e;
					e = fH.creatEquipment(eID);
					if (e->returnStatus())
					{
						status = "out";
					}
					else
					{
						status = "in";
					}
					administrator.updateEquipmentCondition(eID,status);
					administrator.updateLoanStatus(eID, status);
					delete e;
					break;
				case 5:
					cout << "The file has been automatically produced!" << endl;
					cout << "loan record is stored in loan_record.txt" << endl;
					cout << "updated equipment is store in updated_equipment.txt" << endl;
					break;
				case 6:
					cout << "Thanks for using!" << endl;
					system("pause");
					return 0;
					break;
				}
			}
		}
		else
		{
			// Enter the system as user
			if (fH.login(id, password))
			{
				cout << "You're successfully logged in." << endl;
				User *user = fH.creatUser(id);
				cout << "Welcome! " << user->getName() << endl;
				// Run the purpose funciton
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
						delete user;
						return 0;
						break;
					}
				}
			}
			// While wrong password entered
			else
			{
				cout << "Your account or password was entered incorrectly. Please try again." << endl;
			}
		}
	}
}