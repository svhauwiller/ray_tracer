// Ray Tracer: vector3d.h
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

#ifndef VECTOR3D_H
#define	VECTOR3D_H

#include <cmath>

#include "v3double.h"

class Vector3D: public V3double{
public:
    Vector3D();
    Vector3D(double x, double y, double z);
    
    void normalize();
    double magnitude();
    double dot(Vector3D* v);
    Vector3D crossProd(Vector3D* v);
 
    Vector3D operator^(const int d);
    Vector3D operator*(const double d);
    Vector3D operator*(const Vector3D v);
    Vector3D operator+(const double d);
    Vector3D operator-(const double d);
    Vector3D operator-(const Vector3D v);
private:
    
};

#endif	/* VECTOR3D_H */

