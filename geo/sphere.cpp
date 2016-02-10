// Ray Tracer: sphere.cpp
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


#include "sphere.h"

Sphere::Sphere(){
    this->center_ = new Point3D(0,0,0);
    this->radius_ = 1.0;
    
    PhongShader* default_shader = new PhongShader();
    this->shader_ = default_shader;
    setDiffuseColor(RgbColor(0,0,0));
    setSpecularHighlight(RgbColor(0,0,0));
    setPhongConstant(0);
    setReflectiveColor(RgbColor(0,0,0));
    setRefractionIndex(0.0);
}

Sphere::Sphere(Point3D* center, double radius, Shader* shader){
    this->center_ = center;
    this->radius_ = radius;
    this->shader_ = shader;
}

Sphere::~Sphere(){
    delete this->center_;
}

/**
 * Computes the point intersected and the normal at this point when a ray is cast. 
 * Point Hit and Normal Hit attributes are only modified if intersection is detected, otherwise
 * returns only false result 
 * 
 * To test intersection with a sphere, we locate the point along the ray closest
 * to the center of the sphere and compare it with the radius.
 * 
 * @param ray Ray to test intersection
 * @param pointHit Point hit by the ray, if intersection is detected
 * @param normalHit Normal of the surface at the point that is hit, if intersection is detected
 * @return Boolean indicating whether intersection was detected or not
 */
bool Sphere::hasIntersection(Ray* ray, Point3D* point_hit, Vector3D* normal_hit){
    //Geometric Solution
    
    //1. Generate a Vector going from the origin of the Ray to the center of the Sphere
    double vector_to_sphere_center_x = this->center_->getX() - ray->getOrigin()->getX();
    double vector_to_sphere_center_y = this->center_->getY() - ray->getOrigin()->getY();
    double vector_to_sphere_center_z = this->center_->getZ() - ray->getOrigin()->getZ();
    double distance_to_sphere_center = sqrt(vector_to_sphere_center_x * vector_to_sphere_center_x + 
                                            vector_to_sphere_center_y * vector_to_sphere_center_y + 
                                            vector_to_sphere_center_z * vector_to_sphere_center_z);
    
    //2. Compute the Dot Product of this vector and the original Ray
    //Note: This also the distance from the ray origin to a point that forms a right angle with the sphere center pt
    double distance_to_test_point = vector_to_sphere_center_x * ray->getDirection()->getX() + 
                                    vector_to_sphere_center_y * ray->getDirection()->getY() + 
                                    vector_to_sphere_center_z * ray->getDirection()->getZ();
    
    //3. Reject if the Sphere is not in the direction of the Ray (Dot Product is Negative)
    if(distance_to_test_point < 0){
        return false;
    }
    
    //4. Compute the distance to the closest point from the sphere center that exists along the ray by using the Pythagorean theorem
    //     along with the right triangle formed by the ray, the vector from the ray origin to the center, and the vector from the center to the closest pt on the ray
    double distance_from_sphere_center = sqrt(std::abs(distance_to_sphere_center * distance_to_sphere_center - distance_to_test_point * distance_to_test_point));
    
    //5. If this distance is greater than the radius, reject
    if(distance_from_sphere_center > this->radius_){
        return false;
    }
    
    //Compute the intersection pt and the normal
    
    //1. Find the amount of the ray penetrating the sphere up to the test point using the triangle formed by
    //     the radius and the distance to the closest pt on the sphere
    double penetration_amount = sqrt(this->radius_ * this->radius_ - distance_from_sphere_center * distance_from_sphere_center);
    
    //2. Subtract this distance from the distance from the origin to the closest pt on the ray to determine
    //      the distance from the origin to the intersection pt
    double distance_to_intersection = distance_to_test_point - penetration_amount;
    
    //3. Using parametric coordinates, find the point in 3D space where the sphere was intersected by the ray
    Point3D intersection_point = ray->findPoint(distance_to_intersection);
    
    //4. Return the intersection point and the normal at that point
    point_hit->setX(intersection_point.getX());
    point_hit->setY(intersection_point.getY());
    point_hit->setZ(intersection_point.getZ());
    
    Vector3D normal = getNormalAt(&intersection_point);
    normal_hit->setX(normal.getX());
    normal_hit->setY(normal.getY());
    normal_hit->setZ(normal.getZ());
    
    return true;
}

/**
 * Computes the normal at a given point on the sphere. The normal is
 * the vector between the center of the sphere and the given point
 * 
 * @param intersection_point Point on the sphere to query
 * @return Normal at the query point 
 */
Vector3D Sphere::getNormalAt(Point3D* intersection_point){
    double normal_x = intersection_point->getX() - this->center_->getX();
    double normal_y = intersection_point->getY() - this->center_->getY();
    double normal_z = intersection_point->getZ() - this->center_->getZ();
    
    double normalized_normal_x = normal_x / this->radius_;
    double normalized_normal_y = normal_y / this->radius_;
    double normalized_normal_z = normal_z / this->radius_;
    
    Vector3D normal (normalized_normal_x, normalized_normal_y, normalized_normal_z);
    
    return normal; 
}

/**
 * Get the point where the center of the sphere is located
 * 
 * @return Point at the center of the sphere
 */
Point3D* Sphere::getCenter(){
    return this->center_;
}

/**
 * Set the point where the sphere will be centered
 * 
 * @param center Point where the sphere will be centered
 */
void Sphere::setCenter(Point3D* center){
    this->center_ = center;
}

/**
 * Get the radius of the sphere
 * 
 * @return The radius of the sphere
 */
double Sphere::getRadius(){
    return this->radius_;
}

/**
 * Set the radius of the sphere
 * 
 * @param radius Radius to set to the sphere
 */
void Sphere::setRadius(double radius){
    this->radius_ = radius;
}
