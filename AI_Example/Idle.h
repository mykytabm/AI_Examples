#pragma once
#include "State.h"
#include "Thief.h"
class Idle :public  State<Thief>
{
private:
	std::vector<command_type> _allowedCommands = {
	command_plan_robbery,
	command_buy_goods,
	};

public:
	// Inherited via State
	virtual void Enter(Thief* thief) override;
	virtual void Execute(Thief* thief) override;
	virtual void Exit(Thief* thief) override;
};

