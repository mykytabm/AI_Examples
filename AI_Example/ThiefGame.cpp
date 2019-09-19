#include "pch.h"
#include "ThiefGame.h"
#include <iostream>
#include "Thief.h"

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
}

void ThiefGame::Update()
{
	thief.Update();
}



