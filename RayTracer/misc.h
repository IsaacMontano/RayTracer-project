#pragma once

constexpr float pi                 = 3.14159265358979323846f ;  // pi
constexpr float square_root_of_two = 1.41421356237309504880f ;  // sqrt(2)

#include <SDL.h>
#include <cmath>
#include "Vec.h"
#include "Plane.h"

inline bool should_keep_rendering()
{
    SDL_Event event ;
    SDL_PollEvent( &event ) ;
    return event.type != SDL_QUIT ;
}

inline float compute_dot_product( const Vec3f& v1, const Vec3f& v2 )
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z ;
}

inline float compute_dot_product( const Vec3f& v1, const Vec4f& v2 )
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z ;
}

inline Vec3f compute_intersection( const Vec3f& v1, const Vec3f& v2, const Plane& p )
{
    auto t_num = -p.distance - compute_dot_product( p.normal, v1 ) ;
    auto t_den = compute_dot_product( p.normal, v2 - v1 ) ;
    auto t = t_num / t_den ;
    return v1 + t * ( v2 - v1 ) ;
}

inline float compute_vector_length(const Vec3f& v) 
{
    return std::sqrt(compute_dot_product(v, v));
}
