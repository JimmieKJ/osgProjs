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

#include <osgOde/Functions>

namespace osgOde{

    osg::Node* createBox(double lx, double ly, double lz)
    {
        osg::Box *shape = new osg::Box(osg::Vec3(0.0, 0.0, 0.0), lx, ly, lz);
        osg::Geode *geode = new osg::Geode;
        geode -> addDrawable(new osg::ShapeDrawable(shape));
        return geode;
    }

    void setTexture(osg::Node* node, const std::string& name)
    {
        osg::Texture2D *tex = new osg::Texture2D;
        tex -> setImage(osgDB::readImageFile(name));
        osg::StateSet *ss = new osg::StateSet;
        ss -> setTextureAttributeAndModes(0, tex, osg::StateAttribute::ON);
        node -> setStateSet(ss);
    }

}
