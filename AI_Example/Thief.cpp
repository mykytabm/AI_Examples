#include "Thief.h"
#include "ThiefStates.h"
#include <iostream>

Thief::Thief(std::string name)
{
	_name = name;
	_fsm = new StateMachine<Thief>(this);
	_fsm->SetCurrentState(EnterPalacioAndStealGoods::Instance());
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