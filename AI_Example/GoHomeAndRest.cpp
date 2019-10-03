#include "Util.h"
#include "ThiefGame.h"
#include "EnterPalacioAndStealGoods.h"
#include "GoHomeAndRest.h"



GoHomeAndRest* GoHomeAndRest::Instance()
{
	static GoHomeAndRest instance;
	return &instance;
}

void GoHomeAndRest::Enter(Thief* thief)
{
	_time = ThiefGame::Instance()->Hour();
	if (thief->Location() != home)
	{
		thief->ChangeLocation(home);
		std::cout << "its time to sleep" << std::endl;
	}
}

void GoHomeAndRest::Execute(Thief* thief)
{
	//std::cout << *_time;
	//if (*_time == 24) {
	//}
}

void GoHomeAndRest::Exit(Thief* thief)
{
	std::cout << ("Hello darkness my old friend") << std::endl;
}
