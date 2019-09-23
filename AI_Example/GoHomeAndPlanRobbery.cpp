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
}

void GoHomeAndPlanRobbery::ManageEquipment(Thief* thief, Home* home)
{
	std::string s = "";
	//print items in the shelf
	std::cout << "========== Equipment Shelf ==========" << std::endl;
	for (size_t i = 0; i < home->Equipment().size(); i++)
	{
		std::cout << i + 1 << ": " << EquipmentNames[home->Equipment()[i]] << std::endl;
	}

	//print items in thiefs' pockets
	std::cout << "========== " << thief->Name() << " pockets " << " ==========" << std::endl;
	for (size_t i = 0; i < thief->Pockets().size(); i++)
	{
		std::cout << i + 1 << ": " << EquipmentNames[thief->Pockets()[i]] << std::endl;
	}
	while (true)
	{
		std::cout << "to add/replace/move or drop items use commands: " << std::endl;
		std::cout << "pockets add 1, to add 1st item from shelf to pockets " << std::endl;
		std::cout << "pockets remove 1, to remove 1st item from pockets to shelf" << std::endl;
		std::cout << "pockets replace 1  2, to replace 1st item in pockets with 2nd item in shelf " << std::endl;
		std::cout << "pockets drop 1, to drop 1st item  (delete it)" << std::endl;

		std::getline(std::cin, s);


		std::vector<std::string> result;
		std::vector <command_type> parsedCommands;
		bool modifyThiefPockets = false;
		std::vector<equipment_type> targetVec;
		int firstItemIndex = -1;
		int secondItemIndex = -1;


		std::istringstream iss(s);
		for (std::string s; iss >> s; )
			result.push_back(s);
		for (int i = 0; i < 2; i++)
		{
			parsedCommands.push_back(CommandHandler::Instance()->ParseCommand(result[i]));
		}
		targetVec = parsedCommands[0] == pockets ? thief->Pockets() : home->Equipment();
		switch (parsedCommands[1])
		{
		case add:
			//TODO: get rid of  checks on is digid and length, find better way
			//if (isdigit(result[2][0]) && result[2].length() == 1)

			break;


		case replace:
			if (isdigit(result[2][0]) && isdigit(result[3][0]) && result[2].length() == 1 && result[3].length() == 1)
			{
				firstItemIndex = (int)(result[2][0] - '0');

				secondItemIndex = (int)(result[3][0] - '0');
			}
			break;


		case drop:

			break;


		case move:

			break;
		}




	}
}


void GoHomeAndPlanRobbery::Execute(Thief * thief)
{
}

void GoHomeAndPlanRobbery::Exit(Thief * thief)
{

}



