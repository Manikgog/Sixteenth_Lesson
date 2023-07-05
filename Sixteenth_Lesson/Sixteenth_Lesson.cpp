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
	virtual ~Base()
	{
		std::cout << this << " " << "Base object destroyed\n";
	}
	virtual int Bar(int a, bool b) = 0; // чистая виртуальная функция не имеет реализации
										// превращает класс в абстрактный
										// все наследники которые не имеют своей реализации
										// тоже становятся абстрактными классами
										// абстрактный класс - содержит одну и более чистых 
										// виртуальных функций и не может 
										// иметь собственных объектов
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
	int Bar(int a, bool b) override
	{
		return a | b;
	}
	~Derived() override
	{
		std::cout << this << " " << "Derived object destroyed\n";
	}

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

	Harvest* GetHarvest() override
	{
		int amount = GetAmountOfHarvest()--;
		if(amount > 0)
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


int main()
{
	system("chcp 1251");
	system("cls");
	/*Base obj;
	obj.publicMember;
	Derived objDer;
	objDer.publicMember;
	Derived2 objDer2;
	Derived3 objDer3;*/

	/*Base* obj;
	obj = new Derived;*/

	AppleTree appleTree("дерево", "средний", 2, "яблоко");
	PeachTree peachTree("дерево", "средний", 3, "персик");
	SpruceTree firTree("дерево", "большой", 4, "шишка");

	Harvest* h = appleTree.GetHarvest();
	while (h != nullptr)
	{
		h->PrintHarvest(); std::cout << std::endl;
		delete h;
		h = appleTree.GetHarvest();
	}
	Harvest* h1 = peachTree.GetHarvest();
	while (h1 != nullptr)
	{
		h1->PrintHarvest(); std::cout << std::endl;
		delete h1;
		h1 = peachTree.GetHarvest();
	}
	Harvest* h2 = firTree.GetHarvest();
	while (h2 != nullptr)
	{
		h2->PrintHarvest(); std::cout << std::endl;
		delete h2;
		h2 = firTree.GetHarvest();
	}
	
	return 0;
}

