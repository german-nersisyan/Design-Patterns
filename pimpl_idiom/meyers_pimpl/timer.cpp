#include "timer.hpp"
#include <sstream>

struct Timer::Impl {

    using clock = std::chrono::steady_clock;
    clock::time_point start;

    Impl() : start(clock::now()) {}

    void reset()
    {
        start = clock::now();
    }

    double seconds() const
    {
        auto now = clock::now();
        auto dur = std::chrono::duration<double>(now - start);
        return dur.count();
    }

    std::string info() const
    {
        std::ostringstream oss;
        oss << "Timer: " << seconds() << "s elapsed";
        return oss.str();
    }

};

Timer::Timer()
    : pImpl(std::make_unique<Impl>())
{}

Timer::~Timer() = default;

Timer::Timer(Timer&& other) noexcept = default;
Timer& Timer::operator=(Timer&& other) noexcept = default;

void Timer::reset()
{
    pImpl->reset();
}

double Timer::seconds() const
{
    return pImpl->seconds();
}

std::string Timer::info() const
{
    return pImpl->info();
}