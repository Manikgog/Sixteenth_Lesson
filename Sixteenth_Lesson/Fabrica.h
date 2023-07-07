#ifndef _FABRICA_H_
#define _FABRICA_H_

#include <iostream>
#include "Plant.h"

class FabricaOfTrees
{
public:
	virtual std::unique_ptr<Plant> makePlant() = 0;
	virtual ~FabricaOfTrees() {}
};

class Apple : public FabricaOfTrees
{
public:
	std::unique_ptr<Plant> makePlant()
	{
		return std::unique_ptr<AppleTree(("дерево"s, "средний"s, 50), "\'Антоновка\'"s)>;
	}
};


#endif
