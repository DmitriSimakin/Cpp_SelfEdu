#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;


int main()
{
	using std::ios;
	std::string str;

	std::ofstream ofs {"out_course.dat", ios::out};

	if(ofs.is_open())
	{
// для объекта ofs переопределена операция: <<
		ofs << 10 << " " << -5.34 << " " << -34 << endl;
		ofs << '\n' << '\n' << "I'm Dmitri Simakin!" << endl;
	}
	ofs.close();

	// -------- чтение данных из файла -------------

	int data_i1 {}, data_i2 {};
	double data_d1 {};

	std::ifstream ifs("out_course.dat");
	if(ifs.is_open())
	{
		ifs >> data_i1 >> data_d1 >> data_i2; // типы данных д.б. обязательно одинаковыми!
		// ifs >> str;  // читает до пробела
		// getline(ifs, str); // читает до '\n'
// поскольку после крайнего прочитанного числа стоит перевод строки,
// то обычный getline() его читает и всё, след. строка не прочитана.
// while помогает это избежать.
		while(str.length() == 0 && !ifs.eof())
			getline(ifs, str);
	}

	cout << data_i1 << " " << data_i2 << " " << data_d1 << endl;
	cout << str << endl;
	ifs.close();
	return 0;
}