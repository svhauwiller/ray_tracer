// Ray Tracer: ray.h
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

#ifndef RAY_H
#define	RAY_H

#include "math/point3d.h"
#include "math/vector3d.h"

class Ray{
public:
    Ray();
    Ray(Point3D* origin, Vector3D* direction);
    virtual ~Ray();
    
    Point3D findPoint(double distance);
    
    Point3D* getOrigin();
    void setOrigin(Point3D* origin);
    Vector3D* getDirection();
    void setDirection(Vector3D* direction);
    Vector3D getInverseDirection();
private:
    Point3D* origin_;
    Vector3D* direction_;
};

#endif	/* RAY_H */

