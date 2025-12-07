#include "matrix.hpp"
#include <iostream>

int main() {
    Matrix m(3, 3);
    m.fill(2.0);
    std::cout << m.trace() << "\n";

    Matrix copy = m;
    std::cout << copy.trace() << "\n";

    return 0;
}