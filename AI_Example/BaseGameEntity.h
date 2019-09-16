#pragma once
#include <iostream>
#include <string>

class BaseGameEntity
{
private:
	int _id;
	void SetID(int id);
	std::string _name;
public:

	std::string Name() { return _name; };
	virtual void Start() = 0;
	virtual void Update() = 0;
	int const ID()const { return _id; }
	virtual ~BaseGameEntity();
};

