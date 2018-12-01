#pragma once
#include "PhaseObserver.h"
#include <list>
using namespace std;

class PhaseSubject
{
public:
	virtual void AttachPhase(PhaseObserver* o, int idPlayer);
	virtual void DetachPhase(PhaseObserver* o);
	virtual void NotifyPhase(int idPlayer, string action);
	PhaseSubject();
	~PhaseSubject();
private:
	list<PhaseObserver*> *_observers;
};


