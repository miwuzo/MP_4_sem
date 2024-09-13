#include "pch.h"
#include "Auxil.h"
#include <ctime>

using namespace std;

namespace auxil {
    void start() {
        srand((unsigned)time(NULL));
    };
    double dget(double rmin, double rmax) {
        return ((double)rand() / (double)RAND_MAX) * (rmax - rmin) + rmin;
    };
    int iget(int rmin, int rmax) {
        return (int)dget((double)rmin, (double)rmax);
    };
}

int main() {
    auxil::start();

    // Генерация случайного числа double

    double randomDouble = auxil::dget(0.0, 2.0);
    cout << "Random double: " << randomDouble << endl;

    // Генерация случайного числа int

    int randomInt = auxil::iget(0, 32);
    cout << "Random int: " << randomInt << endl;

    return 0;
}
