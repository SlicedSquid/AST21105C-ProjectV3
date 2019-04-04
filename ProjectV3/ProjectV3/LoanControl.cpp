#include "LoanControl.h"

bool loanControl::check(users a, equipments b)
{
	if (a.getStatus()&&b.getStatus())
	{
		return true;
	}
	else
	{
		return false;
	}
}