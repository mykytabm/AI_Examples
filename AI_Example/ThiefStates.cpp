#include "ThiefStates.h"
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
		thief->GetFSM()->ChangeState(VisitMamaJulieAndSellGoods::Instance());
	}
}

void EnterPalacioAndStealGoods::Exit(Thief* thief)
{
	cout << thief->Name() << ": "
		<< "its time to leave." << endl;
}

VisitMamaJulieAndSellGoods* VisitMamaJulieAndSellGoods::Instance()
{
	static VisitMamaJulieAndSellGoods instance;
	return &instance;
}

void VisitMamaJulieAndSellGoods::Enter(Thief* thief)
{
	if (thief->Location() != tavern_red_fool)
	{
		cout << thief->Name() << ": "
			<< "On my way to mama Julie" << endl;

		thief->ChangeLocation(tavern_red_fool);
	}

	cout << "*opens the tavern door*" << endl;
	int goods = thief->AmountOfGoods();

	if (goods > 0)
	{
		cout << "*Mama Julie takes thiefs' goods and gives back gold coins*" << endl;

		cout << "*" << goods << " goods were sold for " << goods << " gold*" << endl;
		thief->AddGold(thief->AmountOfGoods());
		thief->SetAmountOfGoods(0);
	}

}

void VisitMamaJulieAndSellGoods::Execute(Thief* thief)
{
	if (thief->Hunger() >= 2 && thief->Gold() >= 1)
	{
		cout << " thief sits and drinks a bit of wine" << endl;
		cout << "thief spent one gold" << endl;
		thief->AddGold(-1);
		thief->UpdateHunger(-2);
	}
	else
		thief->GetFSM()->ChangeState(EnterPalacioAndStealGoods::Instance());
}

void VisitMamaJulieAndSellGoods::Exit(Thief* thief)
{
	cout << "*" << thief->Name() << "  silently leaves the tavern*" << endl;

}