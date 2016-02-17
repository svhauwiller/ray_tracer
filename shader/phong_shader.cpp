// Ray Tracer: phong_shader.cpp
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

#include "phong_shader.h"

PhongShader::PhongShader() {
    this->diffuse_color_ = RgbColor(0,0,0);
    this->specular_highlight_ = RgbColor(0,0,0);
    this->reflective_color_ = RgbColor(0,0,0);
    this->phong_constant_ = 2;
    this->refraction_index_ = 1.33;
}

PhongShader::PhongShader(const PhongShader& orig) {

}

PhongShader::~PhongShader() {
}

/**
 * Returns a number indicating the type of shader
 * 
 * Shader Number List (2/2/2016)
 * 0: Constant
 * 1: Phong
 * 
 * @return Numeric representation of the shader type (1)
 */
int PhongShader::getType(){
    return 1;
}

/**
 * Queries the shader to see whether it has reflection or not
 * 
 * @return Boolean indicating presence of reflection in the shader
 */
bool PhongShader::hasReflection(){
    if(this->reflective_color_.isBlack()){
        return false;
    } else {
        return true;
    }
}

/**
 * Queries the shader to see whether it has refraction or not
 * 
 * @return Boolean indicating presence of refraction in the shader
 */
bool PhongShader::hasRefraction(){
    if(this->refraction_index_ == 0.0){
        return false;
    } else {
        return true;
    }
}

/**
 * Gets the Diffuse Color
 * 
 * @return The Diffuse Color
 */
RgbColor PhongShader::getDiffuseColor(){
    return this->diffuse_color_;
}

/**
 * Sets the Diffuse Color
 * 
 * @param diffuse_color Diffuse Color to set
 */
void PhongShader::setDiffuseColor(RgbColor diffuse_color){
    this->diffuse_color_ = diffuse_color;
}

/**
 * Gets the specular highlight color 
 * 
 * @return Specular highlight color
 */
RgbColor PhongShader::getSpecularHighlight(){
    return this->specular_highlight_;
}

/**
 * Sets the specular highlight color
 * 
 * @param specular_highlight Specular highlight color to set
 */
void PhongShader::setSpecularHighlight(RgbColor specular_highlight){
    this->specular_highlight_ = specular_highlight;
}

/**
 * Gets the reflective color
 * 
 * @return Shader Reflective Color
 */
RgbColor PhongShader::getReflectiveColor(){
    return this->reflective_color_;
}

/**
 * Sets the reflective color
 * 
 * @param reflective_color Reflective color to set
 */
void PhongShader::setReflectiveColor(RgbColor reflective_color){
    this->reflective_color_ = reflective_color;
}

/**
 * Gets the phong constant indicating the amount of specular reflection
 * 
 * @return Phong Constant
 */
int PhongShader::getPhongConstant(){
    return this->phong_constant_;
}

/**
 * Sets the phong constant that indicates the amount of specular reflection
 * 
 * @param phong_constant Phong Constant to set
 */
void PhongShader::setPhongConstant(int phong_constant){
    this->phong_constant_ = phong_constant;
}

/**
 * Gets the index of refraction
 * 
 * @return Index of Refraction
 */
double PhongShader::getRefractionIndex(){
    return this->refraction_index_;
}

/**
 * Sets the shader's index of refraction
 * 
 * @param refraction_index Refraction index to set
 */
void PhongShader::setRefractionIndex(double refraction_index){
    this->refraction_index_ = refraction_index;
}