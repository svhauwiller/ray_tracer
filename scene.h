// Ray Tracer: scene.h
// 
// Author: Wesley Hauwiller
//
// Description: A Scene contains a description of all the geometry, lights, 
//                   and projection settings for the image
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

#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "camera.h"

#include "geo/geometry.h"

#include "light/light.h"

#include "math/rgb_color.h"
#include "math/point3d.h"

class Scene {
public:
    Scene();
    Scene(const Scene& orig);
    virtual ~Scene();
    
    void setBackgroundColor(RgbColor background_color);
    RgbColor getBackgroundColor();
    
    void setCamera(Camera* camera);
    Point3D* getCameraOrigin();
    int getWidthResolution();
    int getHeightResolution();
    double getDistToImagePlane();
    double getCameraFieldOfView();
    
    void addGeo(Geometry* geometry);
    Geometry* getGeoAt(int index);
    int getGeoListSize();
    
    void addLight(Light* light);
    Light* getLightAt(int index);
    int getLightListSize();
    
private:
    RgbColor background_color_;
    Camera* camera_;
    std::vector<Geometry*> geometry_list_;
    std::vector<Light*> light_list_;
};

#endif /* SCENE_H */

