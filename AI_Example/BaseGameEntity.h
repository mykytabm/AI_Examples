#pragma once
class BaseGameEntity
{
private:
	int _id;
	static int _nextValidID;
	void SetID(int id);
public:


	virtual void Update() = 0;
	int const ID()const { return _id; }
	virtual ~BaseGameEntity();
};

