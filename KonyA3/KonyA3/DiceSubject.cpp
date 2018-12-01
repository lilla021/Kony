#include "DiceSubject.h"
#include "DiceObserver.h"

DiceSubject::DiceSubject()
{
	_observers = new list<DiceObserver*>;
}
DiceSubject::~DiceSubject()
{
	delete _observers;
}
void DiceSubject::AttachDice(DiceObserver* o) 
{
	_observers->push_back(o);
};
void DiceSubject::DetachDice(DiceObserver* o) 
{
	_observers->remove(o);
};
void DiceSubject::NotifyDice() 
{
	list<DiceObserver*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->UpdateDice();
	
};