#include "State.h"
#include "Thief.h"

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

class VisitMamaJulieAndSellGoods : public State<Thief>
{
private:
	VisitMamaJulieAndSellGoods() {}

	VisitMamaJulieAndSellGoods(const VisitMamaJulieAndSellGoods&);
	VisitMamaJulieAndSellGoods& operator=(const VisitMamaJulieAndSellGoods&);

public:
	static VisitMamaJulieAndSellGoods* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};

class GoHomeAndSleepTilRested : public State<Thief>
{
private:
	GoHomeAndSleepTilRested() {}

	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
	GoHomeAndSleepTilRested& operator=(const GoHomeAndSleepTilRested&);
public:
	static GoHomeAndSleepTilRested* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};

