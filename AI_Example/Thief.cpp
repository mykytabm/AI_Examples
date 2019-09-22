#include "EnterPalacioAndStealGoods.h"
#include <iostream>
#include "Thief.h"


Thief::Thief(std::string name)
{
	_name = name;
	_fsm = new StateMachine<Thief>(this);
}

void Thief::Start()
{
	
}

void Thief::Update()
{
	_fsm->Update();

}

Thief::~Thief()
{
}