#pragma once
#ifndef ADMIN_H 
#define ADMIN_H
#include <iostream>
#include <fstream>
#include <string>
#include "Users.h"
#include "LoanControl.h"
#include "FileHandler.h"
class admin
{
public:
	void displayLoanRecord(string userId);
	void updateEquipmentCondition(string eID, string status);
	void updateLoanStatus(string eID, string status);
	void makeLoan(User* user);
	void returnEquipments(User* user);
};

#endif // !ADMIN_H 