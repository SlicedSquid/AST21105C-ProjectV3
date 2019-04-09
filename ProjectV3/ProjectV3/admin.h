#pragma once
#include <iostream>
#ifndef ADMIN_H 
class admin 
{
private:
	
public:
	void displayAvailableEquipment() const;
	void displayLoanRecord(users a) const;
	void makeLoan(users a) const;
	void returnEquipment(users a) const;
};

#endif // !ADMIN_H 

