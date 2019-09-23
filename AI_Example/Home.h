#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "Util.h"
#include "BaseGameEntity.h"

class Home : public BaseGameEntity
{
private:
	std::vector<equipment_type> _equipment = std::vector<equipment_type>();
	int _equipmentNum = 6;
public:
	std::vector<equipment_type>& Equipment() { return _equipment; }
	Home();
	~Home();

	// Inherited via BaseGameEntity
	virtual void Start() override;
	virtual void Update() override;
};

