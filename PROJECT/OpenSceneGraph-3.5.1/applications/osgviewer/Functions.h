/*  Copyright 2006, 2007, 2008 Juan Pablo Reyes Altamirano,
 *  Renato Leriche Vázquez, Dirección General de Servicios de
 *  Cómputo Académico de la Universidad Autónoma Nacional de México

 *  This file is part of osgODE.

 *  osgODE is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation, either version 3 of
 *  the License, or (at your option) any later version.

 *  osgODE is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.

 *  You should have received a copy of the GNU Lesser General
 *  Public License along with osgODE.  If not, see
 *  <http://www.gnu.org/licenses/>. */

#ifndef _OSGODE_FUNCTIONS_
#define _OSGODE_FUNCTIONS_

#include <osg/Node>
#include <osg/Geode>
#include <osg/ShapeDrawable>
#include <osg/Texture2D>
#include <osgDB/ReadFile>

namespace osgOde
{

    // osgOde Functions

    // Create a Simple OpenSceneGraph Box
    osg::Node* createBox(double, double, double);
    // Texturize any osgODE node
    void setTexture(osg::Node*, const std::string&);
}

#endif
