#include "pch.h"
#include <iostream>
#include "ThiefFSM.h"

#include <thread>
#include <chrono>  

int main()
{
	ThiefFSM* MyThiefGame = ThiefFSM::Instance();


	MyThiefGame->Initialize();
	MyThiefGame->Start();

	for (int i = 0; i < 100; i++)
	{
		MyThiefGame->Update();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}

