#include "GoHomeAndPlanRobbery.h"





void GoHomeAndPlanRobbery::ManageEquipment()
{

}

GoHomeAndPlanRobbery * GoHomeAndPlanRobbery::Instance()
{
	static GoHomeAndPlanRobbery instance;
	return &instance;
}



void GoHomeAndPlanRobbery::Enter(Thief * thief)
{
	if (thief->Location() != home)
	{
		thief->ChangeLocation(home);
	}
	std::cout << "its time to plan this night" << std::endl;
	std::cout << "*sips a bit of wine*" << std::endl;
	std::cout << "Manage " << thief->Name() << " equipment" << std::endl;
}

void GoHomeAndPlanRobbery::Execute(Thief * thief)
{
}

void GoHomeAndPlanRobbery::Exit(Thief * thief)
{
}
