#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void swap_p_d(double* x, double* y)
{
	double t = *x;
	*x = *y;
	*y = t;
}

void swap_lnk_d(double& x, double& y)
{
	double t = x;
	x = y;
	y = t;
}

struct point 
{
	char name[50];  // name of point
	double x, y;    // point coords
};

double length(const point& p)
{
	return sqrt(p.x*p.x + p.y*p.y);
}


int main()
{
	// int d{10};
	// int& lnk_d = d;

	// lnk_d = -5;
	// cout << lnk_d << endl;
	// lnk_d *= 10;
	// cout << lnk_d << endl;
	// lnk_d++;
	// cout << lnk_d << endl;

// при объявлении ссылки её сразу же нужно проинициализировать.
	// double& alias_d;  // ошибка.

	// double& alias_d {lvalue};
// lvalue - значения, связанные с конкр. ячейками памяти.

	// int a {10};
	// int* ptr = &a;
	// int ar[] = {1, 2, 3};

	// int& lnk_1 = a;     // ok
	// int& lnk_2 = *ptr;  // ok
	// int& lnk_3 = ar[1]; // ok
	// int& lnk_4 = 10;    // error (не ссылается на конкретную область памяти)
	// int& lnk_5 = ptr;   // error (справа д.б. lvalue значение)


// Польза ссылок:

	double a{1.2}, b{-3.4};
// Работа с указателями:
	swap_p_d(&a, &b);
	// cout << a << " " << b << endl;

// Работа с ссылками:
	swap_lnk_d(a, b);
	// cout << a << " " << b << endl;

	// нельзя: (д.б. lvalue значение)
	// swap_lnk_d(a, 10); // а с указателями бы ошибка была только в программе.
	// ссылки более безопасны.

	short p[] = {1, 2, 3, 4};

// ничего не поменялось.
	// for (short x: p)
	// 	x *= 2;

	// for(short x: p)
	// 	cout << x << " ";
	// cout << endl;
// меняем значения:
	// for (short& x: p)
	// 	x *= 2;

	// for(short x: p)
	// 	cout << x << " ";

// константные ссылки.
// если объявляем const ссылку, то через неё нельзя менять значение, только читать.
	// int s = 0;
	// const int& ls = s;

	// int x = ls;
	// cout << x << endl;

	// // ls = -2; // нельзя
	// s = 2; // можно
	// cout << ls << endl;

// для const int можно создать только const int& тип.
	// const int con_var = 10;
	// // int& lnk_var = con_var;    // низя
	// const int& lnk_var = con_var; // можно


// Применение ссылок:
	point p2 {"first", 10.0, 20.0};
	double len = length(p2);

	cout << len << endl;


	return 0;
}