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

#include <Body.h>

namespace osgOde{

    Body::Body(World* world)
    {
        //  ___
        // |__ |
        // | __|
        // |___|
        //
        // 2. Crear los Cuerpos del Mundo y establecer sus propiedades
        ode_body = dBodyCreate(world -> ode_world);
        world -> addChild(this);
    }

    void Body::destroy()
    {
        dBodyDestroy(ode_body);
    }

    void Body::setData(void* data)
    {
        dBodySetData(ode_body, data);
    }

    void* Body::getData() const
    {
        return dBodyGetData(ode_body);
    }

    void Body::setPosition(double x, double y, double z)
    {
        dBodySetPosition(ode_body, x, y, z);
        PositionAttitudeTransform::setPosition(osg::Vec3(x, y, z));
    }

    void Body::setRotation(double a, double b, double c,
                               double d, double e, double f,
                               double g, double h, double i)
    {
        dReal matrix[12];
        matrix[0] = a;
        matrix[1] = b;
        matrix[2] = c;
        matrix[3] = d;
        matrix[4] = e;
        matrix[5] = f;
        matrix[6] = g;
        matrix[7] = h;
        matrix[8] = i;
        matrix[9] = 0.0;
        matrix[12] = 0.0;
        matrix[11] = 0.0;
        dBodySetRotation(ode_body, &matrix[0]);

        osg::Matrixd* osg_matrix = new osg::Matrixd(a, b, c, 0,
                                                    d, e, f, 0,
                                                    g, h, i, 0,
                                                    0, 0, 0, 1);
        osg::Quat q;
        osg_matrix -> get(q);
        PositionAttitudeTransform::setAttitude(q);
    }

    void Body::setQuaternion(double x, double y, double z, double alpha)
    {
        osg::Quat quat(alpha, osg::Vec3(x, y, z));

        dReal q[4];
        q[0] = quat.w();
        q[1] = quat.x();
        q[2] = quat.y();
        q[3] = quat.z();

        dBodySetQuaternion(ode_body, &q[0]);
        PositionAttitudeTransform::setAttitude(quat);
    }

    void Body::setVelocity(double x, double y, double z)
    {
        dBodySetLinearVel(ode_body, x, y, z);
    }

    void Body::setAngularVelocity(double x, double y, double z)
    {
        dBodySetAngularVel(ode_body, x, y, z);
    }

    void Body::addForce(double x, double y, double z)
    {
        dBodyAddForce(ode_body, x, y, z);
    }

    void Body::addTorque(double x, double y, double z)
    {
        dBodyAddTorque(ode_body, x, y, z);
    }

    void Body::addRelForce(double x, double y, double z)
    {
        dBodyAddRelForce(ode_body, x, y, z);
    }

    void Body::addRelTorque(double x, double y, double z)
    {
        dBodyAddRelTorque(ode_body, x, y, z);
    }

    void Body::addForceAtPos(double x, double y, double z, double px, double py, double pz)
    {
        dBodyAddForceAtPos(ode_body, x, y, z, px,  py,  pz);
    }

    void Body::addForceAtRelPos(double x, double y, double z, double px, double py, double pz)
    {
        dBodyAddForceAtRelPos(ode_body, x, y, z, px, py, pz);
    }

    void Body::addRelForceAtPos(double x, double y, double z, double px, double py, double pz)
    {
        dBodyAddRelForceAtPos(ode_body, x, y, z, px,  py,  pz);
    }

    void Body::addRelForceAtRelPos(double x, double y, double z, double px, double py, double pz)
    {
        dBodyAddRelForceAtRelPos(ode_body, x, y, z, px,  py,  pz);
    }

    void Body::setForce(double x, double y, double z)
    {
        dBodySetForce(ode_body,  x,  y,  z);
    }

    void Body::setTorque(double x, double y, double z)
    {
        dBodySetTorque(ode_body,  x,  y,  z);
    }

    void Body::setMass(double m, int type, double m1, double m2, double m3)
    {
        switch(type)
        {
            case dBoxClass:
            {
                dMassSetBoxTotal(&mass, m, m1, m2, m3);
                break;
            }
            case dSphereClass:
            {
                dMassSetSphereTotal(&mass, m, m1);
                break;
            }
            case dCCylinderClass:
            {
                dMassSetCappedCylinderTotal(&mass, m, 2, m1, m2);
                //dMassSetCylinderTotal(&mass, m, 2, m1, m2);
                break;
            }
            default:
            {
                dMassSetBoxTotal(&mass, m, m1, m2, m3);
                break;
            }
        }
        dBodySetMass(ode_body, &mass);
    }

    void Body::setGeometry(Geometry* geometry)
    {
        //  ___
        // |_  |
        //  / /
        // /_/
        //
        // 7. Asociar las Geometrías con los Cuerpos, si es necesario
        dGeomSetBody(geometry -> ode_geom, ode_body);
        addChild(geometry);
    }

    void Body::setEnable(bool yes)
    {
        if(yes)
            dBodyEnable(ode_body);
        else
            dBodyDisable(ode_body);
    }

    bool Body::isEnabled() const
    {
        return (dBodyIsEnabled(ode_body) == 1);
    }

    void Body::setApplyGravity(bool yes)
    {
        dBodySetGravityMode(ode_body, yes ? 1 : 0);
    }

    bool Body::isGravityApplied() const
    {
        return (dBodyGetGravityMode(ode_body) == 1);
    }

    void Body::traverse(osg::NodeVisitor &nv)
    {
        const dReal* quat = dBodyGetQuaternion(ode_body);
        PositionAttitudeTransform::setAttitude(osg::Quat(quat[1], quat[2], quat[3], quat[0]));

        const dReal* pos = dBodyGetPosition(ode_body);
        PositionAttitudeTransform::setPosition(osg::Vec3(pos[0], pos[1], pos[2]));
        PositionAttitudeTransform::traverse(nv);
    }

}
