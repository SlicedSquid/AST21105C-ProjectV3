/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

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
	int LoanNumber;
	int DateOfBirth;
	bool onLoan = false;
public:
	string getName();
	string getId();
	string getSection();
	string getAddress();
	void setId(string id);
	void setPassword(string password);
	void setLoanStatus(bool status);
	void setLoanNumber(int number);
	int getLoanNumber();
	virtual bool getStatus();
	virtual void borrowItem();
	virtual void returnItem();
	int getDateOfBirth();
	User(string _Id, string _Name, string _Section, string _Address, int _DateOfBirth);
	User();
};

// for loan system
// can borrow up to 3 ltems
class Scout : public User {
protected:
	string Rank;
public:
	Scout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
	Scout();
	bool getStatus();
	void borrowItem();
	void returnItem();
};

// can borrow up to 3 ltems
class VentureScout : public User {
public:
	VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth);
	VentureScout();
	bool getStatus();
	void borrowItem();
	void returnItem();
};

// can borrow up to 5 Items
class RoverScout : public User {
public:
	RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth);
	RoverScout();
	bool getStatus();
	void borrowItem();
	void returnItem();
};

//stop for loan system
// out of loan system but still can borrow
class Scouter : public User {
private:
	string Rank;
public:
	Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank);
	Scouter();
	bool getStatus();
	void borrowItem();
	void returnItem();
};
#endif /* groupproject_h */

