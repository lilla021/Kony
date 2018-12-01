#pragma once
class StatsObserver
{
public:
	~StatsObserver();
	virtual void UpdateStats() = 0;

protected:
	StatsObserver();
};


