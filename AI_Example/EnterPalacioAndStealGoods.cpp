#include "EnterPalacioAndStealGoods.h"
#include "VisitTavernAndSellGoods.h"
#include "Locations.h"
#include <iostream>
#include <string>
#include "Thief.h"
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
		cout << thief->Name() << ": "
			<< "Heading to some lords' palacio.." << endl;
		thief->ChangeLocation(palacio);
	}
}

void EnterPalacioAndStealGoods::Execute(Thief* thief)
{
	thief->AddGoodsToBag(1);
	thief->UpdateHunger(1);
	cout << thief->Name() << ": "
		<< "Oh, this is now mine.";
	cout << " *" << thief->Name() << " found 1  good*" << endl;

	if (thief->BagIsFull() || thief->Hunger() > 8)
	{
		thief->FSM()->ChangeState(VisitTavernAndSellGoods::Instance());
	}
}

void EnterPalacioAndStealGoods::Exit(Thief* thief)
{
	cout << thief->Name() << ": "
		<< "its time to leave." << endl;
}