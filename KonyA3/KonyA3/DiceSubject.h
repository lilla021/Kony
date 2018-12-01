#pragma once
#include "DiceObserver.h"
#include <list>
using namespace std;
class DiceSubject
{
public:
	virtual void AttachDice(DiceObserver* o);
	virtual void DetachDice(DiceObserver* o);
	virtual void NotifyDice();
	DiceSubject();
	~DiceSubject();
private:
	list<DiceObserver*> *_observers;
};
