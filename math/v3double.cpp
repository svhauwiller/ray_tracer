// Ray Tracer: v3double.cpp
// 
// Author: Wesley Hauwiller
//
// Description: A set of three doubles used as a basis of many other constructs
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

#include "v3double.h"

V3double::V3double() {
}

V3double::V3double(const V3double& orig) {
    this->x_ = orig.getX();
    this->y_ = orig.getY();
    this->z_ = orig.getZ();
}

V3double::~V3double() {
}

/**
 * Gets the first number in the set
 * 
 * @return The first number in the set
 */
double V3double::getX(){
    return this->x_;
}

/**
 * Gets the first number in the set as a constant
 * 
 * @return Constant version of the first number in the set
 */
double V3double::getX() const {
    return this->x_;
}

/**
 * Set the first number in the set
 * 
 * @param x Number to be set in the first position
 */
void V3double::setX(double x){
    this->x_ = x;
}

/**
 * Gets the second number in the set
 * 
 * @return The second number in the set
 */
double V3double::getY(){
    return this->y_;
}

/**
 * Gets the second number in the set as a constant
 * 
 * @return Constant version of the second number in the set
 */
double V3double::getY() const {
    return this->y_;
}

/**
 * Sets the second number in the set
 * 
 * @param y Number to be set in the second position
 */
void V3double::setY(double y){
    this->y_ = y;
}

/**
 * Gets the third number in the set
 * 
 * @return The third number in the set
 */
double V3double::getZ(){
    return this->z_;
}

/**
 * Gets the third number in the set as a constant
 * 
 * @return Constant version of the third number in the set
 */
double V3double::getZ() const {
    return this->z_;
}

/**
 * Sets the third number in the set
 * 
 * @param z Number to be set in the third position
 */
void V3double::setZ(double z){
    this->z_ = z;
}

