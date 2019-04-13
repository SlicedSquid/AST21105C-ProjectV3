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
	LoanNumber -= number;
}

int User::getLoanNumber()
{
	return LoanNumber;
}

bool User::getStatus()
{
	return false;
}

void User::borrowItem()
{
}

void User::returnItem()
{
}


int User::getDateOfBirth() {
	return DateOfBirth;
}

User::User() {}

User::User(string _Id, string _Name, string _Section, string _Address, int _DateOfBirth) {
	Id = _Id;
	Name = _Name;
	Section = _Section;
	Address = _Address;
	DateOfBirth = _DateOfBirth;
}

Scout::Scout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
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

Scout::Scout(){}

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

VentureScout::VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
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

RoverScout::RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	LoanNumber = 5;
}

RoverScout::RoverScout()
{
}

bool RoverScout::getStatus()
{
	if (LoanNumber == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
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

Scouter::Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	LoanNumber = 5;
}

Scouter::Scouter()
{
}

bool Scouter::getStatus()
{
	if (LoanNumber == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Scouter::borrowItem()
{
	LoanNumber--;
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
