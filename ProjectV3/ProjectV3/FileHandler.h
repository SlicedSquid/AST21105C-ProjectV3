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
private:
	istream input;
	string *userID;
	string *userPassword;
public:
	equipments creatEquipment(string reg);
	*User creatUser(string reg);
	void displayEquipmentList();
	bool login(User * user) const;
	bool login(string id, string password) const;
};

#endif // !FILEHANDLER_H
