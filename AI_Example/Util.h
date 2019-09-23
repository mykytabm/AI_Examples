#pragma once
#include <map>


enum location_type
{
	home,
	tavern_red_fool,
	market,
	palacio

};

enum equipment_type
{
	lockpick,
	rope,
	pincet,
	tobos
};

enum command_type
{
	none,
	help,
	rest,
	plan_robbery,
	//go_to,
	buy_goods
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
	//{"go",				go_to},
	{"buy",				buy_goods}
};
