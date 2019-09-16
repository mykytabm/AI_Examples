#pragma once
#include "BaseGameEntity.h"
class DayNightCycle : public BaseGameEntity
{
public:
	DayNightCycle();
	~DayNightCycle();

	// Inherited via BaseGameEntity
	virtual void Start() override;
	virtual void Update() override;
};

