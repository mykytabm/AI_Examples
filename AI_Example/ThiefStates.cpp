#include "pch.h"
#include "ThiefStates.h"
#include "Locations.h"
#include <iostream>
#include <string>

using namespace std;

EnterPalacioAndStealGoods* EnterPalacioAndStealGoods::Instance()
{
	static EnterPalacioAndStealGoods instance;
	return &instance;
}
void EnterPalacioAndStealGoods::Enter(Thief* thief)
{
	if (thief->Location() != palacio)
	{
		cout << thief->Name() << ":" << "heading to some lords' palacio..";
		thief->ChangeLocation(palacio);
	}
}

void EnterPalacioAndStealGoods::Execute(Thief* thief)
{
	thief->AddGoodsToBag(1);
	//thief->
}
void EnterPalacioAndStealGoods::Exit(Thief* thief)
{
	//thief->AddGoodsToBag(1);
	//thief->
}