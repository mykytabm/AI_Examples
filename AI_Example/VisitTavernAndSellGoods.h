#include "State.h"
class Thief;

class VisitTavernAndSellGoods : public State<Thief>
{
private:
	VisitTavernAndSellGoods() {}

	VisitTavernAndSellGoods(const VisitTavernAndSellGoods&);
	VisitTavernAndSellGoods& operator=(const VisitTavernAndSellGoods&);

public:
	static VisitTavernAndSellGoods* Instance();

	virtual void Enter(Thief* thief);
	virtual void Execute(Thief* thief);
	virtual void Exit(Thief* thief);
};