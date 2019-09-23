#include <iostream>
#include "pch.h"
#include "Thief.h"
#include "GoHomeAndRest.h"
#include "EnterPalacioAndStealGoods.h"
#include "CommandHandler.h"
#include "ThiefGame.h"
#include "Home.h"

ThiefGame* ThiefGame::_instance = 0;
CommandHandler* commandHandler = CommandHandler::Instance();
Home thiefHome = Home();
Thief thief = Thief("Carla", &thiefHome);
ThiefGame* ThiefGame::Instance()
{
	if (_instance == 0)
	{
		_instance = new ThiefGame();
	}
	return _instance;
}

void ThiefGame::Initialize()
{
	_hour = 18;
}

void ThiefGame::Start()
{
	thief.Start();
	thiefHome.Start();

	std::cout << "Thief " << thief.Name() << " just appeared in Venice, in his/her small palacio" << std::endl;
	commandHandler->ReadAndProccessCommand(&thief);

	//thief.ChangeLocation(home);
	//thief.FSM()->ChangeState(EnterPalacioAndStealGoods::Instance());
}

void ThiefGame::Update()
{
	thief.Update();

	_hour += 1;
	if (_hour >= 25) _hour = 1;
}



