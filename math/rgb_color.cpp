// Ray Tracer: rgb_color.cpp
// 
// Author: Wesley Hauwiller
//
// Description: An RGB Color uses a set of 3 numbers to define a color's 
//              red, green, and blue components respectively
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

#include "rgb_color.h"

RgbColor::RgbColor(){
    this->x_ = 0.0;
    this->y_ = 0.0;
    this->z_ = 0.0;
}

RgbColor::RgbColor(double red, double green, double blue){
    this->x_ = red;
    this->y_ = green;
    this->z_ = blue;
}

/**
 * Determine if all components of the the color are 0
 * 
 * @return Result of the check
 */
bool RgbColor::isBlack(){
    if(this->x_ != 0.0){
        return false;
    }
    if(this->y_ != 0.0){
        return false;
    }
    if(this->z_ != 0.0){
        return false;
    }
    return true;
}

/**
 * Gets the Red component of the color
 * 
 * @return The Red component of the color
 */
double RgbColor::getRed(){
    return this->x_;
}

/**
 * Gets the Red component of the color as a constant
 * 
 * @return Constant version of the Red component
 */
double RgbColor::getRed() const{
    return this->x_;
}

/**
 * Gets the Green component of the color 
 * 
 * @return The Green component of the color
 */
double RgbColor::getGreen(){
    return this->y_;
}

/**
 * Gets the Green component of the color as a constant
 * 
 * @return Constant version of the Green component
 */
double RgbColor::getGreen() const{
    return this->y_;
}

/**
 * Gets the Blue component of the color
 * 
 * @return The Blue component of the color
 */
double RgbColor::getBlue(){
    return this->z_;
}

/**
 * Gets the Blue component of the color as a constant
 * 
 * @return Constant version of the Blue component
 */
double RgbColor::getBlue() const{
    return this->z_;
}

/**
 * Clips the internal color values at the maximum color allowed 
 * so the color data does not overflow
 */
void RgbColor::correctOverflow(){
    this->x_ = this->x_ > 255 ? 255 : this->x_;
    this->y_ = this->y_ > 255 ? 255 : this->y_;
    this->z_ = this->z_ > 255 ? 255 : this->z_;  
}

RgbColor RgbColor::operator^(const int i){
   double result_red = pow((this->x_/255), i) * 255;
   double result_green = pow((this->y_/255), i) * 255;
   double result_blue = pow((this->z_/255), i) * 255;
   return RgbColor(result_red, result_green, result_blue); 
}

RgbColor RgbColor::operator*(const double d)
{
   double result_red = ((this->x_/255) * d) * 255;
   double result_green = ((this->y_/255) * d) * 255;
   double result_blue = ((this->z_/255) * d) * 255;
   return RgbColor(result_red, result_green, result_blue);
}

RgbColor RgbColor::operator+(const RgbColor& c)
{
   double result_red = this->x_ + c.getRed();
   double result_green = this->y_ + c.getGreen();
   double result_blue = this->z_ + c.getBlue();
   return RgbColor(result_red, result_green, result_blue);
}

RgbColor RgbColor::operator*(const RgbColor& c)
{
   double result_red = (this->x_/255) * (c.getRed()/255) * 255;
   double result_green = (this->y_/255) * (c.getGreen()/255) * 255;
   double result_blue = (this->z_/255) * (c.getBlue()/255) * 255;
   return RgbColor(result_red, result_green, result_blue);
}