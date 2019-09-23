#pragma once
#include <map>


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
	help,
	rest,
	plan_robbery,
	buy_goods,
	pockets,
	shelf,
	add,
	replace,
	move,
	drop,
	ready,
	not_ready,
	stop
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
	{"help",			help},
	{"rest",			rest},
	{"plan",			plan_robbery},
	{"pockets",			pockets},
	{"shelf",			shelf},
	{"add",				add},
	{"replace",			replace},
	{"move",			move},
	{"ready",			ready},
	{"not_ready",		not_ready},
	{"stop",			stop}

};
