// Ray Tracer: point3d.h
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

#ifndef POINT3D_H
#define	POINT3D_H

#include "v3double.h"
#include "vector3d.h"

class Point3D : public V3double{
public:
    Point3D();
    Point3D(double x, double y, double z);
    
    Point3D translate(Vector3D* displacement_vector);
    Vector3D computeDirection(Point3D* target, bool normalize);
    float computeDistance(Point3D* target);
    
    Point3D operator+(const Point3D& p);
    Point3D operator*(const double d);
private:
    
};

#endif	/* POINT3D_H */

