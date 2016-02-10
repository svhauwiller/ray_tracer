// Ray Tracer: file_writer.h
// 
// Author: Wesley Hauwiller
//
// Description: A File Writer provides a template for all possible file output
//                  formats. Contains a method to initialize the file, add 
//                  content to the file, and to close the file.
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

#ifndef FILE_WRITER_H
#define	FILE_WRITER_H

#include <fstream>

class FileWriter{
public:
    virtual ~FileWriter();
    virtual void init() =0;
    virtual void addContent(std::string content) =0;
    virtual void close() =0;
protected:
    std::string filename_;
};

#endif	/* FILEWRITER_H */

