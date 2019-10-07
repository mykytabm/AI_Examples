#pragma once
#include "Game.h"


class ThiefFSM : public Game
{

private:
	static ThiefFSM* _instance;

	ThiefFSM() {};
	~ThiefFSM();

public:
	static ThiefFSM* Instance();
	void Initialize();
	void Start();
	void Update();
};

