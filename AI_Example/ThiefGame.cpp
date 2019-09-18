#include "pch.h"
#include "ThiefGame.h"
#include <iostream>
#include "Thief.h"
#include "DayNightCycle.h"

//DayNightCycle dayNight = DayNightCycle();
Thief thief = Thief("Carla");


ThiefGame::ThiefGame()
{
}

void ThiefGame::Initialize()
{

}

void ThiefGame::Start()
{
	thief.Start();
	//dayNight.Start();
}

void ThiefGame::Update()
{
	//dayNight.Update();
	thief.Update();
}



