#pragma once

#include "Constants.h"

namespace COAL
{
    struct Color
    {
        [[nodiscard]] constexpr Color() : r(0), g(0), b(0), a(0xff){};

        [[nodiscard]] constexpr Color(double red, double green, double blue)
            : r(red > 255 ? 255 : red), g(green > 255 ? 255 : green), b(blue > 255 ? 255 : blue), a(0xff){};

        [[nodiscard]] constexpr Color(const float (&vector_array)[3]) : r(vector_array[0] > 255 ? 255 : vector_array[0]), g(vector_array[1] > 255 ? 255 : vector_array[1]), b(vector_array[2] > 255 ? 255 : vector_array[2]), a(0xff){};

        [[nodiscard]] int operator==(const Color &rhs) const noexcept
        {
            return (std::abs(r - rhs.r) <= kEpsilon) && (std::abs(g - rhs.g) <= kEpsilon) && (std::abs(b - rhs.b) <= kEpsilon) && (rhs.a == 0);
        }

        static constexpr uint32_t createRGBA(uint32_t r, uint32_t g, uint32_t b, uint32_t a) noexcept
        {
            return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8) + (a & 0xff);
        }

        constexpr uint32_t createRGBA() const noexcept
        {
            return (((int)r & 0xff) << 24) + (((int)g & 0xff) << 16) + (((int)b & 0xff) << 8) + ((int)a & 0xff);
        }

        static constexpr uint32_t createABGR(uint32_t r, uint32_t g, uint32_t b, uint32_t a) noexcept
        {
            return (((uint32_t)a & 0xff) << 24) + (((uint32_t)b & 0xff) << 16) + (((uint32_t)g & 0xff) << 8) + ((uint32_t)r & 0xff);
        }

        constexpr uint32_t createABGR() const noexcept
        {
            return (((uint32_t)a & 0xff) << 24) + (((uint32_t)b & 0xff) << 16) + (((uint32_t)g & 0xff) << 8) + ((uint32_t)r & 0xff);
        }

        [[nodiscard]] constexpr Color &operator+=(const double rhs) noexcept
        {
            r = r + rhs;
            g = g + rhs;
            b = b + rhs;
            return *this;
        }

        [[nodiscard]] constexpr Color &operator+=(const Color &rhs) noexcept
        {
            r += rhs.r;
            g += rhs.g;
            b += rhs.b;
            return *this;
        }

        [[nodiscard]] constexpr Color &operator-=(const double rhs) noexcept
        {
            r = r - rhs;
            g = g - rhs;
            b = b - rhs;
            return *this;
        }

        [[nodiscard]] constexpr Color &operator-=(const Color &rhs) noexcept
        {
            r -= rhs.r;
            g -= rhs.g;
            b -= rhs.b;
            return *this;
        }

        [[nodiscard]] constexpr Color &operator*=(float factor) noexcept
        {
            r *= factor;
            g *= factor;
            b *= factor;
            return *this;
        }

        [[nodiscard]] constexpr Color &operator*=(const Color &rhs) noexcept
        {
            r *= rhs.r;
            g *= rhs.g;
            b *= rhs.b;
            return *this;
        }

        [[nodiscard]] constexpr Color operator+(const Color &rhs) const noexcept
        {
            return Color(r + rhs.r, g + rhs.g, b + rhs.b);
        }

        [[nodiscard]] constexpr Color operator+(const double rhs) const noexcept
        {
            return Color(r + rhs, g + rhs, b + rhs);
        }

        [[nodiscard]] constexpr Color operator-(const double rhs) const noexcept
        {
            return Color(r - rhs, g - rhs, b - rhs);
        }

        [[nodiscard]] constexpr Color operator-(const Color &rhs) const noexcept
        {
            return Color(r - rhs.r, g - rhs.g, b - rhs.b);
        }

        [[nodiscard]] constexpr Color operator*(const double factor) const noexcept
        {
            return Color(r * factor, g * factor, b * factor);
        }

        [[nodiscard]] constexpr Color operator*(const Color &rhs) const noexcept
        {
            return Color(r * rhs.r, g * rhs.g, b * rhs.b);
        }

        friend std::ostream &operator<<(std::ostream &os, const Color &dt)
        {
            os << "(" << dt.r << ", " << dt.g << ", " << dt.b << ")";
            return os;
        };

        double r;
        double g;
        double b;
        double a;
    };

    static constexpr const Color BLACK = Color(0, 0, 0);
    static constexpr const Color GREY = Color(0.2 * 255, 0.2 * 255, 0.2 * 255);
    static constexpr const Color WHITE = Color(255, 255, 255);
    static constexpr const Color RED = Color(255, 0, 0);
    static constexpr const Color GREEN = Color(0, 255, 0);
    static constexpr const Color BLUE = Color(0, 0, 255);
    static constexpr const Color PURPLE = Color(255, 0, 255);
    static constexpr const Color YELLOW = Color(255, 255, 0);
}