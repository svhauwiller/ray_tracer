// Ray Tracer: ambient_light.h
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

#ifndef AMBIENT_LIGHT_H
#define AMBIENT_LIGHT_H

#include "light.h"
#include "../math/vector3d.h"

class AmbientLight : public Light {
public:
    AmbientLight();
    AmbientLight(RgbColor color);
    AmbientLight(const AmbientLight& orig);
    virtual ~AmbientLight();
    
    int getType();
private:

};

#endif /* AMBIENT_LIGHT_H */

