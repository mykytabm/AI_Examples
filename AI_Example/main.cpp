
#include "pch.h"
#include <fstream>
#include <iostream>
#include "ThiefGame.h"
#include <thread>
#include <chrono>
using namespace std;

ofstream out;

int main()
{
	ThiefGame MyThiefGame = ThiefGame();


	MyThiefGame.Initialize();
	MyThiefGame.Start();

	for (int i = 0; i < 100; i++)
	{
		MyThiefGame.Update();
		this_thread::sleep_for(2s);
	}

	return 0;
}

