// Новые типы данных:
/*
1. bool - булевый тип, приним. два сост. true/false
2. wchar_t - расширенный символьный тип (2байта в ОС Виндовс, 4 байта в Линух)
3. char8_t -  символьный тип (1байт) для символов кодировки Unicode (UTF-8)
4. char16_t - символьный тип (2байт) для символов кодировки Unicode (UTF-16)
5. char32_t - символьный тип (4байт) для символов кодировки Unicode (UTF-32)
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	bool flag = false;
	// flag = true;

	// if(flag)
	// 	cout << "flag" << endl;
	// cout << flag << endl;

	// wchar_t wch;
	// wch = L'Я'; // кладём букву Я

	// char ch = 'q';
	// char str_en[] = "Hi world!";
	// char str[] = "Привет мир!";
	// // ch = str[0];
	// cout << ch << endl;
	// cout << str << endl;
	// cout << str_en << endl;

// ---------------------------------
// wchar_t - применяется когда задействованы русские буквы.
	wchar_t wch = L'я';
	wchar_t str_en[] = L"Hi world!";
	wchar_t str[] = L"Привет мир!";
	//  // ch = str[0];
	// cout << wch << endl;
	// cout << str << endl;
	// cout << str_en << endl;

// В С++ нельзя приравнивать указателя разных типов
// только через явное преобразование.
	int* ptr_i = NULL;
	char* ptr_ch = nullptr; // С++11 с этого правильно
	void* ptr = 0L; // либо так.

	// ptr_ch = ptr_i; // нельзя
	ptr_ch = (char*)ptr_i;

	// аналогично явное преобразование.
	ptr_i = (int*)ptr;
	ptr_i = (int*)malloc(sizeof(int)*5);

	ptr_ch = nullptr;
	//cout << ptr_ch << endl; // ничего
	printf("%p\n", ptr_ch); // нули.

	// Новый цикл for:
	char msg[30] = "I like C++ language";
	for(char x : msg)
		cout << x << " ";
	// Применяется для многих видов коллекций, на каждой итерации в x копируется символ.

	return 0;
}