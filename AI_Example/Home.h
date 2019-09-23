#pragma once
#include <iostream>
#include <array>
#include "Util.h"
#include "BaseGameEntity.h"

class Home : public BaseGameEntity
{
private:
	std::array<equipment_type, 6> _equipment = std::array<equipment_type, 6>();
public:
	std::array<equipment_type, 6>& Equipment() { return _equipment; }
	Home();
	~Home();

	// Inherited via BaseGameEntity
	virtual void Start() override;
	virtual void Update() override;
};

