// Ray Tracer: directional_light.cpp
// 
// Author: Wesley Hauwiller
//
// Description: An Directional Light casts light from a constant direction 
//                  regardless of scene configuration. Light from a 
//                  Directional Light can be obscured by geometry.
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

#include "directional_light.h"

DirectionalLight::DirectionalLight(){
    this->color_ = RgbColor(0,0,0);
    this->direction_from_light_ = new Vector3D(0,0,0);
}

DirectionalLight::DirectionalLight(RgbColor _color, Vector3D* _direction){
    this->color_ = _color;
    this->direction_from_light_ = _direction;
}

DirectionalLight::~DirectionalLight(){
    delete this->direction_from_light_;
}

/**
 * Returns an integer flag defining the type of light.
 * 
 * Light Flag List (2/2/2016)
 * 
 * 0: Ambient
 * 1: Directional
 * 
 * @return The flag defining the light as a directional type (1)
 */
int DirectionalLight::getType(){
    return 1;
}

/**
 * Gets the direction the light is being cast in
 * 
 * @return Direction the light is being cast in
 */
Vector3D* DirectionalLight::getDirectionFromLight(){
    return this->direction_from_light_;
}

/**
 * Gets the direction the light is originating from
 * 
 * @return Direction the light is originating from
 */
Vector3D DirectionalLight::getDirectionToLight(){
    return Vector3D(-this->direction_from_light_->getX(), -this->direction_from_light_->getY(), -this->direction_from_light_->getZ());
}
