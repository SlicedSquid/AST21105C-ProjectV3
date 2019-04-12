#include<iostream>
#include "groupproject.h"
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
	if (LoanNumber == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Scout::borrowItem()
{
	LoanNumber--;
}

VentureScout::VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	LoanNumber = 3;
	cout << "Loan Number is " << LoanNumber << endl;
}

VentureScout::VentureScout(){}

bool VentureScout::getStatus()
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

void VentureScout::borrowItem()
{
	LoanNumber--;
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
