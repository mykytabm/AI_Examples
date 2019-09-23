#pragma once
#include "State.h"
#include "Thief.h"
class GoHomeAndPlanRobbery : public State<Thief>
{

private:
	GoHomeAndPlanRobbery() {};
	void ManageEquipment();
public:
	static GoHomeAndPlanRobbery* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};

