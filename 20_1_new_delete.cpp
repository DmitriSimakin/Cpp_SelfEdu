#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

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

   ~point()
   {
      cout << "Call of object's destructor!" << endl;
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

// malloc(), calloc(), realloc() и free() - использовали ранее.
int main()
{
   // point* pt;
   // pt = (point*)malloc(sizeof(point));;
   // // что-то делаем
   // free(pt);
/* 
НО! Если так создавать и удалять структуру, то не вызываются
ни конструктор, ни деструктор. Для этого вводятся: new и delete.

---- Операторы new и delete ---- 

new - для выделения памяти под указанный тип данных с автоматическим
вызовом конструктора.

delete - освобождение памяти с автоматическим вызовом деструктора.
*/

   point* pt;
//    pt = new point; // также new возвращает сразу нужный тип данных
//                    // поэтому не нужно прописывать приведение типа.
// // Смешивать malloc, new, delete, free нельзя! м. привести к ошибке.
   
//    cout << pt->get_x() << " " << pt->get_y() << endl;
//    // do something
//    delete pt;

   // pt = new point(10, 20);
   // cout << pt->get_x() << " " << pt->get_y() << endl;
   // // do something
   // delete pt;

// new delete можно использовать с базовыми типами!
   int* ptr_int = new int;
   int* ptr_int_2 = new int{-123};
   delete ptr_int;
   delete ptr_int_2;

   cout << *ptr_int_2 << endl;
   
   return 0;
}


   
