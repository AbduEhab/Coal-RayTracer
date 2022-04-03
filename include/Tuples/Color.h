#pragma once

#include "Constants.h"

namespace COAL
{
    class Color
    {
    public:
        [[nodiscard]] constexpr Color() : r(0), g(0), b(0), a(1){};

        [[nodiscard]] constexpr Color(double red, double green, double blue)
            : r(red > 255 ? 255 : red), g(green > 255 ? 255 : green), b(blue > 255 ? 255 : blue), a(0){};

        [[nodiscard]] int operator==(const Color &rhs) const noexcept
        {
            return (std::abs(r - rhs.r) <= 0.00001) && (std::abs(g - rhs.g) <= 0.00001) && (std::abs(b - rhs.b) <= 0.00001) && (rhs.a == 0);
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

        [[nodiscard]] constexpr Color operator*(const float factor) const noexcept
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
    static constexpr const Color DARK_GREY = Color(0.2, 0.2, 0.2);
    static constexpr const Color WHITE = Color(1, 1, 1);
    static constexpr const Color RED = Color(1, 0, 0);
    static constexpr const Color GREEN = Color(0, 1, 0);
    static constexpr const Color BLUE = Color(0, 0, 1);
    static constexpr const Color PURPLE = Color(1, 0, 1);
    static constexpr const Color YELLOW = Color(1, 1, 0);
}