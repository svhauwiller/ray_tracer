// Ray Tracer: camera.cpp
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

#include "camera.h"

Camera::Camera() {
    this->type_ = 0;
    this->origin_ = new Point3D(0,0,0);
    this->image_width_ = 512;
    this->image_height_ = 512;
    this->field_of_view_ = 22.5 * (M_PI/180);
    this->distance_to_image_plane_ = 1;
    this->near_clip_plane_ = 0.1;
    this->far_clip_plane_ = 10000;
}

Camera::Camera(const Camera& orig) {
    
}

Camera::~Camera() {
    delete this->origin_;
}

/**
 * Sets a flag determining the type of camera
 * 
 * Current Available Flags (2/2/2016)
 * 0: Perspective
 * 1: Orthographic
 * 
 * @param type Flag to set
 */
void Camera::setType(int type){
    this->type_ = type;
}

/**
 * Sets the camera position in 3D space
 * 
 * @param origin Pointer to the point the camera is positioned at
 */
void Camera::setOrigin(Point3D* origin){
    this->origin_ = origin;
}

/**
 * Sets the resolution of the resulting image
 * 
 * @param image_width Resulting image width in pixels
 * @param image_height Resulting image height in pixels
 */
void Camera::setResolution(int image_width, int image_height){
    this->image_width_ = image_width;
    this->image_height_ = image_height;
}

/**
 * Sets field of view. The field of view is considered to be the angle between
 * an imaginary ray cast from the camera to the center of the image plane and
 * a ray cast from the camera to the edge of the image plane (half the angle of view)
 * Format of the angle must be specified, whether in radians or degrees.
 * (Internally it is stored as radians)
 * 
 * @param field_of_view Field of view in degrees
 * @param radians Flad indicating whether angle is given in radians or degrees
 */
void Camera::setFocalParams(double field_of_view, bool radians){
    if(!radians){    
        this->field_of_view_ = field_of_view * (M_PI/180);
    } else {
        this->field_of_view_ = field_of_view;
    }
}

/**
 * Sets the distance between the origin of the camera and the point 
 * where the camera will be focused for generating the image
 * 
 * @param distance Distance between the origin and image plane
 */
void Camera::setDistToImagePlane(double distance){
    this->distance_to_image_plane_ = distance;
}

/**
 * Sets the plane positions in defining the front and back of 
 * the camera frustum for culling geometry
 * 
 * @param near_plane Geometry in front of this position will be culled
 * @param far_plane Geometry behind this position will be culled
 */
void Camera::setClipPlanes(float near_plane, float far_plane){
    this->near_clip_plane_ = near_plane;
    this->far_clip_plane_ = far_plane;
}

/**
 * Gets the camera position in 3D space
 * 
 * @return Pointer to the point the camera is positioned at
 */
Point3D* Camera::getOrigin(){
    return this->origin_;
}

/**
 * Gets the width resolution of the resulting image 
 * 
 * @return The width resolution of the resulting image
 */
int Camera::getWidthResolution(){
    return this->image_width_;
}

/**
 * Gets the height resolution of the resulting image
 * 
 * @return The height resolution of the resulting image
 */
int Camera::getHeightResolution(){
    return this->image_height_;
}

/**
 * Gets the distance between the origin of the camera and the point 
 * where the camera will be focused for generating the image
 * 
 * @return Distance between the origin and image plane
 */
double Camera::getDistToImagePlane(){
    return this->distance_to_image_plane_;
}

/**
 * Gets the field of view in radians
 * 
 * @return The field of view in radians
 */
double Camera::getFieldOfView(){
    return this->field_of_view_;
}