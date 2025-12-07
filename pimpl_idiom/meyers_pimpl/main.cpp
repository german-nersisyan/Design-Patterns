#include "timer.hpp"
#include <iostream>
#include <thread>

int main() {
    Timer t;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << t.info() << "\n";

    t.reset();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "After reset: " << t.seconds() << "s\n";

    return 0;
}