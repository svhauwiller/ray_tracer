// Ray Tracer: camera.h
// 
// Author: Wesley Hauwiller
//
// Description: The camera defines the parameters for projecting the 
//                3D scene onto an image plane
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

#ifndef CAMERA_H
#define CAMERA_H

#include <cmath>

#include "math/point3d.h"

class Camera {
public:
    Camera();
    Camera(const Camera& orig);
    virtual ~Camera();
    
    void setType(int type);
    void setOrigin(Point3D* origin);
    void setResolution(int image_width, int image_height);
    void setDistToImagePlane(double distance);
    void setFocalParams(double field_of_view, bool radians);
    void setClipPlanes(float near_plane, float far_plane);
    
    Point3D* getOrigin();
    int getWidthResolution();
    int getHeightResolution();
    double getDistToImagePlane();
    double getFieldOfView();
private:
    int type_;
    Point3D* origin_;
    int image_width_;
    int image_height_;
    double field_of_view_;
    double distance_to_image_plane_;
    float near_clip_plane_;
    float far_clip_plane_;
};

#endif /* CAMERA_H */

