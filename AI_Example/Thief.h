#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"

class Thief : public BaseGameEntity
{

private:

	StateMachine<Thief>* _stateMachine;
	location_type _location;

public:

	void Update();
	Thief(location_type spawnLocation);
	~Thief();
};
