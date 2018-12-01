#include "CardSubject.h"
#include "CardObserver.h"
CardSubject::CardSubject()
{
	_observers = new list<CardObserver*>;
}
CardSubject::~CardSubject()
{
	delete _observers;
}
void CardSubject::AttachCard(CardObserver* o) {
	_observers->push_back(o);
}
void CardSubject::DetachCard(CardObserver* o) {
	_observers->remove(o);
}
void CardSubject::NotifyCard() {
	list<CardObserver*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->UpdateCard();
};

