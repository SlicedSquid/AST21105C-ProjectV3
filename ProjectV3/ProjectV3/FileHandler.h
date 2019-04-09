#pragma once
#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <fstream>
#include <string>

class fileHandler 
{
private:
	istream input;
public:
	void displayEquipmentList() const;
};

#endif // !FILEHANDLER_H
