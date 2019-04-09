#include<iostream>
#include "groupproject.h"
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
	// reset loannumber
	cout << "Loan Number is " << LoanNumber << endl;
}

VentureScout::VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	LoanNumber = 3;
	cout << "Loan Number is " << LoanNumber << endl;
}

RoverScout::RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	LoanNumber = 5;
	// reset loannumber
	cout << "Loan Number is " << LoanNumber << endl;
}

Scouter::Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
	this->Id = Id;
	this->Name = Name;
	this->Section = Section;
	this->Address = Address;
	this->DateOfBirth = DateOfBirth;
	LoanNumber = 5;
	// reset loannumber
	cout << "Loan Number is " << LoanNumber << endl;
}