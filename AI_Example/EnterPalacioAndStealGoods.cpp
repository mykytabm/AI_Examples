#include <iostream>
#include <string>
#include "EnterPalacioAndStealGoods.h"
#include "VisitTavernAndSellGoods.h"
#include "Util.h"
#include "Thief.h"
using namespace std;

EnterPalacioAndStealGoods::EnterPalacioAndStealGoods(Palazzo palazzo)
{
	_palazzo = palazzo;
}

EnterPalacioAndStealGoods* EnterPalacioAndStealGoods::Instance(Palazzo palazzo)
{
	static EnterPalacioAndStealGoods instance = EnterPalacioAndStealGoods(palazzo);
	return &instance;
}

void EnterPalacioAndStealGoods::Enter(Thief* thief)
{
	if (thief->Location() != palacio)
	{
		thief->ChangeLocation(palacio);
		cout << thief->Name() << " arrived to palazzo of " << _palazzo.owner << std::endl;
		cout << "what do you want to do?" << std::endl;
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