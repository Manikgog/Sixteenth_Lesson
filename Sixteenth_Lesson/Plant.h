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
		std::cout << "��� ��������: " << GetPlantName() << "\n������: " << GetSizeOfPlant() << "\n���������� ������: " << GetAmountOfHarvest() << std::endl;
		std::cout << "�������� ��������: " << _name << std::endl;
	}

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return new Apple("������", 0.12, "�������", "���������");
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
		std::cout << "��� ��������: " << GetPlantName() << "\n������: " << GetSizeOfPlant() << "\n���������� ������: " << GetAmountOfHarvest() << std::endl;
		std::cout << "�������� ��������: " << _name << std::endl;
	}

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return new Apple("������", 0.15, "�������", "�����");
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
		std::cout << "��� ��������: " << GetPlantName() << "\n������: " << GetSizeOfPlant() << "\n���������� ������: " << GetAmountOfHarvest() << std::endl;
		std::cout << "�������� ��������: " << _name << std::endl;
	}

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if (amount > 0)
			return new Apple("�����", 0.05, "����������", "������");
		return nullptr;
	}

};


#endif 

