#include <iostream>
#include <string>
#include <Windows.h>


class Base 
{
public:
	int publicMember;
	Base() {
		std::cout << this << " " << "Base object created\n";
	}
	~Base()
	{
		std::cout << this << " " << "Base object destroyed\n";
	}
protected:
	int protectedMember;

private:
	int privateMember;

};

class Derived : public Base
{
	void bar()
	{
		this->protectedMember;
		this->publicMember;
	}
public:
	// publicMember остаётся публичным
	// protectedMember становится защищённым
	// privateMember недоступен

private:

};

class Base2
{
public:
	int publicMember;
	Base2() {
		std::cout << this << " " << "Base object created\n";
	}
	~Base2()
	{
		std::cout << this << " " << "Base object destroyed\n";
	}
protected:
	int protectedMember;

private:
	int privateMember;

};

class Base3
{
public:
	int publicMember;
	Base3() {
		std::cout << this << " " << "Base object created\n";
	}
	~Base3()
	{
		std::cout << this << " " << "Base object destroyed\n";
	}
protected:
	int protectedMember;

private:
	int privateMember;

};

class Derived2 : protected Base2
{
	// publicMember и protectedMember становятся защищёнными
	// privateMember недоступен
	int GetProtMember()
	{
		return protectedMember;
	}
};

class Derived3 : Base3
{
	// publicMember и protectedMember становятся защищёнными
	// privateMember недоступен
};

class Harvest
{
private:
	std::string _harvestName;
	float _weight;
	std::string _color;

public:
	Harvest(std::string harvestName, float weight, std::string color)
		: _harvestName(harvestName), _weight(weight), _color(color) {}

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

class Plant
{
private:
	std::string _plantName;
	std::string _size;
	int _amountHarvest;

public:
	Plant(std::string plantName, std::string size, int amountHarvest)
		: _plantName(plantName), _size(size), _amountHarvest(amountHarvest) {}

	std::string GetPlantName()
	{
		return _plantName;
	}

	std::string GetSizeOfPlant()
	{
		return _size;
	}

	int GetAmountOfHarvest()
	{
		return _amountHarvest;
	}

	virtual void PrintPlant() = 0;


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
		std::cout << "Сорт яблок: " << _sortOfApple << std::endl;
	}

};

class AppleTree : public Plant
{
private:
	std::string _name;

public:
	AppleTree(std::string plantName, std::string size, int amountHarvest, std::string name)
		: Plant(plantName, size, amountHarvest),  _name(name) {}

	void PrintPlant()
	{
		std::cout << "Вид растения: " << GetPlantName() << "\nРазмер: " << GetSizeOfPlant() << "\nКоличество плодов: " << GetAmountOfHarvest() << std::endl;
		std::cout << "Название растения: " << _name << std::endl;
	}

};


int main()
{
	system("chcp 1251");
	/*Base obj;
	obj.publicMember;
	Derived objDer;
	objDer.publicMember;
	Derived2 objDer2;
	Derived3 objDer3;*/


	return 0;
}

