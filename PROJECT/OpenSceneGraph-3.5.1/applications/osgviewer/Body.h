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

#ifndef _OSGODE_BODY_
#define _OSGODE_BODY_

#include <osg/PositionAttitudeTransform>
#include <osg/Geometry>

#include <osgOde.h>
#include <World.h>
#include <Geometry.h>

namespace osgOde{

    class Body : public osg::PositionAttitudeTransform
    {
        public:

            // Cuerpo rígido
            dBodyID ode_body;
            // Constructor
            Body(World* world);
            // Destruye el cuerpo.
            void destroy();
            // Establece/da datos de usuario almacenados jnto con el cuerpo.
            void setData(void*);

            void* getData() const;
            // Establece la posicion/orientacion inicial del cuerpo.
            void setPosition(double, double, double);

            void setRotation(double a, double b, double c,
                             double d, double e, double f,
                             double g, double h, double i);

            void setQuaternion(double x, double y, double z, double alpha);

            // Regresa la posicion/orientacion del cuerpo.
            //const  * dBodyGetPosition   (ode_body);
            //const  * dBodyGetRotation   (ode_body);	/* ptr to 4x3 rot matrix */
            //const  * dBodyGetQuaternion (ode_body);

            // Establece la velocidad lineal/angular.
            void setVelocity(double, double, double);

            void setAngularVelocity(double, double, double);

            // Regresa la velocidad lineal/angular.
            //const  * dBodyGetLinearVel  (ode_body);
            //const  * dBodyGetAngularVel (ode_body);


            // Regresa la posicion/velocidad de un punto en el cuerpo en coordenadas globales (al reves en la ultima funcion).
            //void dBodyGetRelPointPos    (ode_body,  px,  py,  pz, dVector3 result);
            // void dBodyGetRelPointVel    (ode_body,  px,  py,  pz, dVector3 result);
            // void dBodyGetPointVel       (ode_body,  px,  py,  pz, dVector3 result);
            // void dBodyGetPosRelPoint    (ode_body,  px,  py,  pz, dVector3 result);

            // Transforma un vector en cooredenadas relativas al cuerpo en coordenadas globales (o viceversa).
            //void dBodyVectorToWorld     (ode_body,  px,  py,  pz, dVector3 result);
            // void dBodyVectorFromWorld   (ode_body,  px,  py,  pz, dVector3 result);


            // Anade fuerza/torcion al cuerpo.
            void addForce(double, double, double);

            void addTorque(double, double, double);

            // Anade fuerza/torcion relativa al cuerpo.
            void addRelForce(double, double, double);

            void addRelTorque(double, double, double);

            // Anade fuerza al cuerpo aplicada en una posicion especifica.
            void addForceAtPos(double, double, double, double, double, double);

            // Anade fuerza al cuerpo aplicada en una posicion relativa especifica.
            void addForceAtRelPos(double, double, double, double, double, double);

            // Anade fuerza relativa al cuerpo aplicada en una posicion especifica.
            void addRelForceAtPos(double, double, double, double, double, double);

            // Anade fuerza relativa al cuerpo aplicada en una posicion relativa especifica.
            void addRelForceAtRelPos(double, double, double, double, double, double);


            // Regresa la fuerza/torcion.
            //const  * dBodyGetForce   (ode_body);
            //const  * dBodyGetTorque  (ode_body);


            // Establece la fuerza/torcion.
            void setForce(double, double, double);

            void setTorque(double, double, double);


            // Establece 
            void setMass(double m, int type, double m1 = 1.0, double m2 = 1.0, double m3 = 1.0);
            // Regresa la masa del cuerpo.
            //void dBodyGetMass (ode_body, dMass *mass);

            void setGeometry(Geometry*);

            // Establece/regresa si un cuerpo esta habilitado o no.
            void setEnable(bool);

            bool isEnabled() const;


            // Establece/regresa los umbrales para considerar un cuerpo en reposo.
            // (Veanse los las mismas funciones en World.h).
            //dReal dBodyGetAutoDisableLinearThreshold (dBodyID);
            //void  dBodySetAutoDisableLinearThreshold (dBodyID, dReal /linear_threshold);
            //dReal dBodyGetAutoDisableAngularThreshold (dBodyID);
            //void  dBodySetAutoDisableAngularThreshold (dBodyID, dReal     angular_threshold);
            //int   dBodyGetAutoDisableSteps (dBodyID);
            //void  dBodySetAutoDisableSteps (dBodyID, int steps);
            //dReal dBodyGetAutoDisableTime (dBodyID);
            //void  dBodySetAutoDisableTime (dBodyID, dReal time);
            //void  dBodySetAutoDisableDefaults (dBodyID);
            //int   dBodyGetAutoDisableFlag (dBodyID);
            //void  dBodySetAutoDisableFlag (dBodyID, int do_auto_disable);



            // Establece/regresa si el cuerpo sera afectado por la gravedad.
            void setApplyGravity(bool);

            bool isGravityApplied() const;


            // Establece/regresa el modo de rotacion:
            // 0 = infinitesimal, es el default y mas rapido pero menos preciso.
            // 1 = finito, es mas preciso pero menos rapido; sirve para corregir
            // ciertos problemas en cuerpos giratorios.
            //void dBodySetFiniteRotationMode (ode_body, int mode);
            //int dBodyGetFiniteRotationMode (ode_body);

            // Establece/regresa el eje de rotacion en caso de que se este utilizando
            // el modo finito.
            //void dBodySetFiniteRotationAxis (ode_body,  x,  y,  z);
            //void dBodyGetFiniteRotationAxis (ode_body, dVector3 result);


            // Regresa el numero de uniones asociadas a este cuerpo.
            //int dBodyGetNumJoints (ode_body b);

            // Regresa la n-esima union asociada a este cuerpo.
            //dJointID dBodyGetJoint (ode_body, int index);


            // Actualiza la posición y orientación según los datos del Cuerpo
            virtual void traverse(osg::NodeVisitor &nv);
        private:

            // La masa del cuerpo
            dMass mass;
    };

}

#endif
