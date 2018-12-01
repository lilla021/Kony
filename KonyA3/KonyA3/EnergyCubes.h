#pragma once
class EnergyCubes
{
public:
	EnergyCubes();
	EnergyCubes(int i);
	~EnergyCubes();
	int getTotal();
	void setTotal(int i);
private:
	int total; // number of cubes, could be any large number! Not indicated
};

