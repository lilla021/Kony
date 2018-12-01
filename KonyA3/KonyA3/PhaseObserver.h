#pragma once
#include <string>
class PhaseObserver {
public:
	~PhaseObserver();
	virtual void UpdatePhase(std::string action) = 0;
	void setIDPlayer(int idPlayer);
	int id;
protected:
	PhaseObserver();
};
