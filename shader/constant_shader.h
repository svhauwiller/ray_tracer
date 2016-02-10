// Ray Tracer: constant_shader.h
// 
// Author: Wesley Hauwiller
//
// Description: A Constant Shader defines the same color for every pixel 
//                 containing the geometry regardless of scene configuration.
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

#ifndef CONSTANT_SHADER_H
#define CONSTANT_SHADER_H

#include "shader.h"

class ConstantShader: public Shader {
public:
    ConstantShader();
    ConstantShader(const ConstantShader& orig);
    virtual ~ConstantShader();
    
    int getType();
    
    RgbColor getDiffuseColor();
    void setDiffuseColor(RgbColor diffuse_color);
    
private:
    RgbColor diffuse_color_;
};

#endif /* CONSTANT_SHADER_H */

