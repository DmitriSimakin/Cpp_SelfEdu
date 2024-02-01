#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

/*
---- Операторы new [] и delete [] ----

new [] - для выделения памяти под указанное число объектов.
delete [] - для освобождения памяти массива объектов.

*/

struct point   // public private
{
private:
   int x, y;

public:
   point()  // конструктор
   {
      x = 0;
      y = 0;
      cout << "Call of object's constructor!" << endl;
   }

   point(int x, int y)
   {
      this->x = x;
      this->y = y;
      cout << "Call of object's constructor!" << endl;
   }

   ~point() { cout << "Call of object's destructor!" << endl; }

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

// malloc(), calloc(), realloc() и free() - использовали ранее.
int main()
{
// 3 раза вызывает конструктор для каждого объекта.
   point* pt = new point[3]; 

   for(int i=0; i < 3; ++i)
      cout << pt[i].get_x() << " " << pt[i].get_y() << endl;

// вызывает 3 раза деструктор (по одному на каждый объект)
// delete pt;  - вызовет только 1 деструктор для 1 объекта.
   delete [] pt;

// Работа с базовыми типами данных. (создание массива)
   double* v3 = new double[3];
   
   for(int i=0; i < 3; ++i)
      cout << v3[i] << endl;
   delete [] v3;
   return 0;
}