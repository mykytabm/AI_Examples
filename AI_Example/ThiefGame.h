#pragma once
#include "Game.h"


class ThiefGame : public Game
{

private:
	int _hour;
	static ThiefGame* _instance;

	ThiefGame() {};
public:
	int* Hour() { return&_hour; }
	static ThiefGame* Instance();
	void Initialize();
	void Start();
	void Update();
};

