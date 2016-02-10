// Ray Tracer: geometry.h
// 
// Author: Wesley Hauwiller
//
// Description: The geometry provides a template for all possible objects
//                to be rendered in the scene. Contains a shader to store
//                color data and a method used by a Ray to test for intersection.
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


#ifndef GEOMETRY_H
#define	GEOMETRY_H


#include "../ray.h"
#include "../shader/shader.h"
#include "../math/point3d.h"
#include "../math/vector3d.h"

class Geometry{
public:
    Geometry();
    virtual ~Geometry();
    
    void initShader(Shader* shader);
    
    virtual bool hasIntersection(Ray* ray, Point3D* point_hit, Vector3D* normal_hit) = 0;
    int getShaderType();
    bool hasReflection();
    bool hasRefraction();
    
    RgbColor getDiffuseColor();
    void setDiffuseColor(RgbColor diffuse_color);
    RgbColor getSpecularHighlight();
    void setSpecularHighlight(RgbColor specular_highlight);
    int getPhongConstant();
    void setPhongConstant(int phong_constant);
    RgbColor getReflectiveColor();
    void setReflectiveColor(RgbColor reflective_color);
    double getRefractionIndex();
    void setRefractionIndex(double refraction_index);
    
protected:
    Shader* shader_;

};

#endif	/* GEOMETRY_H */

