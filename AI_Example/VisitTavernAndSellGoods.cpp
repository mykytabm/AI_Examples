#include "VisitTavernAndSellGoods.h"
#include "Locations.h"
#include "Thief.h"
#include "EnterPalacioAndStealGoods.h"

using namespace std;

VisitTavernAndSellGoods* VisitTavernAndSellGoods::Instance()
{
	static VisitTavernAndSellGoods instance;
	return &instance;
}

void VisitTavernAndSellGoods::Enter(Thief* thief)
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

void VisitTavernAndSellGoods::Execute(Thief* thief)
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

void VisitTavernAndSellGoods::Exit(Thief* thief)
{
	cout << "*" << thief->Name() << "  silently leaves the tavern*" << endl;
}