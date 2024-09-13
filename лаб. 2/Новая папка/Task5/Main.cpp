// Main 
#include <iostream>
#include "Combi.h"
#include "Knapsack.h"
#include <ctime>
#include <random>
#define NN 18
int main()
{
    setlocale(LC_ALL, "rus");
    int* v = new int[NN];
    int* c = new int[NN];
    int V = 300;  
    srand(time(0));
    for (int i = 0; i <= NN; i++) {
        v[i] = rand() % 290 + 10;
    }
    for (int i = 0; i <= NN; i++) {
        c[i] = rand() % 50 + 5;
    }
    // вместимость рюкзака              
       // v[] = { 25, 30, 54, 20, 10, 7, 22, 11, 5, 7, 40, 55, 28, 17, 9, 34, 51, 50 };     // размер предмета каждого типа  
       // c[] = { 5, 10, 2, 3, 10, 7, 12, 5, 3, 15, 6, 3, 17, 13, 8, 9, 1, 1 };     // стоимость предмета каждого типа 
    short m[NN];                // количество предметов каждого типа  {0,1}   

    clock_t  t1 = 0, t2 = 0;
    t1 = clock();
    int maxcc = knapsack_s(

        V,   // [in]  вместимость рюкзака 
        NN,  // [in]  количество типов предметов 
        v,   // [in]  размер предмета каждого типа  
        c,   // [in]  стоимость предмета каждого типа     
        m    // [out] количество предметов каждого типа  
    );
    t2 = clock();

    std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
    std::cout << std::endl << "- количество предметов : " << NN;
    std::cout << std::endl << "- вместимость рюкзака  : " << V;
    std::cout << std::endl << "- размеры предметов    : ";
    for (int i = 0; i < NN; i++) std::cout << v[i]  << " ";
    std::cout << std::endl << "- стоимости предметов  : ";
    for (int i = 0; i < NN; i++) std::cout << c[i] << " ";
    std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
    std::cout << std::endl << "- вес рюкзака: ";
    int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
    std::cout << s;
    std::cout << std::endl << "- выбраны предметы: " << std::endl;
    for (int i = 0; i < NN; i++) 
    {
        //std::cout << " " << m[i];
        if (m[i] > 0) {
            std::cout << "( стоимость: " << c[i] << ")";
            std::cout << "( вес: " << v[i] << ")";
            std::cout << "( id: " << i << ")" << std::endl;
        }
    }
    std::cout << std::endl << std::endl;
    std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
    std::cout << std::endl << "                  (сек):   "
        << ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
    std::cout << std::endl;

    system("pause");
    return 0;
}
