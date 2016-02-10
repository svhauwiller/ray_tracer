// Ray Tracer: sphere.h
// 
// Author: Wesley Hauwiller
//
// Description: A Sphere is a perfectly round Geometry defined only by a center
//                 point and a radius
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

#ifndef SPHERE_H
#define	SPHERE_H

#include "geometry.h"
#include "../shader/phong_shader.h"

class Sphere: public Geometry{
    public:
        Sphere();
        Sphere(Point3D* center, double radius, Shader* shader);
        virtual ~Sphere();
        
        bool hasIntersection(Ray* ray, Point3D* point_hit, Vector3D* normal_hit);
        Vector3D getNormalAt(Point3D* intersection_point);
        
        Point3D* getCenter();
        void setCenter(Point3D* center);
        double getRadius();
        void setRadius(double radius);
        
    private:
        Point3D* center_;
        double radius_;
};


#endif	/* SPHERE_H */

