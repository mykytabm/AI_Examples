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
		_equipmentShelf.push_back(equipment_none);
	}
	_equipmentShelf[0] = lockpick;
	_equipmentShelf[1] = climbing_gear;
}

void Home::Update()
{
}
