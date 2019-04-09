#include<string>
#include <fstream>
#include <iostream>
using namespace std;

int admin()
{
	ifstream myfile;	
	myfile.open("camp_equiment.txt");

	string thing;
	string date;
	string campname;
	string name;
	string itemid;
	string itemname;
	int nb;
	double returndate;
	string itemstatus1;
	string itemstatus2;
	string itemnum;
	bool back;
	string classofitem;
	string  tent;
	string lantern;
	string stoves;

	if (myfile.is_open())
	{	
		while (!myfile.eof())
		{
			myfile >> thing;
			cout << thing << endl;

			myfile >> campname;
			cout << campname << endl;
			myfile >> name;
			cout << name << endl;
			myfile >> itemname;
			cout << itemname << endl;
			myfile >> itemid;
			cout << itemid << endl;
			myfile >> itemstatus1;
			cout << itemstatus1 << endl;
			myfile >> itemstatus2;
			cout << itemstatus2 << endl;
			myfile >> itemnum;
			cout << itemnum << endl;
			myfile >> classofitem;
			cout << classofitem << endl;
		}
		myfile.close();
	}

	ifstream myfile;
	myfile.open("user.txt");

	string campid;
	string borrower;
	string boid;
	string address;
	string level;

	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			myfile >> campid;
			cout << campid << endl;
			myfile >> borrower;
			cout << borrower << endl;
			myfile >> boid;
			cout << boid << endl;
			myfile >> address;
			cout << address << endl;
			myfile >> level;
			cout << level << endl;
		}
		myfile.close();
	}

}
