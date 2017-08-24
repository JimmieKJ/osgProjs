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

#ifndef _OSGODE_WORLD_
#define _OSGODE_WORLD_

#include <osg/Group>
#include <osg/Timer>
#include <osgOde.h>

namespace osgOde{

    class World : public osg::Group
    {
        public:
            // Ode World identifier
            dWorldID ode_world;
            // Ode Space identifier
            dSpaceID ode_space;
            // Constructor
            World();
            // Set Ode World Gravity
            void setGravity(double, double, double);
            // Node traversing in the world
            virtual void traverse(osg::NodeVisitor &);
            dJointGroupID contact_group;

        protected:
            //Destructor
            ~World();
        private:

            // Timer (so that our animation is not limited to cpu speed)
            osg::Timer timer;
            osg::Timer_t time;
            // This Function establishes the contact points between two Geometries so as to define how they would react in collission with each other
            static void nearCallback(void*, dGeomID, dGeomID);
    };

}

#endif
