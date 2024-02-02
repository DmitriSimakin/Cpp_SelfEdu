#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
   // char msg[] = "Hello, World!";
   std::string msg  {"Hello, Victori Simakina!"};  // объект класса string.

   cout << msg.size() << " " << msg.capacity() << endl;
   cout << msg << endl;
   // obj.capacity() - возвращает размер динамического массива
   // obj.size() - возвращает фактическое кол-во символов в строке

   const char* data = msg.data();
   // obj.data() - возвращает одномерный массив символов.

   printf("%s\n", data);  // аналогично.

   std::string fio {"Dmitri Simakin"};
   std::string fio_new {fio}; // происходит копирование данных, а НЕ указание на одну ячейку памяти.

   fio_new[5] = 'y';  // можно перебирать эл-ты через оператор []

   cout << fio << endl;
   cout << fio_new << endl;

   for(const char& ch: fio)
      cout << ch << " ";
   cout << endl;

// Также можно перебрать через итератор.
   for(auto it = msg.cbegin(); it != msg.cend(); ++it)
      cout << *it << " ";
   cout << endl;

const char* ptr_str = fio.data();
   for(int i=0; ptr_str[i] != '\0'; ++i)
		cout << ptr_str[i] << " ";
	cout << endl;

	std::string msg {"Hello"};
	std::string name {"Maria!"};
	msg.append(", ");
	// msg += name;
	std::string msg2 = msg + name;
	cout << msg << endl;
	cout << msg2 << endl;

	std::string msg;
	// cin >> msg; // но так читает до пробельного символа!
	getline(cin, msg, ';'); // 3-ий аргумент: символ, до которого читать.
	cout << msg << endl;

   return 0;
}