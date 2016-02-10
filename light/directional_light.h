// Ray Tracer: directional_light.h
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

#ifndef DIRECTIONAL_LIGHT_H
#define	DIRECTIONAL_LIGHT_H

#include "light.h"
#include "../math/rgb_color.h"
#include "../math/vector3d.h"

class DirectionalLight : public Light{
    public:
        DirectionalLight();
        DirectionalLight(RgbColor color, Vector3D* direction);
        virtual ~DirectionalLight();
        
        int getType();
        Vector3D* getDirectionFromLight();
        Vector3D getDirectionToLight();
    private:
        Vector3D* direction_from_light_;
};

#endif	/* DIRECTIONAL_LIGHT_H */

