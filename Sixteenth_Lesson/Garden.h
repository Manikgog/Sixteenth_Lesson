#ifndef _GARDEN_H_
#define _GARDEN_H_

#include <vector>

template <typename T>
class Garden
{
public:
	std::vector<T> Trees;

	Trees& GetTrees()
	{
		return Trees;
	}
};

#endif
