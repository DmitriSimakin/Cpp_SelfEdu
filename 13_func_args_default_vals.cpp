#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void show_data(const char* sep, int a=1, const char* str = "Hi!", double b=-5.43)
{
	cout << a << "\n" << str << "\n" << b << endl;
}

/*
Типы передаваемых данных должны соответствовать указанным в определении функции.

Если нужно изменить только 2 указанный параметр по умолчанию, то придётся указать 
значение и 1параметра.

Параметры функции по умолчанию должны следовать после обычных параметров.
*/

double round_math(double x, int radix=0)
{
	double p = pow(10, radix);
	return round(x * p) / p;
}

int main()
{
	// show_data(",");
	// cout << "----------------" << endl;
	// show_data("5", 7);
	// cout << "----------------" << endl;
	// show_data(".", 10, "Hello", 3.1415);
	// cout << "----------------" << endl;

	double res_1 = round_math(4.5634);  // 5
	double res_2 = round_math(4.5634, 1);  // 4.6
	double res_3 = round_math(4.5634, 3);  // 4.563
	cout << res_1 << "\n" << res_2 << "\n" << res_3 << endl;
	return 0;
}