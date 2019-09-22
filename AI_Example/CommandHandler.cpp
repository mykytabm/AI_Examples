#include <string>
#include <cctype>
#include <algorithm>
#include "CommandHandler.h"



CommandHandler* CommandHandler::_instance = 0;

void CommandHandler::HandleCommand(command_type command, Thief*  thief)
{

}

void CommandHandler::ParseCommand(std::string commandUnparsed, Thief * thief)
{
	command_type command = none;

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

	if (command != 0)
	{
		HandleCommand(command, thief);
	}
	else
	{
		//TODO: Show error message suggest to retype command, view help etc
	}
}



void CommandHandler::ReadAndProccessCommand(Thief * thief)
{
	std::string unparsedCommand;
	std::getline(std::cin, unparsedCommand);
	ParseCommand(unparsedCommand, thief);

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
