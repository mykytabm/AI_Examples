#include <string>
#include <cctype>
#include <algorithm>
#include "CommandHandler.h"
#include "GoHomeAndPlanRobbery.h"


CommandHandler* CommandHandler::_instance = 0;

void CommandHandler::HandleCommand(command_type command, Thief*  thief)
{
	switch (command)
	{
	default:
		std::cout << "*coughs* you can do better" << std::endl;
		ReadAndProccessCommand(thief);
		break;
	case help:
		ShowHelp();
		ReadAndProccessCommand(thief);


		break;
	case plan_robbery:
		thief->FSM()->ChangeState(GoHomeAndPlanRobbery::Instance());
		break;

	case buy_goods:
		//set state to enter market and buy/sell goods
		break;
	}



}



void CommandHandler::ShowHelp()
{
	std::cout << "Thief whispers possible commands: " << std::endl;
	for (const auto p : StringCommands)
	{
		std::cout << p.first << std::endl;
	}
}



bool CommandHandler::ParseCommand(std::string commandUnparsed, Thief * thief)
{
	command_type command = command_none;

	std::transform(commandUnparsed.begin(), commandUnparsed.end(), commandUnparsed.begin(),
		[](unsigned char c) { return std::tolower(c); });

	for (const auto p : StringCommands)
	{

		if (commandUnparsed.find(p.first) != std::string::npos)
		{
			command = p.second;
			break;
		}
	}

	if (command != command_none)
	{
		HandleCommand(command, thief);
		return true;
	}
	return false;

}

command_type CommandHandler::ParseCommand(std::string commandUnparsed)
{
	command_type command = command_none;

	std::transform(commandUnparsed.begin(), commandUnparsed.end(), commandUnparsed.begin(),
		[](unsigned char c) { return std::tolower(c); });

	for (const auto p : StringCommands)
	{

		if (commandUnparsed.find(p.first) != std::string::npos)
		{
			command = p.second;
			break;
		}
	}


	return command;

}



location_type CommandHandler::ProccessLocationInput()
{
	std::string unparsedCommand;
	std::cout << "home:   1" << std::endl;
	std::cout << "tavern: 2" << std::endl;
	std::cout << "market: 3" << std::endl;

	std::getline(std::cin, unparsedCommand);
	return (location_type)(((int)unparsedCommand[0]) - '0' - 1);
}


void CommandHandler::ReadAndProccessCommand(Thief * thief)
{
	std::cout << "Enter command:" << std::endl;
	std::string unparsedCommand;
	std::getline(std::cin, unparsedCommand);
	if (!ParseCommand(unparsedCommand, thief))
	{
		std::cout << "Thief did not understand " << unparsedCommand << ", to view possible commands type in help." << std::endl;
		ReadAndProccessCommand(thief);
	}

}

CommandHandler * CommandHandler::Instance()
{
	if (_instance == 0)
	{
		_instance = new CommandHandler();
	}
	return _instance;
}



CommandHandler::~CommandHandler()
{
}
