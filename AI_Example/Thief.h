#include "BaseGameEntity.h"
#include "Locations.h"

class Thief : public BaseGameEntity
{

private:
	location_type _location;
	int _bagSize = 5;
	int _goodInBag = 0;

public:
	void AddGoodsToBag(const int amountOfGoods) { if (_goodInBag < _bagSize) _goodInBag += amountOfGoods; }
	void SetBagSize(const int newSize) { _bagSize = newSize; }
	int BagSize() const { return _bagSize; }
	location_type Location() const { return _location; }
	void ChangeLocation(const location_type newLocation) { _location = newLocation; }

	Thief(std::string name);
	void Start();
	void Update();
	~Thief();
};
