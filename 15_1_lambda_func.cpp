// Начиная с C++11 появились лямбда-функции
// [] ([параметры]) {<операторы тела функции>}

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
   // [] (int a)
   // {
   //    std::cout << "Lambda-function: " << a << endl;
   // };
   // // тем самым мы создали объект-функцию, но не вызвали её
   // // чтобы её вызвать поставим оператор вызова функции () и 
   // // передадим аргумент:
   // [] (int a)
   // {
   //    std::cout << "Lambda-function: " << a << endl;
   // }(10);

   // // присвоим лямбда-выражение переменной.
   // // r не ссылается на лямбда-функцию, 
   // // а само является этой функцией (объектом-функцией).
   // auto r = [] (int a)
   // {
   //    std::cout << "Lambda-function: " << a << endl;
   // }; 

   // auto s = r; // s явл. другим объектом-функцией! (это 2 разных о.-ф.)
   // auto s {r}; // аналогично.
   // // а можно даже инициализировать сразу:

   // auto s  { [] (const char* msg, double& x)
   //            {
   //                cout << msg << endl;
   //                x++;
   //            }
   //          };

   // double b {0};
   // s("increment", b);
   // cout << b << endl;

   // // лямбда-выражение м. также возвращать данные:
   // auto s  { [] (const char* msg, double x)
   //            {
   //                cout << msg << endl;
   //                return ++x;
   //            }
   //          };

   // double b {0};
   // b = s("increment", b);
   // cout << b << endl;

// // Ещё пример, после стрелочки можно явно указать желаемый
// // возвращаемый тип данных:
//    auto sum2 { [] (int a, int b) -> double { return a+b; } };
//    cout << sum2(2, 3) << endl;

// // Начиная со стандарта C++14 в лямбда-выражениях 
// // можно использовать вычисляемый тип у параметров.   
//    auto sum2 { [] (auto a, auto b) -> double { return a+b; } };
//    double res_1 = sum2(2, 3);
//    double res_2 = sum2(2.4, 3.5);
//    cout << res_1 << " " << res_2 << endl;

// // Можно пойти ещё дальше: возвращаемый вычисляемый тип будет 
// // определяться по выражению в return:
//    auto sum2 { [] (auto a, auto b) -> auto { return a+b; } };
//    std::string res_3 = sum2(std::string("Hello, "), std::string("world!"));
//    cout << res_3 << endl;
   
   return 0;
}