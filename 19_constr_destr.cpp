#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

/*
----- Конструкторы ------

1. Имя конструктора всегда должно совпадать с именем типа данных, в нашем случае с именем структуры point.
2. Конструктор никогда не возвращает никаких значений, поэтому возвращаемый тип не прописывается вовсе.
3. Конструктор может иметь произвольное число параметров.
4. Конструктор всегда вызывается при создании каждого нового объекта 

----- Деструкторы ------

1. Имя методы называется также, как и тип данных с тильдой (~) в начале.
2. Деструктор ничего не возвращает.
3. Деструктор не имеет параметров.
*/

/* Деструкторы служат для освобождения ресурсов, захваченных текущеим объектом! (free (coords)); */

struct point   // public private
{
private:
   int x, y;
   short* coords;

public:

// Когда в программе есть несколько конструкторов - это перегрузка конструкторов, компилятор выбирает нужный
// в зависимости от переданных аргументов.

   point()  // конструктор
   {
      x = 0;
      y = 0;
      coords = (short*)malloc(2 * sizeof(short));
   }

   point(int x, int y)
   {
      this->x = x;
      this->y = y;
      coords = (short*)malloc(2 * sizeof(short));
   }

   // // Можно и записать это в одном конструкторе:
   // point(int x=0, int y=0)
   // {
   //    this->x = x;
   //    this->y = y;
   // }

   ~point()
   {
      cout << "Call of object's destructor!" << endl;
      free(coords);
   }


   double length() { return sqrt(x*x + y*y); }
   void sum(const point& pt)
   {
      this->x = pt.x;
      this->y = pt.y;
   }

   void set_x(int x) { this->x = x; }
   void set_y(int y) { this->y = y; } 
   int get_x() { return this->x; } // или просто return x;
   int get_y() { return this->y; }

   void set_coords(int x, int y)
   {
      if(x < -100 || x > 100 || y < -100 || y > 100)
         return;
   // тута this->x - обращение к полю структуры, в которой находится метод, а просто x - входной параметр.
      this->x = x;
      this->y = y;
   }

   void get_coords(int& x, int& y)
   {
      x = this->x;
      y = this->y;
   }
};

int main()
{
   point pt {1, 4};
   //pt.set_coords(1, 2);
   cout << pt.get_x() << " " << pt.get_y() << endl;

   // Вариант создания объекта:
   double res = point(10, 20).length();
   cout << res << endl;

   return 0;
}