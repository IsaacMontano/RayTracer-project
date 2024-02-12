#pragma once

#include <cstdint>
#include "Vec.h"

// Found the list of 48 named colors at:
//   https://simple.wikipedia.org/wiki/Template:Web_colors

class Color final
{
public:
    static Color pink ;
    static Color crimson ;
    static Color red ;
    static Color maroon ;
    static Color brown ;
    static Color misty_rose ;
    static Color salmon ;
    static Color coral ;
    static Color orange_red ;
    static Color chocolate ;
    static Color orange ;
    static Color gold ;
    static Color ivory ;
    static Color yellow ;
    static Color olive ;
    static Color yellow_green ;
    static Color lawn_green ;
    static Color chartreuse ;
    static Color lime ;
    static Color green ;
    static Color spring_green ;
    static Color aquamarine ;
    static Color turquoise ;
    static Color azure ;
    static Color cyan ;
    static Color teal ;
    static Color lavender ;
    static Color blue ;
    static Color navy ;
    static Color blue_violet ;
    static Color indigo ;
    static Color dark_violet ;
    static Color plum ;
    static Color magenta ;
    static Color purple ;
    static Color red_violet ;
    static Color tan ;
    static Color beige ;
    static Color slate_gray ;
    static Color dark_slate_gray ;
    static Color white ;
    static Color white_smoke ;
    static Color light_gray ;
    static Color silver ;
    static Color dark_gray ;
    static Color gray ;
    static Color dim_gray ;
    static Color black ;

    const uint8_t r ;
    const uint8_t g ;
    const uint8_t b ;

    static Color custom( unsigned int r, unsigned int g, unsigned int b )
    {
        uint8_t r_uint8 = r < 0 ? 0 : r > 255 ? 255 : r;
        uint8_t g_uint8 = g < 0 ? 0 : g > 255 ? 255 : g;
        uint8_t b_uint8 = b < 0 ? 0 : b > 255 ? 255 : b;
        return { r_uint8, g_uint8, b_uint8 } ;
    }

    friend Color operator*(const Color& color, float intensity) 
    {
        auto r_uint = static_cast<unsigned int>(static_cast<float>(color.r) * intensity);
        auto g_uint = static_cast<unsigned int>(static_cast<float>(color.g) * intensity);
        auto b_uint = static_cast<unsigned int>(static_cast<float>(color.b) * intensity);

        return custom(r_uint, g_uint, b_uint);
    }

    friend Color operator+(const Color& c1, const Color& c2) 
    {
        return custom(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b );
    }

private:
    Color( uint8_t r, uint8_t g, uint8_t b )
        : r( r ), g( g ), b( b )
    {}

} ;
