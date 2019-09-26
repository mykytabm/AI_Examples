#pragma once
#include <iostream>
#include <array>
#include <vector>
#include "Util.h"
#include "BaseGameEntity.h"

class Home : public BaseGameEntity
{
private:
	std::vector <Palazzo> _availablePalazzos = std::vector<Palazzo>();
	std::vector<equipment_type> _equipmentShelf = std::vector<equipment_type>();
	int _equipmentNum = 6;

	void GenerateEquipment();
	void GeneratePalazzo();

public:
	Home();
	std::vector<Palazzo>* Palazzos() { return &_availablePalazzos; }
	std::vector<equipment_type>* Equipment() { return &_equipmentShelf; }
	~Home();

	// Inherited via BaseGameEntity
	virtual void Start() override;
	virtual void Update() override;
};

