/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

#ifndef LOANCONTROL_H
#define LOANCONTROL_H
#include <iostream>
#include <string>
#include "Users.h"
#include "Equipments.h"
#include "FileHandler.h"
using namespace std;

class loanControl
{
public:
	bool check(User* user, equipments* e);
};
#endif // !LOANCONTROL_H