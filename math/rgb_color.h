// Ray Tracer: rgb_color.h
// 
// Author: Wesley Hauwiller
//
// Description: An RGB Color uses a set of 3 numbers to define a color's 
//              red, green, and blue components respectively
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

#ifndef RGB_COLOR_H
#define	RGB_COLOR_H

#include <cmath>

#include "v3double.h"

class RgbColor: public V3double{
public:
    RgbColor();
    RgbColor(double red, double green, double blue);
    
    bool isBlack();
    double getRed();
    double getRed() const;
    double getGreen();
    double getGreen() const;
    double getBlue();
    double getBlue() const;
    
    void correctOverflow();
    
    RgbColor operator^(const int i);
    RgbColor operator*(const double d);
    RgbColor operator+(const RgbColor& c);
    RgbColor operator*(const RgbColor& c);
private:
    
};

#endif	/* RGB_COLOR_H */

