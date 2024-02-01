#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

/*
Режим доступа private запрещает доступ к полям напрямую из вне структуры, но внутри методов это можно.
Режим доступа public это разрешает.

По умолчанию в структуре задаётся режим доступа PUBLIC
*/


struct point   // public private
{
private:
   int x, y;

public:
   double length() { return sqrt(x*x + y*y); }
   void sum(const point& pt)
   {
      this->x = pt.x;
      // this->y = pt.y;
   }

// сеттеры
   void set_x(int x) { this->x = x; }
   void set_y(int y) { this->y = y; }
// геттеры   
   int get_x() { return this->x; } // или просто return x;
   int get_y() { return this->y; }

// сеттер
   void set_coords(int x, int y)
   {
      if(x < -100 || x > 100 || y < -100 || y > 100)
         return;
// тута this->x - обращение к полю структуры, в которой находится метод, а просто x - входной параметр.
      this->x = x;
      this->y = y;
   }

// геттер (реализован через ссылки, в них возвращаются значения закрытых полей структуры)
   void get_coords(int& x, int& y)
   {
      x = this->x;
      y = this->y;
   }


};

int main()
{
// Если переменная в private, то инициализировать нельзя!
   // point pt {1, 2};  // начальная инициализация
   // pt.x = 10;
   // pt.y = 20;

   point pt;
   pt.set_x(5);
   cout << pt.get_x() << endl;

   point pt_2;
   pt_2.sum(pt);  // через метод pt_2 обращаемся к закрытым полям объекта pt.
   cout << pt_2.get_x() << endl;

   return 0;
}