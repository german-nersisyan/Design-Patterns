#pragma once

#include <chrono>
#include <memory>
#include <string>

class Timer {

public:

    Timer();
    ~Timer();

    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    Timer(Timer&&) noexcept;
    Timer& operator=(Timer&&) noexcept;

    void reset();
    double seconds() const;
    std::string info() const;

private:

    struct Impl;
    std::unique_ptr<Impl> pImpl;
    
};