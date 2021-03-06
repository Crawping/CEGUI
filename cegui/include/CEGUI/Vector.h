/***********************************************************************
	created:	13/2/2011
	author:		Martin Preisler (reworked from code by Paul D Turner)
	
	purpose:	Defines interfaces for Vector classes
*************************************************************************/
/***************************************************************************
 *   Copyright (C) 2004 - 2011 Paul D Turner & The CEGUI Development Team
 *
 *   Permission is hereby granted, free of charge, to any person obtaining
 *   a copy of this software and associated documentation files (the
 *   "Software"), to deal in the Software without restriction, including
 *   without limitation the rights to use, copy, modify, merge, publish,
 *   distribute, sublicense, and/or sell copies of the Software, and to
 *   permit persons to whom the Software is furnished to do so, subject to
 *   the following conditions:
 *
 *   The above copyright notice and this permission notice shall be
 *   included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *   IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 *   OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 ***************************************************************************/
#ifndef _CEGUIVector_h_
#define _CEGUIVector_h_

#include "CEGUI/UDim.h"
#include <typeinfo>
#include <ostream>

// Start of CEGUI namespace section
namespace CEGUI
{

/*!
\brief
    Class used as a two dimensional vector (aka a Point)

\par
    This class is templated now, this allows us to use it as a Vector2 of floats,
    ints or even UDims without replicating the code all over the place.
*/
template<typename T>
class Vector2
{
public:
    typedef T value_type;

    inline Vector2()
    {}
    
    inline Vector2(const T x, const T y):
        d_x(x),
        d_y(y)
    {}

    inline Vector2(const Vector2& v):
        d_x(v.d_x),
        d_y(v.d_y)
    {}

    inline Vector2& operator*=(const Vector2& vec)
    {
        d_x *= vec.d_x;
        d_y *= vec.d_y;

        return *this;
    }

    inline Vector2& operator/=(const Vector2& vec)
    {
        d_x /= vec.d_x;
        d_y /= vec.d_y;

        return *this;
    }

    inline Vector2& operator+=(const Vector2& vec)
    {
        d_x += vec.d_x;
        d_y += vec.d_y;

        return *this;
    }

    inline Vector2& operator-=(const Vector2& vec)
    {
        d_x -= vec.d_x;
        d_y -= vec.d_y;

        return *this;
    }

    inline Vector2 operator+(const Vector2& vec) const
    {
        return Vector2(d_x + vec.d_x, d_y + vec.d_y);
    }

    inline Vector2 operator-(const Vector2& vec) const
    {
        return Vector2(d_x - vec.d_x, d_y - vec.d_y);
    }

    inline Vector2 operator*(const Vector2& vec) const
    {
        return Vector2(d_x * vec.d_x, d_y * vec.d_y);
    }

    inline Vector2 operator/(const Vector2& vec) const
    {
        return Vector2(d_x / vec.d_x, d_y / vec.d_y);
    }

    inline Vector2 operator*(const T c) const
    {
        return Vector2(d_x * c, d_y * c);
    }

    inline Vector2& operator*=(const T c)
    {
        d_x *= c;
        d_y *= c;

        return *this;
    }

    inline Vector2 operator/(const T c) const
    {
        return Vector2(d_x / c, d_y / c);
    }

    inline Vector2 operator/=(const T c)
    {
        d_x /= c;
        d_y /= c;

        return *this;
    }

    inline bool operator==(const Vector2& vec) const
    {
        return ((d_x == vec.d_x) && (d_y == vec.d_y));
    }

    inline bool operator!=(const Vector2& vec) const
    {
        return !(operator==(vec));
    }
    
    /*!
    \brief allows writing the vector2 to std ostream
    */
    inline friend std::ostream& operator << (std::ostream& s, const Vector2& v)
    {
        s << "CEGUI::Vector2<" << typeid(T).name() << ">(" << v.d_x << ", " << v.d_y << ")";
        return s;
    }

    //! \brief finger saving alias for Vector2(0, 0)
    inline static Vector2 zero()
    {
        return Vector2(TypeSensitiveZero<T>(), TypeSensitiveZero<T>());
    }

    //! \brief finger saving alias for Vector2(1, 1)
    inline static Vector2 one()
    {
        return Vector2(TypeSensitiveOne<T>(), TypeSensitiveOne<T>());
    }
    
    //! \brief finger saving alias for Vector2(1, 0)
    inline static Vector2 one_x()
    {
        return Vector2(TypeSensitiveOne<T>(), TypeSensitiveZero<T>());
    }
    
    //! \brief finger saving alias for Vector2(0, 1)
    inline static Vector2 one_y()
    {
        return Vector2(TypeSensitiveZero<T>(), TypeSensitiveOne<T>());
    }

    T d_x;
    T d_y;
};

// we need to allow UVector2 to be multiplied by floats, this is the most elegant way to do that
inline Vector2<UDim> operator * (const Vector2<UDim>& v, const float c)
{
    return Vector2<UDim>(v.d_x * c, v.d_y * c);
}

typedef Vector2<UDim> UVector2;

} // End of  CEGUI namespace section

#endif	// end of guard _CEGUIVector_h_
