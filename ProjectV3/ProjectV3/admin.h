#pragma once
#ifndef ADMIN_H 
#define ADMIN_H
#include <iostream>
#include <fstream>
#include <string>
#include "Users.h"
#include "LoanControl.h"
class admin
{
private:
	istream input;
public:
	void displayLoanRecord(string userId);
	void updateEquipmentCondition(string equipmentID, string status);
	void makeLoan(User* user);
};

#endif // !ADMIN_H 