#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "Util.h"
#include "BaseGameEntity.h"

class Home : public BaseGameEntity
{
private:
	//std::vector <
		std::vector<equipment_type> _equipmentShelf = std::vector<equipment_type>();
	int _equipmentNum = 6;
public:
	std::vector<equipment_type>* Equipment() { return &_equipmentShelf; }
	Home();
	~Home();

	// Inherited via BaseGameEntity
	virtual void Start() override;
	virtual void Update() override;
};

