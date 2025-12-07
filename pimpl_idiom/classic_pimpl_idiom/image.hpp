#pragma once

#include <cstdint>
#include <string>
#include <memory>

class Image {

public:

    Image();
    Image(int width, int height);
    ~Image();

    Image(const Image& other);
    Image& operator=(const Image& other);

    Image(Image&&) noexcept;
    Image& operator=(Image&&) noexcept;

    int width() const;
    int height() const;
    void fill(uint8_t r, uint8_t g, uint8_t b);
    void invert_colors();
    std::string info() const;

private:

    struct Impl;
    std::unique_ptr<Impl> pImpl;

    void swap(Image& other) noexcept;

};