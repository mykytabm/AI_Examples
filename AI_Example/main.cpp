
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>
#include "pch.h"
#include "ThiefGame.h"
using namespace std;

ofstream out;

int main()
{
	ThiefGame* MyThiefGame = ThiefGame::Instance();


	MyThiefGame->Initialize();
	MyThiefGame->Start();

	while(true)
	{
		MyThiefGame->Update();
		this_thread::sleep_for(1s);
	}

	return 0;
}

