#pragma once
#include <map>


struct Palazzo
{
	std::string name = "";
	std::string owner = "";
	std::string shortDescription = "";
	int numberOfFloors = 0;
	int numberOfExits = 0;
	int guards = 0;
	bool dog;
};

enum location_type
{
	location_none,
	home,
	tavern_red_fool,
	market,
	palacio

};

enum equipment_type
{
	equipment_none,
	lockpick,
	climbing_gear,
	knife,
	smoke_bomb
};

enum command_type
{
	command_none,
	command_help,
	command_rest,
	command_plan_robbery,
	command_buy_goods,
	command_pockets,
	command_shelf,
	command_add,
	command_replace,
	command_remove,
	command_drop,
	command_ready,
	command_not_ready,
	command_stop
};


static std::map<equipment_type, std::string> EquipmentNames =
{
	{lockpick,				"lockpick"},
	{climbing_gear,			"climbing gear"},
	{knife,					"knife"},
	{smoke_bomb,			"smoke bomb"}
};

static std::map <location_type, std::string> LocationNames =
{
	{home,				"home"},
	{tavern_red_fool,	"tavern 'red fool'"},
	{market,			"black market"},
	{palacio,			"palacio"}
};




static std::map <std::string, command_type> StringCommands =
{
	{"help",			command_help},
	{"rest",			command_rest},
	{"plan",			command_plan_robbery},
	{"pockets",			command_pockets},
	{"shelf",			command_shelf},
	{"add",				command_add},
	{"replace",			command_replace},
	{"remove",			command_remove},
	{"drop",			command_drop},
	{"ready",			command_ready},
	{"not_ready",		command_not_ready},
	{"stop",			command_stop}

};
