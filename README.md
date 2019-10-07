# AI_Examples
Implementing AI  from book Programming Game AI by example to study different implementations of it.
ThiefFSM has implementation of class based Finite State Machine (FSM);
logic of it is pretty simple:
1) Every state has a reference to its owner and implements unique owner behaviour;
2) Each state also has useful methods Enter and Exit state, which allows to implement logic that does not need to fire multiple times etc;
3) logic of switching states is implemented inside every state;
