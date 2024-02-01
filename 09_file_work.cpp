/* Классы для файловых потоков.
1. ifstream - для чтения данных из файла
2. ofstream - для записи данных в файл
3. fstream - для записи и чтения данных из файла

То же, но для wchar_t:
1. wifstream - для чтения данных из файла
2. wofstream - для записи данных в файл
3. wfstream - для записи и чтения данных из файла
*/

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;


int main()
{
// создаём 2 объекта потоков.
	// std::ofstream ofs;
	// std::ifstream ifs;
	
	// // связываем эти потоки с файлами.
	// ofs.open("ofs.dat");
	// ifs.open("ifs.dat");

	// ofs.close();
	// ifs.close();

	// // а можно открывать файлы сразу при объявлении объектов:
	// std::ofstream ofs {"ofs.dat"};
	// std::ifstream ifs {"ifs.dat"};

	// cout << (ofs.is_open() ? "Файл ofs.dat открыт" : "Ошибка открытия файла ofs.dat") << endl;
	// cout << (ifs.is_open() ? "Файл ifs.dat открыт" : "Ошибка открытия файла ifs.dat") << endl;

	// ofs.close();
	// ifs.close();

/*
1. ios::in  - для чтения(только для объектов классов ifstream или fstream) (не создаёт файл, если его нет)
2. ios::out  - для записи; прежние данные удаляются (только для объектов классов ofstream или fstream)
3. ios::app  - для дозаписи; прежние данные не удаляются (создаёт, если файла нет)
4. ios::ate  - при открытии указатель файла смещается в конец
5. ios::binary  - открытие файла в бинарном режиме доступа.
*/

	using std::ios;

	std::ofstream ofs {"ofs.dat", ios::out};
	std::ifstream ifs {"ifs.dat", ios::app | ios::binary};

	cout << (ofs.is_open() ? "Файл ofs.dat открыт" : "Ошибка открытия файла ofs.dat") << endl;
	cout << (ifs.is_open() ? "Файл ifs.dat открыт" : "Ошибка открытия файла ifs.dat") << endl;
	ofs.close();
	ifs.close();

	
	return 0;
}