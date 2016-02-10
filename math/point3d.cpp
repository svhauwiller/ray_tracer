// Ray Tracer: point3d.cpp
// 
// Author: Wesley Hauwiller
//
// Description: A 3D Point defines a point in 3D space using a set of 3 numbers.
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

#include "point3d.h"

Point3D::Point3D(){
    this->x_ = 0.0;
    this->y_ = 0.0;
    this->z_ = 0.0;
}

Point3D::Point3D(double x, double y, double z){
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

/**
 * Moves the point by the direction and the amount specified by the
 * displacement vector given and returns the result
 * 
 * @param displacement_vector Vector specifying direction and amount of translation
 * @return Resulting Point in 3D space
 */
Point3D Point3D::translate(Vector3D* displacement_vector)
{
   double result_x = this->x_ + displacement_vector->getX();
   double result_y = this->y_ + displacement_vector->getY();
   double result_z = this->z_ + displacement_vector->getZ();
   return Point3D(result_x, result_y, result_z);
}

/**
 * Computes a direction between two points and returns the result as
 * a vector (optionally normalized).
 * 
 * @param target End point of the resulting vector
 * @param normalize Flag to signal whether the resulting vector should be normalized
 * @return Resulting direction expressed as a vector
 */
Vector3D Point3D::computeDirection(Point3D* target, bool normalize){
    double result_x = target->getX() - this->x_;
    double result_y = target->getY() - this->y_;
    double result_z = target->getZ() - this->z_;
    Vector3D direction_vector(result_x, result_y, result_z);
    if(normalize){
        direction_vector.normalize();
    } 
    return direction_vector;
}

/**
 * Computes the distance from the Point to a given target Point
 * 
 * @param target Target point in 3D space
 * @return Resulting distance between two points
 */
float Point3D::computeDistance(Point3D* target){
    double result_x = target->getX() - this->x_;
    double result_y = target->getY() - this->y_;
    double result_z = target->getZ() - this->z_;
    return (float) sqrt(result_x * result_x + result_y * result_y + result_z * result_z);
}

Point3D Point3D::operator+(const Point3D& p)
{
   double result_x = this->x_ + p.getX();
   double result_y = this->y_ + p.getY();
   double result_z = this->z_ + p.getZ();
   return Point3D(result_x, result_y, result_z);
}

Point3D Point3D::operator *(const double d){
   double result_x = this->x_ + d;
   double result_y = this->y_ + d;
   double result_z = this->z_ + d;
   return Point3D(result_x, result_y, result_z); 
}
