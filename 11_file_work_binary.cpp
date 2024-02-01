/*
Бинарный режим позволяет сохранить данные в файл
в том же, что и в ячейках памяти, поэтому мы можем читать
и также записывать в файл, мы можем сохранять и загружать
сложные структуры данных
*/

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::ios;

struct person 
{
	char fio[100];
	short old;
	unsigned int salary;
	double weight;
};


int main()
{
	// double pow[] {4.3, -5.4, 0.01, 7.88};

	// std::ofstream ofs {"out_course.dat", ios::out | ios::binary};

	// if(ofs.is_open())
	// {
	// 	// ofs << pow; // записывает адрес на 1 эл-т массива.
	// 	// ofs.write(1arg, 2arg)  - перенесит побайтно, 1arg - начало считывания данных, 2arg - сколько байт.
	// 	ofs.write((char*)pow, sizeof(pow));
	// }
	// ofs.close();

	// // ----- чтение данных из файла -------
	// double read_pow[10] {0};
	// std::ifstream ifs {"out_course.dat", ios::in | ios::binary};

	// if(ifs.is_open())
	// {
	// 	// ifs.read(1arg, 2arg)  - также похож на функцию read из Cи
	// 	// 1arg - куда писать данные, 2arg - сколько штук.
	// 	ifs.read((char*)read_pow, sizeof(pow));
	// }
	// ifs.close();

	// for(double x : read_pow)
	// 	cout << x << " ";

	
	struct person ps[] {{"Sergey Balakirev", 102, 100001, 82.6},
					 {"Bjarne Stroustrup", 56, 10002, 78.2},
					 {"Dennis Ritchie", 62, 50501, 88.9},
					 {"Kenneth Thompson", 58, 103414, 75.3}
					};
		
	std::ofstream ofs {"out_course.dat", ios::out | ios::binary};

	if(ofs.is_open())
	{
		for(auto& p: ps)
			ofs.write((char*)&p, sizeof(p));
	}
	ofs.close();

// ----- чтение данных из файла -------
	struct person ps_r[10];
	int count {0};

	std::ifstream ifs {"out_course.dat", ios::in | ios::binary};

	if(ifs.is_open())
	{
		while(ifs.read((char*)&ps_r[count], sizeof(person)))
			count++;
	}
	ifs.close();

	for(int i{0}; i < count; ++i)
	{
		cout << ps_r[i].fio << '\n';
		cout << ps_r[i].old << " " << ps_r[i].salary << " " << ps_r[i].weight << endl;
	}

	return 0;
}