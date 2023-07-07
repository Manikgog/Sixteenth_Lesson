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

//class FabricaOfAppleTrees : public FabricaOfTrees
//{
//public:
//	std::unique_ptr<Plant> makePlant()
//	{
//		AppleTree a("дерево"s, "средний"s, 50, "\'Антоновка\'"s);
//		return std::unique_ptr<>;
//	}
//};


#endif
