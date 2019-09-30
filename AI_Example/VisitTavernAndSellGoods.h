#pragma once
#include "State.h"
#include "Thief.h"
class VisitTavernAndSellGoods : public State<Thief>
{
private:
	VisitTavernAndSellGoods() {}

public:
	static VisitTavernAndSellGoods* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
	~VisitTavernAndSellGoods();
};