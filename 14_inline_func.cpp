#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// inline func = подставляемая функция.

int sum2(int a, int b)
{
	return a + b;
}

inline bool sqr_root(double a, double b, double c, double& x1, double& x2)
{
	double D = b*b - 4*a*c;
	if(D < 0)
		return false;
	
	x1 = (-b + sqrt(D)) / (2*a);
	x2 = (-b - sqrt(D)) / (2*a);
	return true;
}

/*
Для чего они нужны: чтобы ускорить программу, не создавать
стековый фрейм вызовов функций, не тратить время на передачу 
аргументов и тд, inline функция сразу же подставляется, как часть кода.

Итог: нынешние компиляторы сами часто преобразуют функции
в inline, но мы, если видим, что функция небольшая (небольшое
кол-во операторов в теле), можем помочь компилятору и указать
на это преобразование.
*/

int main()
{
	int x = 1, y = -5;
	int res = sum2(x, y);

	double x1 {}, x2 {};
	bool res_root = sqr_root(3, 10, 5, x1, x2);

	if(res_root)
		cout << x1 << " " << x2 << endl;

	return 0;
}