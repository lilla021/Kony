#pragma once
#include "StatsObserver.h"
#include <list>
using namespace std;
class StatsSubject
{
public:
	virtual void AttachStats(StatsObserver* o);
	virtual void DetachStats(StatsObserver* o);
	virtual void NotifyStats();
	StatsSubject();
	~StatsSubject();
private:
	list<StatsObserver*> *_observers;
};


