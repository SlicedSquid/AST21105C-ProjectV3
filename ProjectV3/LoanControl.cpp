#include "LoanControl.h"

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
