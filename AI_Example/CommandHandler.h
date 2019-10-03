#pragma once
#include "Thief.h"
#include "Util.h"
#include <iostream>
#include <vector>

class CommandHandler
{
private:

	static CommandHandler* _instance;
	CommandHandler() {};

	void HandleCommand(command_type command, Thief* thief);

	bool ParseCommand(std::string commandUnparsed, Thief* thief);

	std::vector<command_type> _globalCommands = { command_help,command_ready,command_not_ready };
public:

	void ParseCommand(command_type* command,const std::string* commandUnparsed, const std::vector<command_type>* allowedCommands);

	void TryParseGlobalCommand(std::string)

	bool CommandAllowed(std::vector<command_type> alllowedCommands, command_type command);
	static CommandHandler* Instance();

	void ReadAndProccessCommand(Thief* thief);

	command_type ParseCommand(std::string commandUnparsed);

	void ShowHelp();

	location_type ProccessLocationInput();

	~CommandHandler();

};

