#include "pch.h"
#include "BaseGameEntity.h"

int BaseGameEntity::_nextValidID = 0;


void BaseGameEntity::SetID(int val)
{
	_id = val;
	_nextValidID = _id + 1;
}

