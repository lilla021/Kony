#pragma once
class DiceObserver
{
public:
	~DiceObserver();
	virtual void UpdateDice() = 0;
protected: 
	DiceObserver();
};

