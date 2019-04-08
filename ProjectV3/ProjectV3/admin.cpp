#include<string>
#include <fstream>
#include <iostream>
using namespace std;

int display() {
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
	string campid;
	string borrower;
	string boid;
	string address;
	string level;

	ifstream myfile("D:\\camp_equiment.txt");
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, thing);
			cout << thing << endl;
			getline(myfile, campname);
			cout << campname << endl;
			getline(myfile, name);
			cout << name << endl;
			getline(myfile,itemname );
			cout << itemname << endl;
			getline(myfile, itemid);
			cout << itemid << endl;
			getline(myfile, itemstatus1);
			cout << itemstatus1 << endl;
			getline(myfile, itemstatus2);
			cout << itemstatus2 << endl;
			getline(myfile, itemnum);
			cout << itemnum << endl;
			getline(myfile, classofitem);
			cout << classofitem << endl;
		}
		myfile.close();
	}
	ifstream myfile("D:\\user.txt");
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, campid);
			cout << campid << endl;
			getline(myfile, borrower);
			cout << borrower << endl;
			getline(myfile, boid);
			cout << boid << endl;
			getline(myfile, address);
			cout << address << endl;
			getline(myfile, level);
			cout << level << endl;
		}
		myfile.close();
	}

}

int main()
{
	
	string username, password;

	cout << "Welcome to camp equipment loan system!" << endl;
	cout << "Please enter your name: ";
	cin >> username;
	cout << "Please enter your password: ";
	cin >> password;

	if (username == "admin" && password == "admin") {
		cout << "login in succss" << endl;


	}
	else
	{
		cout << "Invalid user ID or password. Please try again." << endl;

	}
	
	

	ofstream output("record.txt");
	output << username << " " << password << endl;
	output.close();

	system("pause");
	return 0;
}
