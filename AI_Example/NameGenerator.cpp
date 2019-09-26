#include "NameGenerator.h"
#include <stdio.h>    
#include <stdlib.h>   
#include <time.h>
#include <chrono>


NameGenerator* NameGenerator::_instance = 0;

std::string NameGenerator::GenerateName()
{
	std::string s = "";

	s = _firstName[rand() % _firstName.size()] + " ";

	if (rand() % 11 > 7)
	{
		//srand(time(NULL));
		s += _middleAdditive[rand() % _middleAdditive.size()] + " ";
	}
	s += _secondName[rand() % _secondName.size()];
	return s;
}

NameGenerator * NameGenerator::Instance()
{
	if (_instance == 0)
	{
		_instance = new NameGenerator();
	}
	return _instance;
}



NameGenerator::NameGenerator()
{
	srand(time(NULL));

	_firstName = std::vector<std::string>{
	"Alboino",
	"Zaccaria",
	"Teodoto",
	"Gianluigi",
	"Onesto",
	"Bonaventura",
	"Democrito",
	"Tizio",
	"Misaele",
	"Petronio"
	};
	_secondName = std::vector<std::string>{
	"Cimaglia",
	"Guttilla",
	"Pietrantonio",
	"Virginia",
	"Lauricella",
	" Massarelli",
	"Sclafani",
	"Bonomi",
	"Andreano",
	"Sisco",
	"Sabina"
	};
	_middleAdditive = std::vector<std::string>{
		"Lo",
		"La",
		"Le",
		"De"

	};

}
