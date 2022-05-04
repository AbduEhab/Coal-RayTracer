#pragma once

#include "Matrix.h"
#include "Shapes/Shape.h"
#include "Tuples/Color.h"
#include "Tuples/Point.h"

namespace COAL
{
    struct Shape;

    struct Pattern
    {
        [[nodiscard]] constexpr Pattern(){};

        // init pattern with first and second color
        [[nodiscard]] constexpr Pattern(Color &first, Color &second)
        {
            m_first_color = first;
            m_second_color = second;
        }

        // init pattern with first and second color and transform matrix
        [[nodiscard]] constexpr Pattern(Color &first, Color &second, COAL::Matrix4 &transform)
        {
            m_first_color = first;
            m_second_color = second;
            m_transform = transform;
        }

        [[nodiscard]] virtual COAL::Color color_at(const COAL::Point &p) const = 0;

        [[nodiscard]] COAL::Color colot_at(const Shape &s, const COAL::Point &p) const;

        // == operator
        friend bool operator==(const Pattern &lhs, const Pattern &rhs)
        {
            return lhs.m_first_color == rhs.m_first_color && lhs.m_second_color == rhs.m_second_color &&
                   lhs.m_transform == rhs.m_transform;
        }

        // << operator
        friend std::ostream &operator<<(std::ostream &os, const Pattern &pattern)
        {
            os << "Pattern(" << pattern.m_first_color << ", " << pattern.m_second_color << ")";
            return os;
        }

        COAL::Matrix4 m_transform = COAL::IDENTITY;
        COAL::Color m_first_color = COAL::WHITE;
        COAL::Color m_second_color = COAL::BLACK;
    };

} // namespace COAL
