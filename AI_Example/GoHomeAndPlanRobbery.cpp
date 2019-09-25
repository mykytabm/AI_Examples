#include <vector>
#include <iostream>
#include <sstream>  
#include <string>   
#include <cctype>
#include <algorithm>
#include "CommandHandler.h"
#include "GoHomeAndPlanRobbery.h"
GoHomeAndPlanRobbery * GoHomeAndPlanRobbery::Instance()
{
	static GoHomeAndPlanRobbery instance;
	return &instance;
}



void GoHomeAndPlanRobbery::Enter(Thief * thief)
{

	if (thief->Location() != home)
	{
		thief->ChangeLocation(home);
	}
	std::cout << "*sips a bit of wine* " << "its time to plan this night" << std::endl;
	std::cout << "Manage " << thief->Name() << " equipment" << std::endl;
	ManageEquipment(thief, thief->ThiefHome());
	std::cout << "now select mansion" << std::endl;
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
		bool userOperatesPockets = parsedCommands[0] == pockets;
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

		HandleUserAction(parsedCommands, firstVec, firstItemIndex, secondVec, secondItemIndex);

	}
}
void GoHomeAndPlanRobbery::HandleUserAction(std::vector<command_type> parsedCommands,
	std::vector<equipment_type>* firstVec, int firstItemIndex,
	std::vector<equipment_type>* secondVec, int  secondItemIndex)
{
	switch (parsedCommands[1])
	{
	default:

		break;
	case add:

		for (int i = 0; i < firstVec->size(); i++)
		{
			if (firstVec->at(i) == equipment_none)
			{
				if (firstItemIndex > secondVec->size()) break;
				firstVec->at(i) = secondVec->at(firstItemIndex - 1);
				secondVec->at(firstItemIndex - 1) = equipment_none;
				break;
			}
		}
		break;


	case replace:
	{
		if (firstItemIndex > firstVec->size() || secondItemIndex > secondVec->size()) break;

		equipment_type temp = firstVec->at(firstItemIndex - 1);
		firstVec->at(firstItemIndex - 1) = secondVec->at(secondItemIndex - 1);
		secondVec->at(secondItemIndex - 1) = temp;
		break;

	}
	case drop:

		firstVec->at(firstItemIndex - 1) = equipment_none;
		break;


	case move:
		for (int i = 0; i < secondVec->size(); i++)
		{
			if (secondVec->at(i) == equipment_none)
			{

				secondVec->at(i) = firstVec->at(firstItemIndex - 1);
				firstVec->at(firstItemIndex - 1) = equipment_none;
				break;
			}
		}
		break;
	}
}

void GoHomeAndPlanRobbery::DisplayItems(Thief * thief, Home * home, std::string feedback)
{
	//print items in the shelf
	std::cout << "========== Equipment Shelf ==========" << std::endl;
	for (size_t i = 0; i < home->Equipment()->size(); i++)
	{
		std::cout << i + 1 << ": " << EquipmentNames[home->Equipment()->at(i)] << std::endl;
	}

	//print items in thiefs' pockets
	std::cout << "========== " << thief->Name() << " pockets " << " ==========" << std::endl;
	for (size_t i = 0; i < thief->Pockets()->size(); i++)
	{
		std::cout << i + 1 << ": " << EquipmentNames[thief->Pockets()->at(i)] << std::endl;
	}

	std::cout << "to add/replace/move or drop items use commands: " << std::endl;
	std::cout << "pockets add 1, to add 1st item from shelf to pockets " << std::endl;
	std::cout << "pockets remove 1, to remove 1st item from pockets to shelf" << std::endl;
	std::cout << "pockets replace 1  2, to replace 1st item in pockets with 2nd item in shelf " << std::endl;
	std::cout << "pockets drop 1, to drop 1st item  (delete it)" << std::endl;
	//std::cout << feedback << std::endl;
}


void GoHomeAndPlanRobbery::Execute(Thief * thief)
{
}

void GoHomeAndPlanRobbery::Exit(Thief * thief)
{

}



