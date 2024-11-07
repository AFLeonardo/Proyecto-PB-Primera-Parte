// Controlling precision of floating point values
#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
    double root2 = sqrt(2.0);

    std::cout << "Precisiones 0-9.\n"
              << "Ejemplos:\n";

    for (int places = 0; places <= 9; places++) {
        std::cout.precision(places);
        std::cout << root2 << std::endl;
    }

    std::cout << "\nPrecisiones con setprecision:\n";

    for (int places = 0; places <= 9; places++) {
        std::cout << std::setprecision(places) << root2 << std::endl;
    }

    return 0;
}