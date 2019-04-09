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
	int DateOfBirth;
public:
	string getName();
	string getId();
	string getSection();
	string getAddress();
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
};

// can borrow up to 3 ltems
class VentureScout : public User {
protected:
	string Rank;
	int LoanNumber;
public:
	VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
};

// can borrow up to 5 Items
class RoverScout : public User {
protected:
	int LoanNumber;
public:
	RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
};

//stop for loan system
// out of loan system but still can borrow
class Scouter : public User {
protected:
	int LoanNumber;
public:
	Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
};
#endif /* groupproject_h */

