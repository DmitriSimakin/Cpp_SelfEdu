/*
cin - объект класса istream для работы с потоком stdin

cout - объект класса ostream для работы с потоком stdout
*/

#include <iostream>

int main()
{

	char str[100] ; //= "Hi, Dmitri!";
	short old ; //= 99;
	double weight ; //= 82.54;
/*
	std::cout << str << "\n";
	std::cout << old << "\n";
	std::cout << weight << std::endl;
*/

// Важно: объект std::cin читает ввод ДО первого пробельного символа;
// если нужно прочитать строку, то используем функцию: getline(cin, str)
// но 2 аргумент д.б. класса std::str.

// если тип не соответствует заявленному, то выводится 0 для int и double
// и какая-то хрень для char[].
	std::cin >> str;
	std::cin >> old;
	std::cin >> weight;

// Т.к. cin и cout возвращают себя же, то можно писать в одну строку несколько
// вызовов.
// std::cin >> old >> str >> weight;
	std::cout << str << "\n" << old << '\n' << weight << std::endl;

	return 0;
}