#include <iostream>
#include <string>
#include <fstream.h>
using namespace std;

class fileHandler 
{
private:
	int counter;
public:
	string fileRead(string fileName) 
	{
		string result;
		istream input(fileName);
		input >> result;
		input.close();
		return result;
	}
	void fileWrite(string fileName, string content) 
	{
		ostream output;
		output.open(fileName);
		output << content;
		output.close();
	}
	void displayAvailableEquipments const()
	{
		string a = fileRead("camp_equipment.txt");
	}
};