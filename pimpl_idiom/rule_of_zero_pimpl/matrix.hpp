#pragma once

#include <memory>

class Matrix {
public:
    Matrix();
    Matrix(int rows, int cols);

    double trace() const;
    void fill(double value);

private:
    struct Impl;
    std::shared_ptr<Impl> pImpl;
};