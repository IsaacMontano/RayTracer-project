#pragma once

#include "Vec.h"

class Light 
{
public:
	enum class LightType{ambient, Directional, Point};

	LightType light_type;
	float intensity; //to vec3 if you want color light
	Vec3f position; //for directional lights, this is the direction

	Light(LightType light_type, float intensity, const Vec3f& position={ 0.0, 0.0, 0.0 })
		: light_type(light_type), intensity(intensity), position(position)
	{
	}



};
