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
	_fsm->Update();
}

Thief::~Thief()
{
}