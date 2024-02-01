#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

// Пример применения:
// в параметрах: указатель на функцию:
void show_ar(const int* ar, size_t length, bool (*filter_func)(int) = nullptr)
{
   for (int i=0; i < length; ++i)
   {
      if (filter_func != nullptr)
      {
         if (filter_func(ar[i]))
            cout << ar[i] << " ";
      }
      else
         cout << ar[i] << " ";
   }
}

int main()
{
   // int data[] {1, 2, 3, 4, 5, 6, 7, 8};
   // show_ar(data, sizeof(data)/sizeof(*data));
   // show_ar(data, sizeof(data)/sizeof(*data), [] (int x) { return x % 2 == 0; } );
   // show_ar(data, sizeof(data)/sizeof(*data), [] (int x) { return x % 3 == 0; } );

   return 0;
}