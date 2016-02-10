// Ray Tracer: vector3d.cpp
// 
// Author: Wesley Hauwiller
//
// Description: A 3D Vector is a construct from mathematics that uses
//                 a set of 3 numbers to define a direction. It also
//                 defines a magitude based on the size of the numbers 
//                 that define its direction. It is considered "normalized"
//                 when the magnitude (or length) of the Vector is equal to 1.
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

#include "vector3d.h"

Vector3D::Vector3D(){
    this->x_ = 0.0;
    this->y_ = 0.0;
    this->z_ = 0.0;
}

Vector3D::Vector3D(double x, double y, double z){
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

/**
 * Change the vector's magnitude to 1 while maintaining the original direction
 */
void Vector3D::normalize(){
    double distance = magnitude();
    
    this->x_ = this->x_ / distance;
    this->y_ = this->y_ / distance;
    this->z_ = this->z_ / distance;
}

/**
 * Determine the length of the vector and return it
 * 
 * @return Length of the vector
 */
double Vector3D::magnitude(){
    return sqrt(this->x_ * this->x_ + this->y_ * this->y_ + this->z_ * this->z_);
}

/**
 * Compute the dot product between this vector and another vector
 * 
 * @param v Pointer to a vector to compute dot product with
 * @return Result of the dot product equation
 */
double Vector3D::dot(Vector3D* v){
    return this->x_ * v->getX() + this->y_ * v->getY() + this->z_ * v->getZ();
}

/**
 * Compute the cross product between this vector and another vector
 * 
 * @param v Vector to compute the cross product with
 * @return Result of the cross product equation
 */
Vector3D Vector3D::crossProd(Vector3D* v){
    double result_x = this->y_ * v->getZ() - this->z_ * v->getY();
    double result_y = this->z_ * v->getX() - this->x_ * v->getZ();
    double result_z = this->x_ * v->getY() - this->y_ * v->getX();
    return Vector3D(result_x, result_y, result_z);
}

Vector3D Vector3D::operator^(const int d){
   double result_x = pow(this->x_, d);
   double result_y = pow(this->y_, d);
   double result_z = pow(this->z_, d);
   return Vector3D(result_x, result_y, result_z); 
}

Vector3D Vector3D::operator*(const double d){
   double result_x = this->x_ * d;
   double result_y = this->y_ * d;
   double result_z = this->z_ * d;
   return Vector3D(result_x, result_y, result_z); 
}

Vector3D Vector3D::operator*(const Vector3D v){
   double result_x = this->x_ * v.getX();
   double result_y = this->y_ * v.getY();
   double result_z = this->z_ * v.getZ();
   return Vector3D(result_x, result_y, result_z); 
}

Vector3D Vector3D::operator+(const double d){
   double result_x = this->x_ + d;
   double result_y = this->y_ + d;
   double result_z = this->z_ + d;
   return Vector3D(result_x, result_y, result_z); 
}

Vector3D Vector3D::operator-(const double d){
   double result_x = this->x_ - d;
   double result_y = this->y_ - d;
   double result_z = this->z_ - d;
   return Vector3D(result_x, result_y, result_z); 
}

Vector3D Vector3D::operator-(const Vector3D v){
   double result_x = this->x_ - v.getX();
   double result_y = this->y_ - v.getY();
   double result_z = this->z_ - v.getZ();
   return Vector3D(result_x, result_y, result_z); 
}