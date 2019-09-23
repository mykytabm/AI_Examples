#include "Home.h"







Home::Home()
{
}





Home::~Home()
{
}

void Home::Start()
{
	for (size_t i = 0; i < _equipmentNum; i++)
	{
		_equipment.push_back(equipment_none);
	}
	_equipment[0] = lockpick;
	_equipment[1] = climbing_gear;
}

void Home::Update()
{
}
