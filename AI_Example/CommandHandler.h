#pragma once
#include "Thief.h"
#include "Util.h"
#include <iostream>

class CommandHandler
{
private:

	static CommandHandler* _instance;

	CommandHandler() {};

	void HandleCommand(command_type command, Thief* thief);

	bool ParseCommand(std::string commandUnparsed, Thief* thief);

public:

	static CommandHandler* Instance();

	void ReadAndProccessCommand(Thief* thief);

	void ShowHelp();

	location_type ProccessLocationInput();

	~CommandHandler();

};

