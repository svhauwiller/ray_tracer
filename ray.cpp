// Ray Tracer: ray.cpp
// 
// Author: Wesley Hauwiller
//
// Description: A Ray is a construct that defines a line originating from 
//                  a specific and extending infinitely in one direction.
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

#include "ray.h"

Ray::Ray(){
    this->origin_ = new Point3D(0,0,0);
    this->direction_ = new Vector3D(0,0,0);
}

Ray::Ray(Point3D* origin, Vector3D* direction){
    this->origin_ = origin;
    this->direction_ = direction;
}

Ray::~Ray(){
    delete this->origin_;
    delete this->direction_;
}

/**
 * Finds the point at the given distance along the ray
 * 
 * @param distance Distance to travel along the ray
 * @return Resulting Point in 3D space
 */
Point3D Ray::findPoint(double distance){
    this->direction_->normalize();
    //Vector3D n = (direction * distance);
    Vector3D* displacement_vector = new Vector3D(this->direction_->getX() * distance, this->direction_->getY() * distance, this->direction_->getZ() * distance);
    
    Point3D result_point = this->origin_->translate(displacement_vector);
    delete displacement_vector;
    return result_point;
}

/**
 * Gets the origin of the ray
 * 
 * @return Origin of the Ray
 */
Point3D* Ray::getOrigin(){
    return this->origin_;
}

/**
 * Sets the origin of the ray
 * 
 * @param origin Origin to be set
 */
void Ray::setOrigin(Point3D* origin){
    this->origin_ = origin;
}

/**
 * Gets the direction of the ray
 * 
 * @return Direction of the ray
 */
Vector3D* Ray::getDirection(){
    return this->direction_;
}

/**
 * Sets the direction of the ray
 * 
 * @param direction Direction to be set
 */
void Ray::setDirection(Vector3D* direction){
    this->direction_ = direction;
}

/**
 * Computes and returns the inverse direction of the ray
 * 
 * @return Inverse direction of the ray
 */
Vector3D Ray::getInverseDirection(){
    return Vector3D(-this->direction_->getX(), -this->direction_->getY(), -this->direction_->getZ());
}