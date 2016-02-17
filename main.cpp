// Ray Tracer: main.cpp
//
// Author: Wesley Hauwiller
//
// Description: Central hub of a ray tracer. Renders a static scene of 
//                 spheres to a file named "output.ppm"
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

#include <iostream>
#include <stdexcept>
#include <vector>

#include "scene.h"
#include "ray_tracer.h"

#include "file_writer/ppm_writer.h"

#include "geo/sphere.h"

#include "shader/constant_shader.h"
#include "shader/phong_shader.h"

#include "light/ambient_light.h"
#include "light/directional_light.h"

using namespace std;

/**
 * Adds a list of static geometry to the scene
 * 
 * List of Geometry (2/2/2016)
 * 1: Sphere centered at (-0.6, 0, 0) with a radius of 0.3
 * 2: Sphere centered at (0.2, 0, 0) with a radius of 0.075
 * 3: Sphere centered at (0.35, 0, 0) with a radius of 0.05
 * 
 * @param scene Pointer to the scene description to be appended to
 */
void addGeometry(Scene* scene){

    PhongShader* shader1 = new PhongShader();
    Sphere* sphere1 = new Sphere(new Point3D(-0.6, 0, 0), 0.3, shader1);
    sphere1->setDiffuseColor(RgbColor(0, 255, 0));
    sphere1->setSpecularHighlight(RgbColor(255, 255, 255));
    sphere1->setPhongConstant(32);
    scene->addGeo(sphere1);
    
    PhongShader* shader2 = new PhongShader();
    Sphere* sphere2 = new Sphere(new Point3D(0.2, 0, -0.1), 0.075, shader2);
    sphere2->setDiffuseColor(RgbColor(255, 0, 0));
    sphere2->setSpecularHighlight(RgbColor(255, 255, 255));
    sphere2->setPhongConstant(32);
    scene->addGeo(sphere2);
    
    ConstantShader* shader3 = new ConstantShader();
    Sphere* sphere3 = new Sphere(new Point3D(0.35, 0, -0.1), 0.05, shader3);
    sphere3->setDiffuseColor(RgbColor(255, 255, 255));
    scene->addGeo(sphere3);
   
}

/**
 * Adds a list of lights to the scene
 * 
 * List of Lights (2/16/2016)
 * 1: Ambient Light with an 8-bit color of Dark Grey (25.5, 25.5, 25.5)
 * 2: Directional Light with an 8-bit color of Pure White (255, 255, 255) 
 *       directed down the negative X-axis (-1, 0, 0)
 * 3: Directional Light with an 8-bit color of Pure White (255, 255, 255) 
 *       directed down the negative Y-axis (0, -1, 0)
 * 
 * @param scene Pointer to the scene description to be appended to
 */
void addLights(Scene* scene){
    AmbientLight* ambient_light1 = new AmbientLight(RgbColor(25.5, 25.5, 25.5));
    scene->addLight(ambient_light1);

    DirectionalLight* directional_light1 = new DirectionalLight(RgbColor(255,255,255), new Vector3D(-1,0,0));
    scene->addLight(directional_light1);
    
    DirectionalLight* directional_light2 = new DirectionalLight(RgbColor(255,255,255), new Vector3D(0,-1,0));
    scene->addLight(directional_light2);
}

/**
 * Adds a Camera to the Scene
 * 
 * Camera Description (2/2/2016)
 * 
 * Origin: (0, 0, 1)
 * Focal Point: (0, 0, 0)
 * Angle of View: 56 degrees (28 degrees Field of View)
 * Image Result: 512px x 512px
 * 
 * @param scene
 */
void addCamera(Scene* scene){
    Camera* camera = new Camera();
    camera->setResolution(512, 512);
    camera->setOrigin(new Point3D(0,0,1));
    camera->setFocalParams(28.0, false);
    camera->setDistToImagePlane(1);
    scene->setCamera(camera);
}

int main(int argc, char** argv) {
 
    Scene* scene1 = new Scene();

    scene1->setBackgroundColor(RgbColor(51.2,51.2,51.2));
    addGeometry(scene1);
    addLights(scene1);
    addCamera(scene1);
    
    PpmWriter* output_writer = new PpmWriter("output.ppm");
    try {
        output_writer->init();
        output_writer->defineHeaders(scene1->getWidthResolution(), scene1->getHeightResolution(), 255);
    } catch ( const std::invalid_argument& error ) {
        std::cout << "Error (PpmWriter): " << error.what() << std::endl;
        delete scene1;
        delete output_writer;
        return 1;
    }

    RayTracer* ray_tracer = new RayTracer(scene1, output_writer);
    ray_tracer->run();
    
    delete ray_tracer;

    return 0;
}

