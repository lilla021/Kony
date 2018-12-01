#include "PhaseSubject.h"
#include "PhaseObserver.h"
#include "Player.h"
PhaseSubject::PhaseSubject()
{
	_observers = new list<PhaseObserver*>;
}
PhaseSubject::~PhaseSubject()
{
	delete _observers;
}
void PhaseSubject::AttachPhase(PhaseObserver* o, int idPlayer) {
	o->setIDPlayer(idPlayer);
	_observers->push_back(o);
}
void PhaseSubject::DetachPhase(PhaseObserver* o) {
	_observers->remove(o);
}
void PhaseSubject::NotifyPhase(int idPlayer, string action) {
	list<PhaseObserver*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i) {
		if ((*i)->id == idPlayer) {
			(*i)->UpdatePhase(action);
			break;
		}
	}

};

