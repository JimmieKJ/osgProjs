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

#ifndef _OSGODE_GEOMETRY_
#define _OSGODE_GEOMETRY_

#include <osg/PositionAttitudeTransform>
#include <osg/ShapeDrawable>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Notify>

#include <osgOde.h>
#include <World.h>

namespace osgOde{

    class Geometry : public osg::PositionAttitudeTransform
    {
        public:

            // Ode Geometry identifier
            dGeomID ode_geom;
            // Constructor
            Geometry(){};
            // Method to destroy the identifier
            void destroy();

            // Establece y recupara datos del usuario dentro de la geometría.
            //void dGeomSetData(dGeomID, void *);
            //void *dGeomGetData(dGeomID);
            // Asocia la geometría con un cuerpo. (Ver Body.h, función setGeometry)
            //void dGeomSetBody(dGeomID, dBodyID);

            // Regresa el cuerpo asociado on esta geometría. (Ver World.h, función
            // nearCallback).
            //dBodyID dGeomGetBody(dGeomID);

            // Regresa la clase de esta geometría. Las posibilidades son dSphereClass,
            // dBoxClass, dCCylinderClass, dCylinderClass, dPlaneClass, dRayClass,
            // dGeomTransformClass, dTriMeshClass, dSimpleSpaceClass = dFirstSpaceClass,
            // dHashSpaceClass, dQuadTreeSpaceClass = dLastSpaceClass,
            // dFirstUserClass, dLastUserClass = dFirstUserClass + dMaxUserClasses - 1.
            int getClass() const;
            // Set Position of our geometry
            void setPosition(double, double, double);
            // Set Rotation via Matrix Transform
            void setRotation(double, double, double,
                             double, double, double,
                             double, double, double);
            // Set Rotation using Quaternions
            void setQuaternion(double, double, double, double);
            // Regresa la posición/orientación
            //const dReal * dGeomGetPosition (dGeomID);
            //const dReal * dGeomGetRotation (dGeomID);
            //void dGeomGetQuaternion (dGeomID, dQuaternion result);

            // Habilita o deshabilita la geometría.
            void setEnable(bool);

            // Regresa verdadero en caso de que la geometría esté habilitada y falso en
            // caso contrario.
            bool isEnable() const;

            // Regresa los puntos (min_x, min_y, min_z) y (max_x, max_y, max_z) de la caja
            // que acota la geometría, pero en este vector
            // (min_x, max_x, min_y, max_y, min_z, max_z)
            //void dGeomGetAABB (dGeomID, dReal aabb[6]);

            // Regresa si la geometría está en el espacio dado.
            //int dGeomIsSpace (dGeomID);

            // Regresa el espacio en el que se encuentra esta geometría.
            //dSpaceID dGeomGetSpace (dGeomID);

            // Para controlar que geometrías interaccionan con cuales otras.
            //void dGeomSetCategoryBits (dGeomID, unsigned long bits);
            //void dGeomSetCollideBits (dGeomID, unsigned long bits);
            //unsigned long dGeomGetCategoryBits (dGeomID);
            //unsigned long dGeomGetCollideBits (dGeomID);
    };


    class BoxGeometry : public Geometry
    {
        public:
            // Constructor
            BoxGeometry(World*, double, double, double);
    };


    class SphereGeometry : public Geometry
    {
        public:
            // Constructor
            SphereGeometry(World*, double);
    };


    class CapsuleGeometry : public Geometry
    {
        public:
            // Constructor
            CapsuleGeometry(World*, double, double);
    };

    class PlaneGeometry : public Geometry
    {
        public:
            // Constructor
            PlaneGeometry(World*, double, double, double, double);
            // Puro OSG!
            void setBox(double, double, double);
    };

    class CylinderGeometry : public Geometry
    {
        public:
            // Constructor
            CylinderGeometry(World* world, double radius, double length);
            void setCylinder(double radius, double length);
    };

    class TriangleMeshGeometry : public Geometry
    {
        public:
            //Constructor
            TriangleMeshGeometry(World *,osg::Geode *);
            dTriMeshDataID getOdeGeomData();
            float * getdVertices();
            unsigned int getNumdVertices();
            int ** getdIndices();
            unsigned int getNumdIndices();
            //Destructor
            ~TriangleMeshGeometry();
        private:
            //Intermediate arrays for Trimesh Construction
            float * Vertices;
            int ** Indices;
            unsigned int vsize;
            unsigned int isize;
            //TriMesh Data
            dTriMeshDataID ode_geomData;
            //Our Trimesh Filter
            bool checkDrawable(osg::Geode *);
    };

}

#endif