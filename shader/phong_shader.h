// Ray Tracer: phong_shader.h
// 
// Author: Wesley Hauwiller
//
// Description: A Phong Shader uses the Phong Reflection model to combine 
//                  the global ambient color with a diffuse color and 
//                  specular reflection to generate the color on each pixel.
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

#ifndef PHONG_SHADER_H
#define PHONG_SHADER_H

#include "shader.h"

class PhongShader: public Shader {
public:
    PhongShader();
    PhongShader(const PhongShader& orig);
    virtual ~PhongShader();
    
    int getType();
    
    bool hasReflection();
    bool hasRefraction();
    RgbColor getDiffuseColor();
    void setDiffuseColor(RgbColor diffuse_color);
    RgbColor getSpecularHighlight();
    void setSpecularHighlight(RgbColor specular_highlight);
    RgbColor getReflectiveColor();
    void setReflectiveColor(RgbColor reflective_color);
    int getPhongConstant();
    void setPhongConstant(int phong_constant);
    double getRefractionIndex();
    void setRefractionIndex(double refraction_index);
    
private:
    RgbColor diffuse_color_;
    RgbColor specular_highlight_;
    RgbColor reflective_color_;
    int phong_constant_;
    double refraction_index_;
};

#endif /* PHONG_SHADER_H */

