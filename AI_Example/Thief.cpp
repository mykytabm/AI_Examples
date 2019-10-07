#include "Thief.h"
#include "EnterPalacioAndStealGoods.h"
#include <iostream>


Thief::Thief(std::string name)
{
	_name = name;
	_fsm = new StateMachine<Thief>(this);
}

void Thief::Start()
{
	std::cout << "Thief " << _name << " just appeared somewhere in Venice" << std::endl;
}

void Thief::Update()
{
	std::cout << "===============================" << std::endl;
	std::cout << " Hunger: " << _hunger << std::endl;
	std::cout << " Energy: " << _energy << std::endl;
	std::cout << " Gold: " << _gold << std::endl;
	std::cout << " Items in Bag: " << _goodsInBag << ":" << _bagSize << std::endl;
	std::cout << "===============================" << std::endl;
	_fsm->Update();
}

Thief::~Thief()
{
}