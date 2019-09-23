#include "EnterPalacioAndStealGoods.h"
#include <iostream>
#include "Thief.h"




void Thief::ChangeLocation(const location_type newLocation)
{
	_location = newLocation;
	std::cout << "Thief just arrived to: " << LocationNames[_location] << std::endl;
}

Thief::Thief(std::string name, Home* home)
{
	_name = name;
	_fsm = new StateMachine<Thief>(this);
	_home = home;
}

void Thief::Start()
{
	//initialize default thief equipment
	_pockets[0] = lockpick;
	_pockets[1] = lockpick;



}

void Thief::Update()
{
	_fsm->Update();

}

Thief::~Thief()
{
}