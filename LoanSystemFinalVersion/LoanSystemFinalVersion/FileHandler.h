/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <fstream>
#include <string>
#include "Equipments.h"
#include "Users.h"

class fileHandler 
{
public:
	equipments* creatEquipment(string reg);
	User *creatUser(string reg);
	void displayEquipmentList();
	void displayAllEquipmentList();
	bool login(string id, string password) ;
	void changeLoanStatus(User* user);
	void insertFiles();
};

#endif // !FILEHANDLER_H
