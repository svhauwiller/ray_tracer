// Ray Tracer: constant_shader.cpp
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

#include "constant_shader.h"

ConstantShader::ConstantShader() {
}

ConstantShader::ConstantShader(const ConstantShader& orig) {

}

ConstantShader::~ConstantShader() {
}

/**
 * Returns a number indicating the type of shader
 * 
 * Shader Number List (2/2/2016)
 * 0: Constant
 * 1: Phong
 * 
 * @return Numeric representation of the shader type (0)
 */
int ConstantShader::getType(){
    return 0;
}

/**
 * Gets the Diffuse Color
 * 
 * @return The Diffuse Color
 */
RgbColor ConstantShader::getDiffuseColor(){
    return this->diffuse_color_;
}

/**
 * Sets the Diffuse Color
 * 
 * @param diffuse_color Diffuse Color to set
 */
void ConstantShader::setDiffuseColor(RgbColor diffuse_color){
    this->diffuse_color_ = diffuse_color;
}
