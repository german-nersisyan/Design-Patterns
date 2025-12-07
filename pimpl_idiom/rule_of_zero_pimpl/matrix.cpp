#include "matrix.hpp"

#include <vector>
#include <stdexcept>

struct Matrix::Impl {

    int r = 0;
    int c = 0;
    std::vector<double> data;

    Impl() = default;
    Impl(int rows, int cols)
        : r(rows), c(cols), data(rows*cols) {}

    double trace() const
    {
        if (r != c) throw std::runtime_error("Non-square matrix");
        double t = 0;
        for (int i = 0; i < r; ++i) {
            t += data[i*r + i];
        }
        return t;
    }

    void fill(double v)
    {
        std::fill(data.begin(), data.end(), v);
    }

};

Matrix::Matrix()
    : pImpl(std::make_shared<Impl>())
{}

Matrix::Matrix(int rows, int cols)
    : pImpl(std::make_shared<Impl>(rows, cols))
{}

double Matrix::trace() const
{
    return pImpl->trace();
}

void Matrix::fill(double value)
{
    pImpl->fill(value);
}