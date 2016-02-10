// Ray Tracer: light.h
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

#ifndef LIGHT_H
#define	LIGHT_H

#include "../math/rgb_color.h"
#include "../math/vector3d.h"

class Light{
public:
    Light();
    Light(RgbColor color);
    virtual ~Light();
    
    RgbColor getColor();
    
    //0: Ambient
    //1: Directional
    virtual int getType() = 0;
    virtual Vector3D* getDirectionFromLight();
    virtual Vector3D getDirectionToLight();
    
protected:
    RgbColor color_;
};

#endif	/* LIGHT_H */

