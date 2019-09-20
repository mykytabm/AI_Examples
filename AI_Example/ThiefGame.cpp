#include "pch.h"
#include "ThiefGame.h"
#include <iostream>
#include "Thief.h"
#include "GoHomeAndRest.h"
#include "EnterPalacioAndStealGoods.h"




Thief thief = Thief("Carla");
ThiefGame* ThiefGame::_instance = 0;


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
	thief.FSM()->SetCurrentState(EnterPalacioAndStealGoods::Instance());

}

void ThiefGame::Update()
{
	thief.Update();

	_hour += 1;
	if (_hour >= 25) _hour = 1;
}



