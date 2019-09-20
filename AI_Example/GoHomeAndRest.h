#pragma once
#include "State.h"
#include "Thief.h"

class GoHomeAndRest : public State<Thief>
{
private:
	int* _time;
	GoHomeAndRest() {}

public:
	static GoHomeAndRest* Instance();

	virtual void Enter(Thief* thief);

	virtual void Execute(Thief* thief);

	virtual void Exit(Thief* thief);
};

