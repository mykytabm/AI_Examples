#include "pch.h"
#include "ThiefFSM.h"

#include <iostream>
#include "Thief.h"
#include "GoHomeAndRest.h"
#include "EnterPalacioAndStealGoods.h"




Thief thief = Thief("Carla");
ThiefFSM* ThiefFSM::_instance = 0;


ThiefFSM::~ThiefFSM()
{
}

ThiefFSM* ThiefFSM::Instance()
{
	if (_instance == 0)
	{
		_instance = new ThiefFSM();
	}
	return _instance;
}

void ThiefFSM::Initialize()
{
}

void ThiefFSM::Start()
{
	thief.Start();
	thief.FSM()->SetCurrentState(NULL);
	thief.FSM()->ChangeState(EnterPalacioAndStealGoods::Instance());

}

void ThiefFSM::Update()
{
	thief.Update();
}



