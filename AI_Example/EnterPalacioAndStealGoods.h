#pragma once
#include "State.h"

class Thief;
class EnterPalacioAndStealGoods : public State<Thief>
{
private:
	EnterPalacioAndStealGoods() {}

	EnterPalacioAndStealGoods(const EnterPalacioAndStealGoods&);
	EnterPalacioAndStealGoods& operator=(const EnterPalacioAndStealGoods&);


public:
	static EnterPalacioAndStealGoods* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};
