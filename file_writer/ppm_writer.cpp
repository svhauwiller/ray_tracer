// Ray Tracer: ppm_writer.cpp
// 
// Author: Wesley Hauwiller
//
// Description: A PPM Writer generates an ASCII formated Portable Pixel Map
//                  file (.ppm). Conforms to the following specification (see
//                  <http://people.sc.fsu.edu/~jburkardt/data/ppma/ppma.html> 
//                  for details):
//              
//              - A "magic number" for identifying the file type. 
//                  (An ASCII PPM file's magic number is the two characters "P3")
//              - NEW LINE.
//              - A width, formatted as ASCII characters in decimal.
//              - Whitespace.
//              - A height, again in ASCII decimal.
//              - NEW LINE.
//              - The maximum color-component value, again in ASCII decimal.
//              - NEW LINE.
//              - Width * height pixels, each three ASCII decimal values between 
//                   0 and the specified maximum value, starting at the top-left 
//                   corner of the pixmap, proceeding in normal English reading 
//                   order. The three values for each pixel represent red, green, 
//                   and blue, respectively; a value of 0 means that color is off, 
//                   and the maximum value means that color is maxed out.
//         
// Example Output:
//        P3
//        4 4
//        15
//         0  0  0  0  0  0    0  0  0   15  0 15
//         0  0  0  0 15  7    0  0  0    0  0  0
//         0  0  0  0  0  0    0 15  7    0  0  0
//        15  0 15  0  0  0    0  0  0    0  0  0
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

#include "ppm_writer.h"

PpmWriter::PpmWriter(){
    this->filename_ = "PPM_File.ppm";
}

PpmWriter::PpmWriter(std::string filename){
    this->filename_ = filename;
}

PpmWriter::~PpmWriter(){}

/**
 * Create PPM file with the filename assigned in the constructor.
 * Create an internal header to define it as an ASCII PPM file.
 */
void PpmWriter::init(){
    std::ofstream output_file;
    output_file.open(this->filename_.c_str());
    output_file.close();
}

/**
 * Set the headers required by the ASCII PPM file specifications to specify the 
 * file as an ASCII PPM file type and define the image width, image height, and 
 * maximum color value (color value to be considered white) Maximum color value 
 * must be less than 65536 and more than zero.
 * 
 * @param image_width Image width in pixels
 * @param image_height Image height in pixels
 * @param max_color Maximum color value (1-65535)
 */
void PpmWriter::defineHeaders(int image_width, int image_height, int max_color){
    
    //Keep the maximum color within bounds
    if(max_color <= 0 || max_color >= 65536){
        throw std::invalid_argument("Maximum color value must be less than 65536 and more than zero.");
    }
    
    std::ofstream output_file;
    output_file.open(this->filename_.c_str(), std::ios_base::app);
    output_file << "P3" << std::endl; //A "magic number" identifying the file type. An ASCII PPM image's magic number is "P3".
    output_file << image_width << " " << image_height << std::endl; //[Width] Whitespace [Height] in ASCII decimal
    output_file << max_color << std::endl; //The maximum color value in ASCII decimal
    output_file.close();
}

/**
 * Add any additional content to the file. This is typically used to add the
 * pixel color map data to the interior of the file.
 * 
 * @param content Text to add to the PPM file
 */
void PpmWriter::addContent(std::string content){
    std::ofstream output_file;
    output_file.open(this->filename_.c_str(), std::ios_base::app);
    output_file << content;
    output_file.close();
}

/**
 * Implementation of the close function. 
 * PPM does have specifcations for footers, so this fucntion is a No-Op
 */
void PpmWriter::close(){
    return;
}
