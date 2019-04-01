#include <iostream>
#include <fstream>
using namespace std;

class fileHandler 
{
private:
	string *reg = new string;
public:
	string *fileRead(string fileName, int line) 
	{
		istream input(fileName);
		for (int i = 0; i < line; i++)
		{
			getline(input, reg);
		}
		input.close();
		return reg;
	}
	void fileWrite() 
	{


	}
};