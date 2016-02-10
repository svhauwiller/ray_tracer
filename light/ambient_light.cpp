// Ray Tracer: ambient_light.cpp
// 
// Author: Wesley Hauwiller
//
// Description: An Ambient Light colors the entire scene equally regardless of
//                 scene configuration.
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

#include "ambient_light.h"

AmbientLight::AmbientLight() {
    this->color_ = RgbColor(0,0,0);
}

AmbientLight::AmbientLight(RgbColor color){
    this->color_ = color;
}

AmbientLight::AmbientLight(const AmbientLight& orig) {

}

AmbientLight::~AmbientLight() {
}

/**
 * Returns an integer flag defining the type of light.
 * 
 * Light Flag List (2/2/2016)
 * 
 * 0: Ambient
 * 1: Directional
 * 
 * @return The flag defining the light as an ambient type (0)
 */
int AmbientLight::getType(){
    return 0;
}
