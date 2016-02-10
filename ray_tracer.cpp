// Ray Tracer: ray_tracer.cpp
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

#include "ray_tracer.h"

#define MAX_RAY_DEPTH 3
 

RayTracer::RayTracer(){}

RayTracer::RayTracer(Scene* scene, FileWriter* file_writer){
    this->scene_ = scene;
    this->file_writer_ = file_writer;
}

RayTracer::~RayTracer(){
    delete this->scene_;
    delete this->file_writer_;
}

/**
 * Iterates over each pixel in the image. Casts a ray through the center of the 
 * pixel on the focal plane, computes the color of the pixel using the ray, and 
 * writes the color data to the file writer
 */
void RayTracer::run(){
    std::stringstream color_datastream;
    for (int y = 0; y < this->scene_->getHeightResolution(); y++) {
        for (int x = 0; x < this->scene_->getWidthResolution(); x++) {
            Ray* primary_ray = generatePrimaryRay(x, y);
            RgbColor pixel_color = trace(primary_ray, 0);
            
            //Note: Output to the file is a give and take situation
            //We can write the image data to MEMORY and write to DISK with a fast computation time
            //We can write the image data to DISK at every pixel to save MEMORY, but slow down computation time
            //Write to MEMORY(512x512): 5s    Write to DISK(512x512): 1m 40s
            color_datastream << pixel_color.getRed() << ' ' << pixel_color.getGreen() << ' ' << pixel_color.getBlue() << "    ";
        }
        color_datastream << std::endl;
    }
    this->file_writer_->addContent(color_datastream.str());
}

/**
 * Normalizes the coordinate (scale between 0 and 1) and shifts it to center of pixel. 
 * This space is also known as Normalized Device Coordinate (NDC) space.
 * 
 * @param x X-coordinate of the pixel
 * @param y Y-coordinate of the pixel
 */
void RayTracer::normalizeAndCenterPixel(double &x, double &y){
    x = (x + 0.5) / this->scene_->getWidthResolution();
    y = (y + 0.5) / this->scene_->getHeightResolution();
}

/**
 * Transforms a coordinate in NDC space to screen space. 
 * (All the pixels are scaled between -1 and 1)
 * Then, the aspect ratio is applied adjusting the range of the x coordinate,
 * while leaving the y coordinate static.
 * 
 * @param x X-coordinate in NDC space
 * @param y Y-coordinate in NDC space
 */
void RayTracer::convertToScreenSpace(double &x, double &y){
    double aspect_ratio = this->scene_->getWidthResolution() / this->scene_->getHeightResolution();
    x = ((x * 2) - 1) * aspect_ratio;
    y = 1 - (y * 2);
}

/**
 * Transforms a coordinate in screen space to camera space. This applies 
 * the field of view and the distance to the focal plane to determine what 
 * area of the 3D scene is in frame.
 * 
 * @param x X-coordinate in screen space
 * @param y Y-coordinate in screen space
 */
void RayTracer::convertToCameraSpace(double &x, double &y){
    x = x * tan(this->scene_->getCameraFieldOfView()) * this->scene_->getDistToImagePlane();
    y = y * tan(this->scene_->getCameraFieldOfView()) * this->scene_->getDistToImagePlane();
}

/**
 * Compute the initial Ray that needs to be cast to determine the color data at the given pixel 
 * 
 * @param x X-coordinate of the pixel
 * @param y Y-coordinate of the pixel
 * @return Resulting ray
 */
Ray* RayTracer::generatePrimaryRay(double x, double y){
    
    normalizeAndCenterPixel(x, y);
    convertToScreenSpace(x, y);
    convertToCameraSpace(x, y);
    
    Point3D center_of_pixel (x, y, 0);
    Vector3D rayDirection = this->scene_->getCameraOrigin()->computeDirection(&center_of_pixel, true);
    
    return new Ray(new Point3D(this->scene_->getCameraOrigin()->getX(),
                               this->scene_->getCameraOrigin()->getY(),
                               this->scene_->getCameraOrigin()->getZ()),
                   new Vector3D(rayDirection.getX(),
                                rayDirection.getY(),
                                rayDirection.getZ()));
}

/**
 * Computes the geometry closest to the camera that the ray has collided with.
 * Also computes and returns the point in 3D space that was collided with and the
 * normal at that point, if applicable.
 * 
 * @param ray Ray to compute intersections with
 * @param nearest_point Point in 3D space that was collided with
 * @param normal_at_nearest_point Normal at the point collided with
 * @return Pointer to the Geometry object intersected
 */
Geometry* RayTracer::computeNearestIntersection(Ray* ray, Point3D* nearest_point, Vector3D* normal_at_nearest_point){
    Geometry* nearest_geometry = NULL;
    float nearest_intersection_distance = INFINITY;
    
    Point3D point_hit (0,0,0);
    Vector3D normal_hit (1,1,1);
    
    for (int i = 0; i < this->scene_->getGeoListSize(); i++) { 
        if (this->scene_->getGeoAt(i)->hasIntersection(ray, &point_hit, &normal_hit)) {
            float distance = ray->getOrigin()->computeDistance(&point_hit);
            if (distance < nearest_intersection_distance) { 
                nearest_geometry = this->scene_->getGeoAt(i);
                nearest_intersection_distance = distance;
    
                nearest_point->setX(point_hit.getX());
                nearest_point->setY(point_hit.getY());
                nearest_point->setZ(point_hit.getZ());
                
                normal_at_nearest_point->setX(normal_hit.getX());
                normal_at_nearest_point->setY(normal_hit.getY());
                normal_at_nearest_point->setZ(normal_hit.getZ());
            }
        }
    }
    
    return nearest_geometry;
}

