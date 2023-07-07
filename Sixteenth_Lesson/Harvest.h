#ifndef _HARVEST_H_
#define _HARVEST_H_

#include <string>

class Harvest
{
private:
	std::string _harvestName;
	float _weight;
	std::string _color;

public:
	Harvest(const std::string& harvestName, float weight, const std::string& color)
		: _harvestName(harvestName), _weight(weight), _color(color) {}

	virtual ~Harvest() {}

	std::string GetHarvestName()
	{
		return _harvestName;
	}

	float GetWeight()
	{
		return _weight;
	}

	std::string GetColor()
	{
		return _color;
	}

	virtual void PrintHarvest() = 0;


};

class Apple : public Harvest
{
private:
	std::string _sortOfApple;

public:
	Apple(std::string harvestName, float weight, std::string color, std::string sortOfApple)
		: Harvest(harvestName, weight, color), _sortOfApple(sortOfApple) {}


	void PrintHarvest() override
	{
		std::cout << "Вид плода: " << GetHarvestName() << "\nВес плода: " << GetWeight() << "\nЦвет плода: " << GetColor() << std::endl;
		std::cout << "Сорт: " << _sortOfApple << std::endl;
	}

};


#endif // !_HARVEST_H_

