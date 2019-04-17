/*
***********************************************************************
*                AST21105C - ProjectV3 - Group 14                     *
***********************************************************************
*          Contributors: Anthony, Gary, Justin, Mow, Zan              *
* Open Source URL: https://github.com/SlicedSquid/AST21105C-ProjectV3 *
***********************************************************************
*/

#include "LoanControl.h"

// Change the certain loan recod 
bool loanControl::check(User* user, equipments* e)
{
	if (user->getStatus()&&e->returnStatus())
	{
		return true;
	}
	else
	{
		return false;
	}
}