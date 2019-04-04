#include <iostream>
#include <fstream.h>
using namespace std;

class fileHandler 
{
private:
	string *reg = new string;
public:
	string *fileRead(string fileName) 
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
};