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
	bool login(string id, string password) ;
	void changeLoanStatus(User* user);
};

#endif // !FILEHANDLER_H
