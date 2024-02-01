#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

// отличия от Си:
/*
1. Имя point в C++ является полноценным типом,
а не просто тегом структуры, как в Си -
(обязательно при объявлении объекта структуры
нужно было писать struct <tag = имя>)

2. В структурах теперь можно объявлять функции (методы).
*/
struct point 
{
   int x, y;
// запись this->x и просто x эквивалентны
   double length() { return sqrt(this->x*x + y*y); }
   int get_x() { return x; }
   int get_y() { return y; }
   double length_2() { return sqrt(get_x()*get_x() + get_y()*get_y()); }
};


int main()
{
// 1.
   // struct point pt; // Как в Си
   // point pt {};
   // cout << pt.x << " " << pt.y << endl;
   
   // point pt_2 {1};
   // cout << pt_2.x << " " << pt_2.y << endl;

   // point pt_3 {1, 2};
   // cout << pt_3.x << " " << pt_3.y << endl;

// 2. 
   point pt {1, 2};
   point pt_2 {3, 4};

   cout << pt.length() << endl;
   cout << pt_2.length() << endl;

   // как метод length понимает, какие x и y использовать?
   // здесь имеем дело с указателем this->.
/*
каждому методу автоматически и неявно передается спец. указатель this->.
Это неявный указатель на объект. Когда мы вызываем: pt.length(), то this 
ссылается на объект pt.
Указатель this имеет тот же самый тип, что и объект, но со *
Указатель this можно использовать везде в структуре, кроме статических методов.

*/


   return 0;
}