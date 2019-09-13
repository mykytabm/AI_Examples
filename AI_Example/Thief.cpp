#include "Thief.h"


Thief::Thief(location_type spawnLocation)
{
	_location = spawnLocation;

}
void Thief::Update()
{

}

Thief::~Thief()
{
	delete _stateMachine;
}