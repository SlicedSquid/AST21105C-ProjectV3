/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

#include<iostream>
#include "Users.h"
#include "FileHandler.h"
using namespace std;

string User::getName() {
	return Name;
}

string User::getId() {
	return Id;
}

string User::getSection() {
	return Section;
}

string User::getAddress() {
	return Address;
}

void User::setId(string id)
{
	this->Id = id;
}

void User::setPassword(string password)
{
	this->password = password;
}

void User::setLoanStatus(bool status)
{
	onLoan = status;
}

void User::setLoanNumber(int number)
{
	LoanNumber = number;
}

int User::getLoanNumber()
{
	return LoanNumber;
}

bool User::getStatus()
{
	return true;
}

void User::borrowItem()
{
	LoanNumber--;
	onLoan = true;
}

void User::returnItem()
{
}


int User::getDateOfBirth() {
	return DateOfBirth;
}

User::User(string _Id, string _Name, string _Section, string _Address, int _DateOfBirth) {
	Id = _Id;
	Name = _Name;
	Section = _Section;
	Address = _Address;
	DateOfBirth = _DateOfBirth;
}

User::User() {}

Scout::Scout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) : User(Id, Name, Section, Address, DateOfBirth){
	Rank = _Rank;
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	if (_Rank == "Assistant Patrol Leader" || _Rank == "Patrol Leader") {
		LoanNumber = 3;
	}
	else
	{
		//only member can loan 1 item
		LoanNumber = 1;
	}
}

Scout::Scout() : User() {}

bool Scout::getStatus()
{
	return onLoan;
}

void Scout::borrowItem()
{
	LoanNumber--;
	onLoan = true;
}

void Scout::returnItem()
{
	LoanNumber++;
	if (LoanNumber == 3 && ((Rank == "Assistant Patrol Leader")||(Rank == "Patrol Leader") ))
	{
		onLoan = false;
	}
	else
	{
		if (LoanNumber == 1 && Rank != "Assistant Patrol Leader" && Rank != "Patrol Leader")
		{
			onLoan = false;
		}
	}
}

VentureScout::VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth):  User(Id, Name, Section, Address, DateOfBirth) 
{
	LoanNumber = 3;
}

VentureScout::VentureScout(){}

bool VentureScout::getStatus()
{
	return onLoan;
}

void VentureScout::borrowItem()
{
	LoanNumber--;
	onLoan = true;
}

void VentureScout::returnItem()
{
	LoanNumber++;
	if (LoanNumber == 3)
	{
		onLoan = false;
	}
}

RoverScout::RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth) : User(Id, Name, Section, Address, DateOfBirth) 
{
	LoanNumber = 5;
}

RoverScout::RoverScout()
{
}

bool RoverScout::getStatus()
{
	return onLoan;
}

void RoverScout::borrowItem()
{
	LoanNumber--;
	onLoan = true;
}

void RoverScout::returnItem()
{
	LoanNumber++;
	if (LoanNumber == 5)
	{
		onLoan = false;
	}
}

Scouter::Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) : User(Id, Name, Section, Address, DateOfBirth) {
	LoanNumber = 5;
}

Scouter::Scouter()
{
}

bool Scouter::getStatus()
{
	return onLoan;
}

void Scouter::borrowItem()
{
	LoanNumber--;
	onLoan = true;
}

void Scouter::returnItem()
{
	LoanNumber++;
	if (LoanNumber == 3 && ((Rank == "Assistant Patrol Leader") || (Rank == "Patrol Leader")))
	{
		onLoan = false;
	}
	else
	{
		if (LoanNumber == 1 && Rank != "Assistant Patrol Leader" && Rank != "Patrol Leader")
		{
			onLoan = false;
		}
	}
}