/**
 * Generates a flag based on whether the point is in shadow or not.
 * 
 * @param nearest_point Point in 3D space to test
 * @return Flag determining if the point is in shadow or not
 */
bool RayTracer::computeShadowRay(Point3D* nearest_point){
    int shadow_flag = 0;
    
    Vector3D direction_to_light1 = this->scene_->getLightAt(1)->getDirectionToLight();
    Ray* shadow_ray = new Ray(new Point3D(nearest_point->getX() + (direction_to_light1.getX() * FLT_EPSILON), 
                                          nearest_point->getY() + (direction_to_light1.getY() * FLT_EPSILON), 
                                          nearest_point->getZ() + (direction_to_light1.getZ() * FLT_EPSILON)), 
                             new Vector3D(direction_to_light1.getX(), direction_to_light1.getY(), direction_to_light1.getZ()));
  
    Point3D point_hit_noop (0,0,0);
    Vector3D normal_hit_noop (1,1,1);
  
    for (int i = 0; i < this->scene_->getGeoListSize(); i++) {
        if (this->scene_->getGeoAt(i)->hasIntersection(shadow_ray, &point_hit_noop, &normal_hit_noop)) {
            shadow_flag = 1;
            break;
        }
    }
  
    delete shadow_ray;
    
    return shadow_flag;
}

/**
 * Computes the color of the pixel based on the Phong Lighting Model
 * <https://en.wikipedia.org/wiki/Phong_reflection_model>
 * 
 * Computes an ambient, diffuse, and specular component of the color using
 * shadow information four separate vectors:
 * 
 * 1. Surface Normal
 * 2. Direction to the Light Source
 * 3. Direction to the eye
 * 4. Reflection Direction
 * 
 * @param nearest_geometry Geometry object containing the color information
 * @param ray Ray being cast from the camera
 * @param normal_at_nearest_point Normal at the point intersected by the ray
 * @param shadow_mask A mask identifying which points appear in shadow. 1 is in shadow and 0 is not.
 * @return Color of the pixel
 */
RgbColor RayTracer::computePhongLightingModel(Geometry* nearest_geometry, Ray* ray, Vector3D* normal_at_nearest_point, bool shadow_mask){
    RgbColor ambient_light_color(0,0,0);
    for (int i = 0; i < this->scene_->getLightListSize(); i++) {
        if(this->scene_->getLightAt(i)->getType() == 0){ //Is Ambient
            ambient_light_color = ambient_light_color + this->scene_->getLightAt(i)->getColor();  
        }
    }

    Vector3D direction_to_light1 = this->scene_->getLightAt(1)->getDirectionToLight();
    
    double a = std::max(0.0, normal_at_nearest_point->dot(&direction_to_light1));
    Vector3D reflection_direction = ((*normal_at_nearest_point * 2) * a) - direction_to_light1;
    Vector3D direction_to_eye = ray->getInverseDirection();
    double b = std::max(0.0, direction_to_eye.dot(&reflection_direction));

    RgbColor ambient_color = (nearest_geometry->getDiffuseColor() * ambient_light_color); 
    RgbColor diffuse_color = (this->scene_->getLightAt(1)->getColor() * (nearest_geometry->getDiffuseColor() * a)) * !shadow_mask;
    RgbColor specular_color = (this->scene_->getLightAt(1)->getColor() * ((nearest_geometry->getSpecularHighlight() * b) ^ nearest_geometry->getPhongConstant())) * !shadow_mask;
    
    return ambient_color + diffuse_color + specular_color;
}

/**
 * Computes the color data of the pixel based on the ray cast
 * 
 * @param ray Ray to compute intersections and color data by
 * @param depth Maximum number of additional rays that may be cast by this ray
 * @return Color data of the pixel
 */
RgbColor RayTracer::trace(Ray* ray, int depth)
{
    Point3D nearest_point (0,0,0);
    Vector3D normal_at_nearest_point (1,1,1);
    Geometry* nearest_geometry = computeNearestIntersection(ray, &nearest_point, &normal_at_nearest_point);
  
    if (nearest_geometry == NULL){
        delete ray;
        return this->scene_->getBackgroundColor();
    }
    
    bool shadow_flag = computeShadowRay(&nearest_point); 
    
    RgbColor pixel_color;
    switch(nearest_geometry->getShaderType()){
        case 0: //Constant Shader
            pixel_color = nearest_geometry->getDiffuseColor();
            break;
        case 1: //Phong Shader
            pixel_color = computePhongLightingModel(nearest_geometry, ray, &normal_at_nearest_point, shadow_flag);
            break;
    }
    pixel_color.correctOverflow();
    
    delete ray;

    return pixel_color;
} 