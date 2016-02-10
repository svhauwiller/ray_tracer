// Ray Tracer: ray_tracer.h
// 
// Author: Wesley Hauwiller
//
// Description: Backbone of the Ray Tracer. Takes a scene description 
//                  and file output writer and generates the color data 
//                  for each pixel in the image by casting a ray though 
//                  the center of each pixel in the image plane and 
//                  returning the color data of the closest geometry 
//                  it intersects.
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

#ifndef RAY_TRACER_H
#define	RAY_TRACER_H

#include <cfloat>
#include <iostream>
#include <sstream>
#include <vector>

#include "scene.h"
#include "ray.h"

#include "file_writer/file_writer.h"

#include "light/directional_light.h"
#include "light/light.h"

#include "geo/geometry.h"

#include "math/rgb_color.h"
#include "math/point3d.h"
#include "math/vector3d.h"

class RayTracer{
public:
    RayTracer();
    RayTracer(Scene* scene, FileWriter* file_writer);
    ~RayTracer();
    
    void run();
    
    void normalizeAndCenterPixel(double &x, double &y);
    void convertToScreenSpace(double &x, double &y);
    void convertToCameraSpace(double &x, double &y);
    Ray* generatePrimaryRay(double x, double y);
    
    Geometry* computeNearestIntersection(Ray* ray, Point3D* nearest_point, Vector3D* normal_at_nearest_point);
    bool computeShadowRay(Point3D* nearest_point);
    RgbColor computePhongLightingModel(Geometry* nearest_geometry, Ray* ray, Vector3D* normal_at_nearest_point, bool shadow_mask);
    RgbColor trace(Ray* ray, int depth);
    
private:
    Scene* scene_;
    FileWriter* file_writer_;
};

#endif	/* RAYTRACER_H */

