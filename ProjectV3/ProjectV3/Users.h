#ifndef GROUPPROJECT_H
#define GROUPPROJECT_H
#include <iostream>
using namespace std;

class User {
protected:
	string Id;
	string Name;
	string Section;
	string Address;
	string password;
	int DateOfBirth;
public:
	string getName();
	string getId();
	string getSection();
	string getAddress();
	void setId(string id);
	void setPassword(string password);
	virtual bool getStatus() = 0;
	virtual void borrowItem() = 0;
	int getDateOfBirth();
	User();
	User(string _Id, string _Name, string _Section, string _Address, int _DateOfBirth);
};

// for loan system
// can borrow up to 3 ltems
class Scout : public User {
protected:
	string Rank;
	int LoanNumber;
public:
	Scout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
	Scout();
	bool getStatus();
	void borrowItem();
};

// can borrow up to 3 ltems
class VentureScout : public User {
protected:
	int LoanNumber;
public:
	VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth);
	VentureScout();
	bool getStatus();
	void borrowItem();
};

// can borrow up to 5 Items
class RoverScout : public User {
protected:
	int LoanNumber;
public:
	RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth);
	RoverScout();
	bool getStatus();
	void borrowItem();
};

//stop for loan system
// out of loan system but still can borrow
class Scouter : public User {
protected:
	int LoanNumber;
public:
	Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
	Scouter();
	bool getStatus();
	void borrowItem();
};
#endif /* groupproject_h */

