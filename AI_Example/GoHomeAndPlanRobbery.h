#pragma once
#include "State.h"
#include "Thief.h"
#include <string>   
class GoHomeAndPlanRobbery : public State<Thief>
{

private:
	GoHomeAndPlanRobbery() {};
	void ManageEquipment(Thief* thief, Home* home);
	void SelectRobberyTarget(Home* home);
	void DisplayItems(Thief* thief, Home* home, std::string feedback);
	void HandleUserAction(std::vector<command_type> parsedCommands, std::string* s, std::vector<equipment_type>* firstVec, int firstItemIndex,
		std::vector<equipment_type>* secondVec, int  secondItemIndex);
	std::vector<command_type> _allowedCommands = { command_pockets,command_shelf };
public:
	static GoHomeAndPlanRobbery* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};

