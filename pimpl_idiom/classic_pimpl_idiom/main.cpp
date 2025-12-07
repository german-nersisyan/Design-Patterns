#include "image.hpp"
#include <iostream>

int main() {
    Image a(640, 480);
    a.fill(10, 20, 30);
    std::cout << a.info() << "\n";

    Image b = a;
    b.invert_colors();
    std::cout << "a: " << a.info() << "\n";
    std::cout << "b: " << b.info() << "\n";

    Image c = std::move(b);
    std::cout << "c: " << c.info() << "\n";
}