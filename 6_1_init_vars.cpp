/*
Рекомендуемая практика: инициализировать сразу 
переменную (не оставлять без значения), т.к. она
может принимать неопр. значение(любое).
*/


#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// операции инициализации:
	int val = 0;
	int pow[] = {1, 2, 4, 8};

	double d;
	// операции присваивания:
	d = 5.78;

// в С++ ввели свои обозначения, чтобы разграничить
// эти операции (и там и там было = )

// операция инициализации:
	double dd(5.78);
	short sh(10); // functional notation

	char ch{'b'};  // braced initialization
	long lv{}; // пустые скобки означают ноль (всегда).


	cout << sh << " " << d << endl;
	cout << ch << " " << lv << endl;

// в чём разница? 
// при иниц. с пом. {}  - происходит проверка типа данных
long long_var_a{5.43}; // ошибка.

// при иниц. с пом. () - происходит приведение типов.
long long_var_b(5.43); // отбрасывает дробную часть.
cout << long_var_b << endl;


// Модификатор const:
// константная переменная д.б. сразу инициализирована.
	const double pi {3.1415}; 

	return 0;
}