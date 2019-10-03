#include <vector>
#include <iostream>
#include <sstream>  
#include <cctype>
#include <algorithm>
#include "CommandHandler.h"
#include "GoHomeAndPlanRobbery.h"
#include "EnterPalacioAndStealGoods.h"
GoHomeAndPlanRobbery* GoHomeAndPlanRobbery::Instance()
{
	static GoHomeAndPlanRobbery instance;
	return &instance;
}



void GoHomeAndPlanRobbery::Enter(Thief* thief)
{

	if (thief->Location() != home)
	{
		thief->ChangeLocation(home);
	}

	std::cout << "*sips a bit of wine* " << "its time to plan this night" << std::endl;
	std::cout << "I need to choose who I will be robbing this time" << std::endl;

	SelectRobberyTarget(thief->ThiefHome());
	std::cout << "Now I need to pick right equipment" << std::endl;
	ManageEquipment(thief, thief->ThiefHome());
	thief->FSM()->ChangeState(EnterPalacioAndStealGoods::Instance(_targetPalazzo));
}

GoHomeAndPlanRobbery::GoHomeAndPlanRobbery()
{
	_targetPalazzo = Palazzo();
}

bool GoHomeAndPlanRobbery::PlayerReady(std::string s)
{
	return CommandHandler::Instance()->ParseCommand(s) == command_ready;
}
void GoHomeAndPlanRobbery::ManageEquipment(Thief* thief, Home* home)
{
	bool userReady = false;
	std::string feedback = "";
	while (!userReady)
	{
		system("cls");
		DisplayItems(thief, home, feedback);

		std::string s = "";
		std::getline(std::cin, s);

		userReady = PlayerReady(s);

		int firstItemIndex = -1;
		int secondItemIndex = -1;

		std::vector<equipment_type>* firstVec = new std::vector<equipment_type>();
		std::vector<equipment_type>* secondVec = new std::vector<equipment_type>();

		//separate space separation
		std::vector<std::string> result;
		std::istringstream iss(s);
		for (std::string s; iss >> s; )
			result.push_back(s);

		std::vector <command_type> parsedCommands = { command_none, command_none };

		for (size_t i = 0; i < result.size(); i++)
		{
			parsedCommands.at(i) = (CommandHandler::Instance()->ParseCommand(result[i]));
			if (i == 1) break;
		}

		if (!CommandHandler::Instance()->CommandAllowed(_allowedCommands, parsedCommands[0]))
		{
			feedback = "incorrect input";
			continue;
		}

		//setup equipment vectors according to user input
		bool userOperatesPockets = parsedCommands[0] == command_pockets;
		firstVec = userOperatesPockets ? thief->Pockets() : home->Equipment();
		secondVec = userOperatesPockets ? home->Equipment() : thief->Pockets();


		if (result.size() > 2)
		{
			std::istringstream issFirstItem(result[2]);
			issFirstItem >> firstItemIndex;
			if (issFirstItem.fail()) {
				feedback = "incorrect input";
				continue;
			}
		}
		if (result.size() > 3)
		{
			std::istringstream issSecondItem(result[3]);
			issSecondItem >> secondItemIndex;
			if (issSecondItem.fail()) {
				feedback = "incorrect input";
				continue;
			}
		}

		HandleUserAction(parsedCommands, &feedback, firstVec, firstItemIndex, secondVec, secondItemIndex);

	}
}


void GoHomeAndPlanRobbery::SelectRobberyTarget(Home* home)
{
	system("cls");
	int x = 0;
	while (_targetPalazzo.owner == "")
	{
		auto palazzoVec = home->Palazzos();
		for (size_t i = 0; i < palazzoVec->size(); i++)
		{
			auto p = palazzoVec->at(i);
			std::cout << "=============================" << i + 1 << ". Palazzo of " << p.owner << " =============================" << std::endl << std::endl;

			std::cout << "Additional notes: " << p.shortDescription << std::endl << std::endl;

			std::cout << "Number of floors: " << p.guards << std::endl << std::endl;

			std::cout << "Number of guards: " << p.numberOfFloors << std::endl << std::endl;

			std::cout << "Number of exits: " << p.numberOfExits << std::endl << std::endl;

			std::cout << "Dog: " << (p.dog ? " Si" : " No ") << std::endl << std::endl;
		}
		std::cout << "=====================================================================================" << std::endl;
		std::string s = "";
		std::getline(std::cin, s);
		//TODO: insert handling exit commands
		//if (CommandHandler::Instance()->ParseCommand(s) == command_stop)

		std::stringstream iss(s);

		if (iss >> x)
		{
			if (x > palazzoVec->size())
				continue;
			x--;
			_targetPalazzo = palazzoVec->at(x);
		}
	}

}


