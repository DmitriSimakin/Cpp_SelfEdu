/*
В стандарте C++11 появились лямбда-функции
(их также называют анонимные функции):

[]([параметры]){<операторы тела функции>}
*/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// // r не ссылается на лямбда-функцию, а само является этой функцией (объектом функции).
	// auto r = [] (int a)
	// {
	// 	cout << "Lambda-function: " << a << endl;
	// };
	// // () - оператор вызова функции, (10) - с аргументом 10.

	// // s и r  - разные объекты (2 разных лямбда-выражения)
	// auto s = r; // auto s {r}; // одно и тоже
	// r(10);
	// s(10);


	// auto s { [] (const char* msg, double& x)
	// {
	// 	cout << msg << endl;
	// 	x++;
	// } };

	// // А можно с return:
	// auto s { [] (const char* msg, double x)
	// {
	// 	cout << msg << endl;
	// 	return ++x;
	// } };

	// double b = 0;
	// r(10);
	// b = s("increment", b);
	// cout << b << endl;

	// auto sum2 { [] (int a, int b) {return a+b;} };
	// cout << sum2(2, 3) << endl;

// // также можно указывать явно желаемый возвращаемый тип: -> type
// 	auto sum2 { [] (int a, int b) -> double {return a+b;} };
// 	cout << sum2(2, 3) << endl;

// // Со стандарта C++14 в лямбда-выражениях можно использовать auto в параметрах:
// 	auto sum2 { [] (auto a, auto b) -> double {return a+b;} };
// 	double res_1 = sum2(2, 3);
// 	double res_2 = sum2(2.4, 3.5);
// 	cout << res_1 << " " << res_2 << endl;

// Также можно в возвращаемом типе использовать вычисляемый тип:
// возвращаемое значение будет вычисляться на основе типа данных в return.
	auto sum2 { [] (auto a, auto b) -> auto {return a+b;} };
	double res_1 = sum2(2, 3);
	double res_2 = sum2(2.4, 3.5);
	cout << res_1 << " " << res_2 << endl;

// Дальше - больше: мы можем и строки складывать:
	std::string res_3 = sum2(std::string("Hello "), std::string("World!"));
	cout << res_3 << endl;

	
	return 0;
}