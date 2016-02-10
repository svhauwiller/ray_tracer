// Ray Tracer: ppm_writer.h
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

#ifndef PPM_WRITER_H
#define	PPM_WRITER_H

#include <fstream>
#include <stdexcept>

#include "file_writer.h"

class PpmWriter: public FileWriter{
public:
    PpmWriter();
    PpmWriter(std::string filename);
    virtual ~PpmWriter();
    void init();
    void defineHeaders(int image_width, int image_height, int max_color);
    void addContent(std::string content);
    void close();
private:
            
};


#endif	/* PPMWRITER_H */

