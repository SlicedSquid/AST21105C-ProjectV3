/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

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
	void displayLoanRecord();
	void updateEquipmentCondition(string eID, string status);
	void updateLoanStatus(string eID, string status);
	void makeLoan(User* user);
	void returnEquipments(User* user);
};

#endif // !ADMIN_H