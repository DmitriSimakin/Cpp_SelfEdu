#include <iostream>

namespace firstSpace
{
	struct point
	{
		double x, y;
	};
}
// эл-ты из пр-в имён можно сразу импортировать 
// в программу (в эту область видимости):

// using <пр-во имён>::<элемент>;
using std::cout;
using std::cin;
using std::endl;

// импортируем всё пр-во имён std в модуль. (Плохая практика)
// using namespace std;

// Также можно переименовывать типы данных:
// using <alias> = <тип данных>;
using byte_8 = unsigned char;
using point2D = firstSpace::point;

// Аналогичен с typedef, разница видна лишь при
// применении с шаблонами или определении указателя
// на функцию:

// указатель на ф-ю, возвр. float и приним. 1пар.-int.
typedef float (*func_ptr)(int);
using func_ptr = float (*)(int);

int main()
{
	byte_8 ch;
	byte_8* ptr_ch, * a;
	point2D pt = {};

	int global_a = 10;
	//std::cout << "Hello World!" << std::endl;
	cout << "Hello World!" << endl;
	return 0;
}