#pragma once
#include "State.h"
#include "Util.h"
class Thief;
class EnterPalacioAndStealGoods : public State<Thief>
{
private:
	Palazzo _palazzo;
	EnterPalacioAndStealGoods(const EnterPalacioAndStealGoods&);
	EnterPalacioAndStealGoods& operator=(const EnterPalacioAndStealGoods&);
	void Encounter(Thief* thief);
public:
	EnterPalacioAndStealGoods(Palazzo palazzo);
	static EnterPalacioAndStealGoods* Instance(Palazzo palazzo);

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};
