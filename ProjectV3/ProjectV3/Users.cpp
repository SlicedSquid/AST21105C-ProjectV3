#include<iostream>
#include "groupproject.h"
#include "Users.h"
#include "FileHandler.h"
using namespace std;

//get name
string User::getName() {
    return Name;
}
//get id
string User::getId() {
    return Id;
}
//get section
string User::getSection() {
    return Section;
}

//get address
string User::getAddress() {
    return Address;
}
//set id
void User::setId(string id)
{
    this->Id = id;
}

//set password
void User::setPassword(string password)
{
    this->password = password;
}
//check user can loan or not
void User::setLoanStatus(bool status)
{
    onLoan = status;
}
//set how many items that user can loan
void User::setLoanNumber(int number)
{
    LoanNumber -= number;
}

//get dateofbirth
int User::getDateOfBirth() {
    return DateOfBirth;
}

//defalut constructor to prevent error
User::User() {}

//prepared for the inheritance
User::User(string _Id, string _Name, string _Section, string _Address, int _DateOfBirth) {
    Id = _Id;
    Name = _Name;
    Section = _Section;
    Address = _Address;
    DateOfBirth = _DateOfBirth;
}

//sub class Scout inheritance from the class user
Scout::Scout(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
    Rank = _Rank;
    this->Id = Id;
    this->Name = Name;
    this->Section = Section;
    this->Address = Address;
    this->DateOfBirth = DateOfBirth;
    
    //for Assistant Patrol Leader and Patrol Leader, they can loan up to 3 items
    if (_Rank == "Assistant Patrol Leader" || _Rank == "Patrol Leader") {
        LoanNumber = 3;
    }
    else
    {
        //member can only loan 1 item
        LoanNumber = 1;
    }
}

//defalut constructor to prevent error
Scout::Scout(){}

//check scout can loan or not
bool Scout::getStatus()
{
    return onLoan;
}

//if Scout borrow one item, then loannumber - 1(loannumber down to 0)
void Scout::borrowItem()
{
    LoanNumber--;
    onLoan = true;
}

//if Scout return one item, then loannumber + 1(for loannumber up to 3)
void Scout::returnItem()
{
    LoanNumber++;
    //for Assistant Patrol Leader and Patrol Leader the loannumber up to 3
    if (LoanNumber == 3 && (rank == "Assistant Patrol Leader"|| rank == "Patrol Leader"))
    {
        //set they did not borrow anything
        onLoan = false;
    }
    else
    {
        //for member the loannumber up to 1
        if (LoanNumber == 1 && rankrank != "Assistant Patrol Leader" && rank != "Patrol Leader")
        {
            //set they did not borrow anything
            onLoan = false;
        }
    }
}

//sub class VentureScout inheritance from the class user
VentureScout::VentureScout(string Id, string Name, string Section, string Address, int DateOfBirth) {
    this->Id = Id;
    this->Name = Name;
    this->Section = Section;
    this->Address = Address;
    this->DateOfBirth = DateOfBirth;
    LoanNumber = 3;
}

//defalut constructor to prevent error
VentureScout::VentureScout(){}

//check VentureScout can loan or not
bool VentureScout::getStatus()
{
    return onLoan;
}
//if VentureScout borrow one item, then loannumber - 1(loannumber down to 0)
void VentureScout::borrowItem()
{
    LoanNumber--;
    onLoan = true;
}

//if VentureScout return one item, then loannumber + 1(for loannumber up to 3)
void VentureScout::returnItem()
{
    LoanNumber++;
    //for VentureScout loannumber up to 3
    if (LoanNumber == 3)
    {
        //set they did not borrow anything
        onLoan = false;
    }
}
//sub class RoverScout inheritance from the class user
RoverScout::RoverScout(string Id, string Name, string Section, string Address, int DateOfBirth) {
    this->Id = Id;
    this->Name = Name;
    this->Section = Section;
    this->Address = Address;
    this->DateOfBirth = DateOfBirth;
    LoanNumber = 5;
}

//defalut constructor to prevent error
RoverScout::RoverScout(){}

//check RoverScout can loan or not
bool RoverScout::getStatus()
{
    
    if (LoanNumber == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//if RoverScout borrow one item, then loannumber - 1(loannumber down to 0)
void RoverScout::borrowItem()
{
    LoanNumber--;
    //set they borrow something
    onLoan = true;
}
//if VentureScout return one item, then loannumber + 1(for loannumber up to 5)
void RoverScout::returnItem()
{
    LoanNumber++;
    if (LoanNumber == 5)
    {
          //set they did not borrow anything
        onLoan = false;
    }
}

//sub class Scouter inheritance from the class user
Scouter::Scouter(string Id, string Name, string Section, string Address, int DateOfBirth, string  _Rank) {
    this->Id = Id;
    this->Name = Name;
    this->Section = Section;
    this->Address = Address;
    this->DateOfBirth = DateOfBirth;
    LoanNumber = 5;
}

Scouter::Scouter(){}
//check Scouter can loan or not
bool Scouter::getStatus()
{
    if (LoanNumber == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
//if Scouter borrow one item, then loannumber - 1(loannumber down to 0)
void Scouter::borrowItem()
{
    LoanNumber--;
}

//if VentureScout return one item, then loannumber + 1(for loannumber up to 5)
void Scouter::returnItem()
{
    LoanNumber++;
    if (LoanNumber == 5)
    {
        onLoan = false;
    }
}
