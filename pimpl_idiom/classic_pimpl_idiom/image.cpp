#include "image.hpp"

#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>

struct Image::Impl {
    int w = 0;
    int h = 0;

    std::vector<uint8_t> pixels;

    Impl() = default;
    Impl(int width, int height)
        : w(width), h(height), pixels(size_t(width) * height * 3, 0) {}

    std::unique_ptr<Impl> clone() const
    {
        auto c = std::make_unique<Impl>();
        c->w = w;
        c->h = h;
        c->pixels = pixels;
        return c;
    }

    std::string info() const
    {
        std::ostringstream oss;
        oss << "Image(" << w << "x" << h << "), pixels=" << pixels.size();
        return oss.str();
    }

    void fill(uint8_t r, uint8_t g, uint8_t b)
    {
        for (size_t i = 0; i < pixels.size(); i += 3) {
            pixels[i + 0] = r;
            pixels[i + 1] = g;
            pixels[i + 2] = b;
        }
    }

    void invert_colors()
    {
        for (auto &px : pixels) px = static_cast<uint8_t>(255u - px);
    }

};

Image::Image() : pImpl(std::make_unique<Impl>()) {}

Image::Image(int width, int height) : pImpl(std::make_unique<Impl>(width, height)) {}

Image::~Image() = default;

Image::Image(const Image& other)
    : pImpl(other.pImpl ? other.pImpl->clone() : nullptr) {}

Image& Image::operator=(const Image& other) 
{
    if (this == &other) return *this;
    auto copy = other.pImpl ? other.pImpl->clone() : nullptr;
    pImpl.swap(copy);
    return *this;
}

Image::Image(Image&&) noexcept = default;

Image& Image::operator=(Image&&) noexcept = default;

void Image::swap(Image& other) noexcept
{
    pImpl.swap(other.pImpl);
}

int Image::width() const { return pImpl ? pImpl->w : 0; }
int Image::height() const { return pImpl ? pImpl->h : 0; }

void Image::fill(uint8_t r, uint8_t g, uint8_t b)
{
    if (!pImpl) pImpl = std::make_unique<Impl>();
    pImpl->fill(r, g, b);
}

void Image::invert_colors()
{
    if (pImpl) pImpl->invert_colors();
}

std::string Image::info() const
{
    return pImpl ? pImpl->info() : std::string("Empty Image");
}