void GoHomeAndPlanRobbery::HandleUserAction(std::vector<command_type> parsedCommands, std::string* s,
	std::vector<equipment_type>* firstVec, int firstItemIndex,
	std::vector<equipment_type>* secondVec, int  secondItemIndex)
{
	firstItemIndex--;
	secondItemIndex--;
	std::string feedback = *s;
	switch (parsedCommands[1])
	{
	default:
		*s = "incorrect input";
		break;
	case command_add:

		for (int i = 0; i < firstVec->size(); i++)
		{
			if (firstVec->at(i) == equipment_none)
			{
				if (firstItemIndex > secondVec->size() - 1) break;

				*s = "Item " + EquipmentNames[secondVec->at(firstItemIndex)] + " was added";

				firstVec->at(i) = secondVec->at(firstItemIndex);
				secondVec->at(firstItemIndex) = equipment_none;
				break;
			}
		}
		break;


	case command_replace:
	{
		if (firstItemIndex > firstVec->size() - 1 || secondItemIndex > secondVec->size() - 1) break;

		*s = "Item " + EquipmentNames[firstVec->at(firstItemIndex)] +
			" was replaced with " + EquipmentNames[secondVec->at(secondItemIndex)];

		equipment_type temp = firstVec->at(firstItemIndex);
		firstVec->at(firstItemIndex) = secondVec->at(secondItemIndex);
		secondVec->at(secondItemIndex) = temp;
		break;

	}
	case command_drop:

		*s = "Item " + EquipmentNames[firstVec->at(firstItemIndex)] + " was dropped";

		firstVec->at(firstItemIndex) = equipment_none;


		break;


	case command_remove:
		for (int i = 0; i < secondVec->size(); i++)
		{
			if (secondVec->at(i) == equipment_none)
			{
				*s = "Item " + EquipmentNames[firstVec->at(firstItemIndex)] + " was removed";
				secondVec->at(i) = firstVec->at(firstItemIndex);
				firstVec->at(firstItemIndex) = equipment_none;

				break;
			}
		}
		break;
	}
}


void GoHomeAndPlanRobbery::DisplayItems(Thief* thief, Home* home, std::string feedback)
{
	//print items in the shelf
	std::cout << "======================= Target: " << "Palazzo of " << _targetPalazzo.owner << " =======================" << std::endl;
	std::cout << "================================== Equipment Shelf ==================================" << std::endl;
	for (size_t i = 0; i < home->Equipment()->size(); i++)
	{
		std::cout << i + 1 << ": " << EquipmentNames[home->Equipment()->at(i)] << std::endl;
	}

	//print items in thiefs' pockets
	std::cout << "================================== " << thief->Name() << " pockets " << " ==================================" << std::endl;
	for (size_t i = 0; i < thief->Pockets()->size(); i++)
	{
		std::cout << i + 1 << ": " << EquipmentNames[thief->Pockets()->at(i)] << std::endl;
	}

	std::cout << "to add/replace/remove or drop items use commands: " << std::endl;
	std::cout << "pockets add 1, to add 1st item from shelf to pockets " << std::endl;
	std::cout << "pockets remove 1, to move 1st item from pockets to shelf" << std::endl;
	std::cout << "pockets replace 1  2, to replace 1st item in pockets with 2nd item in shelf " << std::endl;
	std::cout << "pockets drop 1, to drop 1st item  (get rid of it)" << std::endl;
	std::cout << "===================================================================================" << std::endl;
	std::cout << feedback << std::endl;
	std::cout << "===================================================================================" << std::endl;
}


void GoHomeAndPlanRobbery::Execute(Thief* thief)
{
}

void GoHomeAndPlanRobbery::Exit(Thief* thief)
{

}



