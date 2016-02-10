// Ray Tracer: light.cpp
// 
// Author: Wesley Hauwiller
//
// Description: A Light provides a template for all possible lights in the scene. 
//                  Contains color data.
//
// Copyright (C) 2016  whauwiller.blogspot.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// A full copy of the GNU General Public License may be found at
// <http://www.gnu.org/licenses/>.
//

#include "light.h"

Light::Light(){
    this->color_ = RgbColor(0,0,0);
}

Light::~Light(){}

Light::Light(RgbColor color){
    this->color_ = color;
}

/**
 * Gets the color the light will project
 * 
 * @return Color projected by the light
 */
RgbColor Light::getColor(){
    return this->color_;
}

/**
 * Gets the a vector specifying direction from the light
 * (No-Op unless overridden)
 * 
 * @return Vector specifying direction from the light
 */
Vector3D* Light::getDirectionFromLight(){
    return 0;
}

/**
 * Gets the a vector specifying direction to the light
 * (No-Op unless overridden)
 * 
 * @return Vector specifying direction to the light
 */
Vector3D Light::getDirectionToLight(){
    return Vector3D(0,0,0);
}