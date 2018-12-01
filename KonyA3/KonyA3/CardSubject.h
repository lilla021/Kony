#pragma once
#include "CardObserver.h"
#include <list>
using namespace std;
class CardSubject
{
public:
	virtual void AttachCard(CardObserver* o);
	virtual void DetachCard(CardObserver* o);
	virtual void NotifyCard();
	CardSubject();
	~CardSubject();
private:
	list<CardObserver*> *_observers;
};


