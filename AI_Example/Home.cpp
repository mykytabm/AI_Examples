#include "Home.h"
#include "NameGenerator.h"




Home::~Home()
{
}
Home::Home()
{

}

void Home::Start()
{
	GenerateEquipment();
	GeneratePalazzo();
}

void Home::Update()
{
}

void Home::GenerateEquipment()
{
	for (size_t i = 0; i < _equipmentNum; i++)
	{
		_equipmentShelf.push_back(equipment_none);
	}
	_equipmentShelf[0] = lockpick;
	_equipmentShelf[1] = climbing_gear;
}

void Home::GeneratePalazzo()
{
	for (size_t i = 0; i < 2; i++)
	{
		Palazzo p;
		p.owner = NameGenerator::Instance()->GenerateName();
		p.shortDescription = " Its old, like everything in here...";
		p.dog = false;
		p.guards = 2;
		p.numberOfExits = 5;
		p.numberOfFloors = 4;
		_availablePalazzos.push_back(p);
	}
}
