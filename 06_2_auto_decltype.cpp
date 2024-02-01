#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;

int main()
{
// c С++11 ключевое слово "auto" поменяло свое значение.
// теперь с его помощью можно вычислять переменные перечисляемого типа.

// вместо auto компилятор подставляет тип,
// который вычисляется справа.
	// auto i = -100;    // тип int
	// auto d = 76.98;  // тип double
	// auto g = 0.55f;  // тип float
	// auto h = 'f';    // тип char
	// auto l = 5000L;  // тип long

	// auto d_var = 1 + i + 10.0; // double


// для константных типов и указателей сложнее.
	// int* ptr = nullptr;
	// int k; 
	// int& lk = k;

	// auto t1 = k;     // int
	// auto t2 = *ptr;  // int
	// auto t3 = ptr;   // int*
	// auto t4 = &ptr;  // int**
	// auto t5 = lk;    // int

// с модификатором const:
	// const int* co_ptr = nullptr;
	// const int co_k{0}; 
	// const int& co_lk = co_k;

	// auto co_t1 = co_k;     // int
	// auto co_t2 = *co_ptr;  // int
	// auto co_t3 = co_ptr;   // const int*
	// auto co_t4 = &co_ptr;  // const int**
	// auto co_t5 = lk;       // int

// если для нас важно оставить полностью идентичный тип.

	// decltype(co_k) var1 = 1;
	// decltype(co_ptr) var2;     // const int*
	// decltype(co_lk) var3 = k;  // const int &

// Применение:
	std::list<short> dg = {-3, -2, 0, 2, 3};

	for(std::list<short>::iterator i = dg.begin(); i != dg.end(); ++i)
		std::cout << *i << " ";

// упрощает.
	for(auto i = dg.begin(); i != dg.end(); ++i)
		std::cout << *i << " ";

	return 0;
}