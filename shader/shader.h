// Ray Tracer: shader.h
// 
// Author: Wesley Hauwiller
//
// Description: A Shader provides a template for storing color data on a geometry.
//                 By default it only contains a diffuse color.
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

#ifndef SHADER_H
#define SHADER_H

#include "../math/rgb_color.h"

class Shader {
public:
    Shader();
    Shader(const Shader& orig);
    virtual ~Shader();
    
    //0: Constant
    //1: Phong
    virtual int getType() = 0;
    
    virtual bool hasReflection();
    virtual bool hasRefraction();
    
    virtual RgbColor getDiffuseColor();
    virtual void setDiffuseColor(RgbColor diffuse_color);
    virtual RgbColor getSpecularHighlight();
    virtual void setSpecularHighlight(RgbColor specular_highlight);
    virtual RgbColor getReflectiveColor();
    virtual void setReflectiveColor(RgbColor reflective_color);
    virtual int getPhongConstant();
    virtual void setPhongConstant(int phong_constant);
    virtual double getRefractionIndex();
    virtual void setRefractionIndex(double refraction_index);
protected:
    
    
};

#endif /* SHADER_H */

