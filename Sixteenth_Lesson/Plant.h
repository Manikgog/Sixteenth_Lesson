#ifndef _PLANT_H_
#define _PLANT_H_

#include <string>
#include "Harvest.h"

class Plant
{
private:
	std::string _plantName;
	std::string _size;
	int _amountHarvest;

public:
	Plant(const std::string& plantName, const std::string& size, int amountHarvest)
		: _plantName(plantName), _size(size), _amountHarvest(amountHarvest) {}

	virtual ~Plant() {}

	std::string GetPlantName()
	{
		return _plantName;
	}

	std::string GetSizeOfPlant()
	{
		return _size;
	}

	int& GetAmountOfHarvest()
	{
		return _amountHarvest;
	}



	virtual void PrintPlant() = 0;

	virtual Harvest* GetHarvest() = 0;

};


class AppleTree : public Plant
{
private:
	std::string _name;

public:
	AppleTree(std::string plantName, std::string size, int amountHarvest, std::string name)
		: Plant(plantName, size, amountHarvest), _name(name) {}

	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return new Apple("яблоко", 0.12, "красный", "антоновка");
		return nullptr;
	}
};



class PeachTree : public Plant
{
private:
	std::string _name;

public:
	PeachTree(std::string plantName, std::string size, int amountHarvest, std::string name)
		: Plant(plantName, size, amountHarvest), _name(name) {}

	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return new Apple("персик", 0.15, "красный", "принц");
		return nullptr;
	}

};

class SpruceTree : public Plant
{
private:
	std::string _name;

public:
	SpruceTree(std::string plantName, std::string size, int amountHarvest, std::string name)
		: Plant(plantName, size, amountHarvest), _name(name) {}

	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return new Apple("шишка", 0.05, "коричневый", "еловая");
		return nullptr;
	}

};


#endif 

