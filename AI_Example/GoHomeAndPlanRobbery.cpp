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
	system("cls");
	while (true)
	{
		std::string s = "";
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

		std::getline(std::cin, s);


		std::vector<std::string> result;
		std::vector <command_type> parsedCommands;
		bool modifyThiefPockets = false;
		int firstItemIndex = -1;
		int secondItemIndex = -1;
		std::vector<equipment_type>* firstVec;
		std::vector<equipment_type>* secondVec;

		std::istringstream iss(s);
		for (std::string s; iss >> s; )
			result.push_back(s);
		for (int i = 0; i < 2; i++)
		{
			parsedCommands.push_back(CommandHandler::Instance()->ParseCommand(result[i]));
		}


		firstVec = parsedCommands[0] == pockets ? thief->Pockets() : home->Equipment();
		secondVec = parsedCommands[0] == pockets ? home->Equipment() : thief->Pockets();
		try
		{
			std::istringstream issFirstItem(result[2]);
			issFirstItem >> firstItemIndex;
			if (issFirstItem.fail()) {
				std::cout << "error" << std::endl;
				// something wrong happened
			}

			if (result.size() > 3)
			{
				std::istringstream issSecondItem(result[3]);
				issSecondItem >> secondItemIndex;
				if (issSecondItem.fail()) {
					std::cout << "error" << std::endl;
					// something wrong happened
				}
			}

		}
		catch (const std::exception&)
		{
			std::cout << "error" << std::endl;
			//ManageEquipment(thief, home);
		}



		switch (parsedCommands[1])
		{
		case add:

			for (int i = 0; i < firstVec->size(); i++)
			{
				if (firstVec->at(i) == equipment_none)
				{

					firstVec->at(i) = secondVec->at(firstItemIndex - 1);
					secondVec->at(firstItemIndex - 1) = equipment_none;
					break;
				}
			}
			break;


		case replace:
		{
			equipment_type temp = firstVec->at(firstItemIndex - 1);
			firstVec->at(firstItemIndex - 1) = secondVec->at(secondItemIndex - 1);
			secondVec->at(secondItemIndex - 1) = temp;
			break;

		}
		case drop:
			firstVec->at(firstItemIndex) = equipment_none;
			break;


		case move:
		{
			for (int i = 0; i < secondVec->size(); i++)
			{
				if (secondVec->at(i) = equipment_none)
				{
					secondVec->at(i) = firstVec->at(firstItemIndex);
					firstVec->at(firstItemIndex) = equipment_none;
					break;
				}
			}
			std::cout << "you cant do that" << std::endl;
		}
		}

		break;
	}


	ManageEquipment(thief, thief->ThiefHome());

}


void GoHomeAndPlanRobbery::Execute(Thief * thief)
{
}

void GoHomeAndPlanRobbery::Exit(Thief * thief)
{

}



