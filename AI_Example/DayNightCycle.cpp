//#include "pch.h"
//#include "DayNightCycle.h"
//#include "DayNightCycleStates.h"
//
//DayNightCycle::DayNightCycle()
//{
//	_fsm = new StateMachine<DayNightCycle>(this);
//	_fsm->SetCurrentState(Day::Instance());
//}
//
//
//DayNightCycle::~DayNightCycle()
//{
//}
//
//void DayNightCycle::Start()
//{
//	_currentHour = 6;
//}
//
//void DayNightCycle::Update()
//{
//	_currentHour += 1;
//	if (_currentHour > 24) _currentHour = 1;
//}
