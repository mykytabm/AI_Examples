#pragma once
#include "BaseGameEntity.h"
#include "Locations.h"
#include "StateMachine.h"
#include "ThiefFSM.h"

#include <iostream>
#include <string>

class Thief : public BaseGameEntity
{

private:
	StateMachine<Thief>* _fsm;
	location_type _location = location_type::home;
	int _bagSize = 5;
	int _goodsInBag = 0;
	int _gold;
	int _hunger = 0;
	int _energy = 10;

public:
	int Energy() const { return _energy; }
	void UpdateEnergy(const int amount) { _energy += amount; if (_energy < 0) _energy = 0; }

	int Hunger() const { return _hunger; }
	void UpdateHunger(const int amount) { _hunger += amount; if (_hunger < 0) _hunger = 0; }

	void SetAmountOfGoods(const int newGoodsAmount) { _goodsInBag = newGoodsAmount; }
	int AmountOfGoods() { return _goodsInBag; }

	int Gold() const { return _gold; }
	void AddGold(const int amount) { _gold += amount; }

	void SetBagSize(const int newSize) { _bagSize = newSize; }
	int BagSize() const { return _bagSize; }
	void AddGoodsToBag(const int amountOfGoods) { if (_goodsInBag < _bagSize) _goodsInBag += amountOfGoods; }
	bool BagIsFull() const { return  _goodsInBag >= _bagSize; }

	location_type Location() const { return _location; }
	void ChangeLocation(const location_type newLocation) { _location = newLocation; }


	StateMachine<Thief>* FSM() const { return _fsm; }
	Thief(std::string name);
	void Start();
	void Update();
	~Thief();
};
