// Ray Tracer: v3double.h
// 
// Author: Wesley Hauwiller
//
// Description: A set of three doubles used as a basis of many other constructs
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

#ifndef V3DOUBLE_H
#define V3DOUBLE_H

class V3double {
public:
    V3double();
    V3double(const V3double& orig);
    virtual ~V3double();
    
    double getX();
    double getX() const;
    void setX(double x);
    double getY();
    double getY() const;
    void setY(double y);
    double getZ();
    double getZ() const;
    void setZ(double z);
    
protected:
    double x_;
    double y_;
    double z_;
};

#endif /* V3DOUBLE_H */

