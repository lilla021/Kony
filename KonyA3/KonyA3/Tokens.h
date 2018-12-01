#pragma once
#include <iostream>
class Tokens
{
public:
	Tokens();
	virtual ~Tokens();
	std::string getTokenName();
	void setTokTotal(int i) {
		tokTotal = i;
	}
	int getTokTotal() {
		return tokTotal;
	}
protected:
	int tokTotal;
	std::string name;
};
class Web : public Tokens {
public:
	Web();
	virtual ~Web();
};
class Jinx : public Tokens {
public:
	Jinx();
	virtual ~Jinx();
};
class Souvenir : public Tokens {
public:
	Souvenir();
	virtual ~Souvenir();
};
class Carapace : public Tokens {
public:
	Carapace();
	virtual ~Carapace();
};

