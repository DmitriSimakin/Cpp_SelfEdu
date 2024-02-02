#include <iostream>


/*
Все объявления вне функций попадают в Глобальное пространство имён.
*/

// создаём своё пр-во имён:
namespace firstSpace
{
	void foo()
	{
		std::cout << "function from firstSpace: foo()" << std::endl;
	}
}

// М.б. переопределение в глоб. пр-ве имён, поэтому и создали концепт пр-в имён.
namespace secondSpace
{
	void foo()
	{
		std::cout << "function from secondSpace: foo()" << std::endl;
	}
}

// Можно добавлять в пр-во, разрывая его наполнение (в разных местах программы добавлять в него эл-ты)
namespace firstSpace
{
	struct point
	{
		double x, y;
	};

	// Вложенные пр-ва имён: обращаться к его наполнению через OuterNameSpace::InnerNameSpace::int_a
	namespace params
	{
		int global_a = 5;
	}

	// Если перед внутр. namespace написать inline, то можно обращаться только через внешний:
	// std::cout << firstSpace::global_a;
}



int main()
{
	int global_a = 10; // локальная переменная.
	//point pt {};
	//foo();

	std::cout << global_a << std::endl; // сначала смотрит локальную, потом по глобальному пр-ву имён.

	// можно обратиться через четвероточие к глобальной области видимости:
	firstSpace::point pt {};
	//::foo();

	std::cout << global_a << " " << firstSpace::params::global_a << std::endl;

	firstSpace::foo();
	secondSpace::foo();
	return 0;
}