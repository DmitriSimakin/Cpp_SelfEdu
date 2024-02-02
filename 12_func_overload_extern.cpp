#include <iostream>

using std::cout;
using std::endl;
// [-10; 10]

// int module_int(int x)
// {
// 	cout << "module_int(int)" << endl;
// 	if(x >= -10 && x <= 10)
// 		return (x > 0) ? x : -x;
// 	return x;
// }

// double module_double(double x)
// {
// 	cout << "module_double(double)" << endl;
// 	if(x >= -10 && x <= 10)
// 		return (x > 0) ? x : -x;
// 	return x;
// }

// Работать с int как с double неудобно - медленнно и потр. больше памяти.
// labs(), fabs(), ...

/*
Однако C++ позволяет объявлять функции с одним именем, но разными типама 
входных параметров. (перегрузка имени функции - перегрузка функции)
*/

int module(int x) // _Z6modulei
{
	cout << "module_int(int)" << endl;
	if(x >= -10 && x <= 10)
		return (x > 0) ? x : -x;
	return x;
}

double module(double x) // _Z6moduled
{
	cout << "module_double(double)" << endl;
	if(x >= -10 && x <= 10)
		return (x > 0) ? x : -x;
	return x;
}

/*
Раньше в Си было достаточно только имени функции, чтобы компилятор мог её найти и подставить,
теперь необходимо ещё указать параметры, разные компиляторы под капотом 
могут по-разному кодировать перегруженные функции (даже не перегруженные),
g++ даёт разные имена _Z6module(буква).
*/

int main()
{
// Можно даже передавать входные данные меньших типов, они будут приводиться
// к большим: short -> int, float -> double, ...
// однако большие к меньшим приводиться не будут: нельзя long -> int.

	double res_1 = module(-0.5f);             // modul(double)
	//int res_2 = module((long double)-0.5);  //нельзя, modul(double)
	//double res_3 = module((long)-10);       //нельзя, modul(int)
	int res_4 = module((short)-10);           // modul(int)

// ---- extern "C" -------
/*
Нужна если код пишется и для С, и для С++  программ.
Нужна для того, чтобы программа могла компиллироваться и C-компилятором, и
С++-компилятором, при указании extern "C" имя функции кодируется по-стартому,
а также, чтобы этот объектный файл мог собираться С и С++ компоновщиками.
*/

	return 0;
}

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
void show_msg(const char* msg)
{
	puts("-----------------");
	puts(msg);
	puts("-----------------");
}

#ifdef __cplusplus
}
#endif // __cplusplus

/*
директивы условной компиляции нужны для того,
чтобы extern "C" был только для С++, поскольку
в С такой конструкции нет.
*/