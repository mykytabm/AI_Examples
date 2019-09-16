#pragma once

#include "State.h"
#include <cassert>
#include <string>


template <class entity_type>
class StateMachine
{

private:

	entity_type*          m_pOwner;

	State<entity_type>*   m_pCurrentState;

	//a record of the last state the agent was in
	State<entity_type>*   m_pPreviousState;

	//this is called every time the FSM is updated
	State<entity_type>*   m_pGlobalState;


public:
	//StateMachine(entity_type* owner) : m_pOwner(owner),
	//	m_pCurrentState(NULL),
	//	m_pPreviousState(NULL),
	//	m_pGlobalState(NULL);


	~StateMachine();
};

