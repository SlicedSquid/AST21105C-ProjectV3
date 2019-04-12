#include "LoanControl.h"

bool loanControl::check(User* user, string equipmentID)
{
	fileHandler fH;
	equipments* e;
	e = fH.creatEquipment(equipmentID);
	if (user->getStatus()&&e->returnStatus())
	{
		return true;
	}
	else
	{
		return false;
	}
}
