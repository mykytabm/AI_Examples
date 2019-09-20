#include "GoHomeAndRest.h"
#include "Locations.h"
#include "ThiefGame.h"
#include "EnterPalacioAndStealGoods.h"



GoHomeAndRest * GoHomeAndRest::Instance()
{
	static GoHomeAndRest instance;
	return &instance;
}

void GoHomeAndRest::Enter(Thief * thief)
{
	_time = ThiefGame::Instance()->Hour();
	if (thief->Location() != home)
	{
		thief->ChangeLocation(home);
	}
}

void GoHomeAndRest::Execute(Thief * thief)
{
	std::cout << *_time;
	if (*_time == 24) {
		thief->FSM()->ChangeState(EnterPalacioAndStealGoods::Instance());
	}
}

void GoHomeAndRest::Exit(Thief * thief)
{
	std::cout << ("Hello darkness my old friend") << std::endl;
}
