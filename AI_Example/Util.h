#pragma once
#include <map>


enum location_type
{
	home,
	tavern_red_fool,
	palacio
};


static enum command_type
{
	none,
	help,
	rest,
	plan_robbery,
	go_to,
	buy_goods

};
static std::map <std::string, command_type> StringCommands =
{
	{"help",   help},
	{"rest",   rest},
	{"plan",   plan_robbery},
	{"go",     go_to},
	{"buy",    buy_goods}

};
