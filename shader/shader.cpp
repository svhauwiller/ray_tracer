// Ray Tracer: shader.cpp
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

#include "shader.h"

Shader::Shader() {
}

Shader::Shader(const Shader& orig) {
}

Shader::~Shader() {
}

/**
 * Queries the shader to see whether it has reflection or not
 * (No-Op unless overridden)
 * 
 * @return Boolean indicating presence of reflection in the shader
 */
bool Shader::hasReflection(){
    return false;
}

/**
 * Queries the shader to see whether it has refraction or not
 * (No-Op unless overridden)
 * 
 * @return Boolean indicating presence of refraction in the shader
 */
bool Shader::hasRefraction(){
    return false;
}

/**
 * Gets the Diffuse Color
 * (No-Op unless overridden)
 * 
 * @return The Diffuse Color
 */
RgbColor Shader::getDiffuseColor(){
    return RgbColor(0,0,0);
}

/**
 * Sets the Diffuse Color
 * (No-Op unless overridden)
 * 
 * @param diffuse_color Diffuse Color to set
 */
void Shader::setDiffuseColor(RgbColor diffuse_color){ }


/**
 * Gets the specular highlight color 
 * (No-Op unless overridden)
 * 
 * @return Specular highlight color
 */
RgbColor Shader::getSpecularHighlight(){
    return RgbColor(0,0,0);
}

/**
 * Sets the specular highlight color
 * (No-Op unless overridden)
 * 
 * @param specular_highlight Specular highlight color to set
 */
void Shader::setSpecularHighlight(RgbColor specular_highlight){ }

/**
 * Gets the reflective color
 * (No-Op unless overridden)
 * 
 * @return Shader Reflective Color
 */
RgbColor Shader::getReflectiveColor(){
    return RgbColor(0,0,0);
}

/**
 * Sets the reflective color
 * (No-Op unless overridden)
 * 
 * @param reflective_color Reflective color to set
 */
void Shader::setReflectiveColor(RgbColor reflective_color){ }

/**
 * Gets the phong constant indicating the amount of specular reflection
 * (No-Op unless overridden)
 * 
 * @return Phong Constant
 */
int Shader::getPhongConstant(){
    return 0;
}

/**
 * Sets the phong constant that indicates the amount of specular reflection
 * (No-Op unless overridden)
 * 
 * @param phong_constant Phong Constant to set
 */
void Shader::setPhongConstant(int phong_constant){ }

/**
 * Gets the index of refraction
 * (No-Op unless overridden)
 * 
 * @return Index of Refraction
 */
double Shader::getRefractionIndex(){
    return 0;
}

/**
 * Sets the shader's index of refraction
 * (No-Op unless overridden)
 * 
 * @param refraction_index Refraction index to set
 */
void Shader::setRefractionIndex(double refraction_index){ }