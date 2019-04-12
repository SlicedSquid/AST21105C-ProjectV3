#pragma once
#include <iostream>
#ifndef ADMIN_H 
#define ADMIN_H
class admin
{
private:
	string a;
	string b;

public:
	void displayAvailableEquipment() const;
	void displayLoanRecord(users a) const;
	void displaycampofequipment(user a) const;
	void makeLoan(users a) const;
	void returnEquipment(users a) const;
};

#endif // !ADMIN_H 