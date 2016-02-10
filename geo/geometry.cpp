// Ray Tracer: geometry.cpp
// 
// Author: Wesley Hauwiller
//
// Description: The Geometry provides a template for all possible objects
//                to be rendered in the scene. Contains a shader to store
//                color data and a method used by a Ray to test for intersection. 
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

#include "geometry.h"

Geometry::Geometry(){}

Geometry::~Geometry(){
    delete this->shader_;
}

/**
 * Adds a shader to the geometry to describe 
 * the color data for rendering
 * 
 * @param shader Shader to contain the Geometry's color data
 */
void Geometry::initShader(Shader* shader){
    this->shader_ = shader;
}

/**
 * Returns an integer identifying the type of shader
 * 
 * Shader Number List (2/2/2016)
 * 0: Constant
 * 1: Phong
 * 
 * @return Integer identifying the type of shader
 */
int Geometry::getShaderType(){
    return this->shader_->getType();
}

/**
 * Queries the shader to see whether it has reflection or not
 * 
 * @return Boolean indicating presence of reflection in the shader
 */
bool Geometry::hasReflection(){
    return this->shader_->hasReflection();
}

/**
 * Queries the shader to see whether it has refraction or not
 * 
 * @return Boolean indicating presence of refraction in the shader
 */
bool Geometry::hasRefraction(){
    return this->shader_->hasRefraction();
}

/**
 * Gets the shader's diffuse color
 * 
 * @return Shader diffuse color 
 */
RgbColor Geometry::getDiffuseColor(){
    return this->shader_->getDiffuseColor();
}

/**
 * Sets the shader's diffuse color
 * 
 * @param diffuse_color Diffuse color to set
 */
void Geometry::setDiffuseColor(RgbColor diffuse_color){
    this->shader_->setDiffuseColor(diffuse_color);
}

/**
 * Gets the shader's specular highlight color 
 * 
 * @return Shader specular highlight color
 */
RgbColor Geometry::getSpecularHighlight(){
    return this->shader_->getSpecularHighlight();
}

/**
 * Sets the shader's specular highlight color
 * 
 * @param specular_highlight Specular highlight color to set
 */
void Geometry::setSpecularHighlight(RgbColor specular_highlight){
    this->shader_->setSpecularHighlight(specular_highlight);
}

/**
 * Gets the shader's phong constant indicating the amount of specular reflection
 * 
 * @return Shader Phong Constant
 */
int Geometry::getPhongConstant(){
    return this->shader_->getPhongConstant();
}

/**
 * Sets the shader's phong constant that indicates the amount of specular reflection
 * 
 * @param phong_constant Phong Constant to set 
 */
void Geometry::setPhongConstant(int phong_constant){
    this->shader_->setPhongConstant(phong_constant);
}

/**
 * Gets the shader's reflective color
 * 
 * @return Shader Reflective Color
 */
RgbColor Geometry::getReflectiveColor(){
    return this->shader_->getReflectiveColor();
}

/**
 * Sets the shader's reflective color
 * 
 * @param reflective_color Reflective color to set
 */
void Geometry::setReflectiveColor(RgbColor reflective_color){
    this->shader_->setReflectiveColor(reflective_color);
}

/**
 * Gets the shader's index of refraction
 * 
 * @return Shader's Index of Refraction
 */
double Geometry::getRefractionIndex(){
    return this->shader_->getRefractionIndex();
}

/**
 * Sets the shader's index of refraction
 * 
 * @param refraction_index Refraction index to set
 */
void Geometry::setRefractionIndex(double refraction_index){
    this->shader_->setRefractionIndex(refraction_index);
}
