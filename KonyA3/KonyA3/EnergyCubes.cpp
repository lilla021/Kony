#include "EnergyCubes.h"

EnergyCubes::EnergyCubes()
{
	total = 1000;
}
EnergyCubes::EnergyCubes(int i)
{
	total = i;
}
int EnergyCubes::getTotal()
{
	return total;
}
void EnergyCubes::setTotal(int i)
{
	total = i;
}
EnergyCubes::~EnergyCubes()
{
}

