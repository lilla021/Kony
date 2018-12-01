#pragma once
class CardObserver
{
public:
	~CardObserver();
	virtual void UpdateCard() = 0;

protected:
	CardObserver();
};


