#include <iostream>
#include <string>
#include <Windows.h>
#include "Harvest.h"
#include "Plant.h"
#include "InterfaceClass.h"
#include <typeinfo>
#include <type_traits>

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

//---------------------восемнадцатый урок-----------------------------------

class IPrintable
{
public:
	virtual void Print(std::string tmp) const = 0;
	//IPrintable() = delete;
	//~IPrintable() = delete;
};


class A : virtual public IPrintable
{
public:

	virtual ~A() {}
	void Print(std::string tmp) const override
	{
		std::cout << tmp << "\n";
	}
};

class B : public A
{
public:
	~B() override
	{
	}
};

void Bar(const IPrintable& obj)
{
	std::string tmp = typeid(obj).name(); std::cout << std::endl;
	obj.Print(tmp);
}

//-----------------------------MAIN-----------------------------------------

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

	/*AppleTree appleTree("дерево", "средний", 2, "яблоко");
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
	}*/
	// 18 урок

	A* p_A = new B;
	A* p2_A = nullptr;
	A* p3_A = new A;

	A& ref_A = *p_A;
	A& ref2_A = *p3_A;
	//A& ref3_A = *p2_A;	//разыменование пустого указателя

	std::string tmp = typeid(*p_A).name();
	//tmp = typeid(*p2_A).name();
	tmp = typeid(*p3_A).name();

	tmp = typeid(ref_A).name();
	tmp = typeid(ref2_A).name();


	int a = int();
	std::cout << a;

	Bar(*p_A);
	//Bar(*p2_A);
	Bar(*p3_A);
	Bar(ref_A);
	Bar(ref2_A);
	delete p_A;
	delete p3_A;

	return 0;
}

