#pragma once
#include "BaseGameEntity.h"
#include "Util.h"
#include "StateMachine.h"
#include "Home.h"
#include <iostream>
#include <list>
#include <string>
#include "ThiefGame.h"
class Thief : public BaseGameEntity
{

private:
	StateMachine<Thief>* _fsm;
	location_type _location = home;
	int _bagSize = 5;
	int _goodsInBag = 0;
	int _gold;
	int _hunger = 0;
	std::list<equipment_type> equipment;
	Home* _home;
public:
	Home* ThiefHome() { return _home; }
	int Hunger() const { return _hunger; }
	int Gold() const { return _gold; }
	void UpdateHunger(const int amount) { _hunger += amount; if (_hunger < 0) _hunger = 0; }
	StateMachine<Thief>* FSM() const { return _fsm; }
	void AddGoodsToBag(const int amountOfGoods) { if (_goodsInBag < _bagSize) _goodsInBag += amountOfGoods; }
	void SetAmountOfGoods(const int newGoodsAmount) { _goodsInBag = newGoodsAmount; }
	int AmountOfGoods() { return _goodsInBag; }
	void AddGold(const int amount) { _gold += amount; }
	void SetBagSize(const int newSize) { _bagSize = newSize; }
	int BagSize() const { return _bagSize; }
	bool BagIsFull() const { return  _goodsInBag >= _bagSize; }
	location_type Location() const { return _location; }
	void ChangeLocation(const location_type newLocation);

	Thief(std::string name, Home* home);
	void Start();
	void Update();
	~Thief();
};
