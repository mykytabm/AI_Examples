#include "GoHomeAndRest.h"
#include "Locations.h"
#include "ThiefFSM.h"
#include "EnterPalacioAndStealGoods.h"



GoHomeAndRest* GoHomeAndRest::Instance()
{
	static GoHomeAndRest instance;
	return &instance;
}

void GoHomeAndRest::Enter(Thief* thief)
{
	if (thief->Location() != location_type::home)
	{
		thief->ChangeLocation(location_type::home);
		std::cout << "finally home, will relax for a little bit" << std::endl;
	}
}

void GoHomeAndRest::Execute(Thief* thief)
{
	if (thief->Energy() > 9)
		thief->FSM()->ChangeState(EnterPalacioAndStealGoods::Instance());

	thief->UpdateEnergy(2);
}

void GoHomeAndRest::Exit(Thief* thief)
{
	std::cout << ("It is time to do dark things.") << std::endl;
}
