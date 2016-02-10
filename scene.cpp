// Ray Tracer: scene.cpp
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

#include "scene.h"

Scene::Scene() {
}

Scene::Scene(const Scene& orig) {

}

Scene::~Scene() {
    delete this->camera_;
    
    while(!this->geometry_list_.empty()){
        Geometry* geometry = this->geometry_list_.back();
        delete geometry;
        this->geometry_list_.pop_back();
    }
    
    while(!this->light_list_.empty()){
        Light* light = this->light_list_.back();
        delete light;
        this->light_list_.pop_back();
    }
}

/**
 * Sets the background color to return when the ray tracer does not intersect any geometry
 * 
 * @param background_color Background color of the scene to be set
 */
void Scene::setBackgroundColor(RgbColor background_color){
    this->background_color_ = background_color;
}

/**
 * Gets the background color to display when the ray tracer does not intersect any geometry
 * 
 * @return Background color to display
 */
RgbColor Scene::getBackgroundColor(){
    return this->background_color_;
}

/**
 * Set the projection parameters of the scene defined as a Camera object
 * 
 * @param camera Projection parameters to set
 */
void Scene::setCamera(Camera* camera){
    this->camera_ = camera;
}

/**
 * Gets the origin of the camera
 * 
 * @return Origin of the camera
 */
Point3D* Scene::getCameraOrigin(){
    return this->camera_->getOrigin();
}

/**
 * Gets the width resolution of the resulting image
 * 
 * @return Width resolution of the resulting image
 */
int Scene::getWidthResolution(){
    return this->camera_->getWidthResolution();
}

/**
 * Gets the height resolution of the resulting image
 * 
 * @return Height resolution of the resulting image
 */
int Scene::getHeightResolution(){
    return this->camera_->getHeightResolution();
}

/**
 * Gets the distance between the camera and the image projection plane in 3D space
 * 
 * @return Distance between the camera and the image plane
 */
double Scene::getDistToImagePlane(){
    return this->camera_->getDistToImagePlane();
}

/**
 * Gets the field of view in radians
 * 
 * @return Field of view in radians
 */
double Scene::getCameraFieldOfView(){
    return this->camera_->getFieldOfView();
}

/**
 * Adds a Geometry description to the scene to be rendered
 * 
 * @param geometry Pointer to a geometry description
 */
void Scene::addGeo(Geometry* geometry){
    this->geometry_list_.push_back(geometry);
}

/**
 * Retrieves the geometry description at the given index
 * 
 * @param index Index to retrieve the geometry description from
 * @return Geometry description at the given index
 */
Geometry* Scene::getGeoAt(int index){
    return this->geometry_list_.at(index);
}

/**
 * Gets the amount of Geometry objects defined in the scene
 * 
 * @return Amount of Geometry objects defined in the scene
 */
int Scene::getGeoListSize(){
    return this->geometry_list_.size();
}

/**
 * Adds a light description to the scene
 * 
 * @param light Light description to add
 */
void Scene::addLight(Light* light){
    this->light_list_.push_back(light);
}

/**
 * Retrieves the light description at the given index
 * 
 * @param index Index to retrieve the description from
 * @return Light description at the given index
 */
Light* Scene::getLightAt(int index){
    return this->light_list_.at(index);
}

/**
 * Gets the amount of Light objects defined in the scene
 * 
 * @return Amount of Light objects defined in the scene
 */
int Scene::getLightListSize(){
    return this->light_list_.size();
}