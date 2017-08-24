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

#include <World.h>

namespace osgOde
{

    World::World()
    {
        // Create our World and set it's Properties
        ode_world = dWorldCreate();
        dWorldSetGravity(ode_world, 0.0, 0.0, 0.0);
        //dWorldGetGravity (ode_world, dVector3 gravity);
        dWorldSetERP(ode_world, 0.2);
        //dReal dWorldGetERP (ode_world);
        dWorldSetCFM(ode_world, 0.0001);
        //dReal dWorldGetCFM (ode_world);
        dWorldSetAutoDisableFlag(ode_world, 1);
        //int   dWorldGetAutoDisableFlag (ode_world);
        dWorldSetAutoDisableLinearThreshold(ode_world, 0.01);
        //dReal dWorldGetAutoDisableLinearThreshold (ode_world);
        dWorldSetAutoDisableAngularThreshold(ode_world, 0.01);
        //dReal dWorldGetAutoDisableAngularThreshold (ode_world);
        dWorldSetAutoDisableSteps(ode_world, 10);
        //int   dWorldGetAutoDisableSteps (ode_world);
        dWorldSetAutoDisableTime(ode_world, 0.0);
        //dReal dWorldGetAutoDisableTime (ode_world);
        dWorldSetQuickStepNumIterations(ode_world, 20);
        //int dWorldGetQuickStepNumIterations (ode_world);
        dWorldSetContactMaxCorrectingVel(ode_world, 100.0);
        //dReal dWorldGetContactMaxCorrectingVel (ode_world);
        dWorldSetContactSurfaceLayer(ode_world, 0.1);
        //dReal dWorldGetContactSurfaceLayer (ode_world);

        //  ___
        // | __|
        // |__ |
        // |___|
        //
        // 5. Crear el Espacio y establecer sus propiedades
        // El espacio simple no tiene jerarquía de geometrías, por lo que para verificar
        // las colisiones se hace cada una contra todas, lo que requiere mucha memoria
        // y tiempo te cómputo del orden O(n"2), donde n es el número de objetos en el
        // espacio. Es recomendable cuando se usa un número pequeño de objetos y no se
        // recomienda cuando el número de objetos es grande. El parámetro indica el
        // espacio donde se creará este espacio (en este caso sólo tenemos un espacio,
        // de modo que el parámetro debe ser 0).
        //	  ode_space = dSimpleSpaceCreate(0);

        // El espacio de multi-resolución "hash table" tiene una estructura interna
        // de "cuadrícula 3D" con varios niveles de resolución. Requiere menos memoria
        // y el tiempo de cómputo es O(n). Recomendable cuando hay muchos objetos.
        ode_space = dHashSpaceCreate(0);

        // Especifica que el tamaño del mínimo nivel de resolución será 2 * min y el
        // máximo 2 * max.
        //		int min = 1, max = 6;
        //		dHashSpaceSetLevels (ode_space, min, max);
        //void dHashSpaceGetLevels (dSpaceID space, int *minlevel, int *maxlevel);

        // El espacio "quad-tree" una jerarquía tipo árbol AABB basada en cuadrícula.
        // La memoria utilizada para esta estructura es 4"depth * 32 bytes. Es
        // recomendable su uso para espacios muy grandes con muchos objetos.
        //		dReal center[3]; center[0] = 0.0; center[1] = 0.0; center[2] = 0.0;
        //		dReal extent[3]; extent[0] = 100.0; extent[1] = 100.0; extent[2] = 100.0;
        //		int depth = 4;
        //		ode_space = dQuadTreeSpaceCreate(0, &center[0], &extent[0], depth);

        // Determnina si las gemetrías se destruirán cuando se detruya el espacio
        // (al llamar dSpaceDestroy(ode_space)) con el parámetro 1, o no con el
        // parámetro 0.
        dSpaceSetCleanup(ode_space, 1);
        //int dSpaceGetCleanup (dSpaceID space);

        // Añade una geometría al espacio. Útil cuando se quieren utilizar las mismas
        // geometrías en varios espacios.
        //		dSpaceAdd(dSpaceID, dGeomID);

        // Quita una geometría de este espacio
        //		dSpaceRemove(dSpaceID, dGeomID);

        // Regresa 1 si la geometría está en este espacio o 0 si no.
        //		int dSpaceQuery(dSpaceID, dGeomID);

        // Regresa el número de geometrías en el espacio
        //		int dSpaceGetNumGeoms(dSpaceID);

        // Regresa la i-ésima geometría en es espacio. No funciona para el espacio
        // quad-tree.
        //		dGeomID dSpaceGetGeom(dSpaceID, int i);

        //  ___
        // | _ |
        // | _ |
        // |___|
        //
        // 8. Crear un Grupo de uniones de contacto
        contact_group = dJointGroupCreate(0);
        time = timer.tick();
    }

    void World::setGravity(double x, double y, double z)
    {
        dWorldSetGravity(ode_world, x, y, z);
    }

    void World::traverse(osg::NodeVisitor &nv)
    {
        //  ___
        // | _ |
        // |_  |
        //   |_|
        //
        // 9. Loop:

        // c) Hacer detección de colisiones en el Espacio
        // d) Añadir al Grupo de uniones de contacto una Unión por cada colisión
        dSpaceCollide(ode_space, this, nearCallback);
        osg::Timer_t actual_time = timer.tick();
        // e) Hacer un paso de simulación en el Mundo
        //    dWorldStep(ode_world, timer.delta_s(time, actual_time));
        dWorldQuickStep(ode_world, timer.delta_s(time, actual_time));
        time = actual_time;
        // f) Vaciar el Grupo de uniones de contacto
        dJointGroupEmpty(contact_group);
        osg::Group::traverse(nv);
    }

    World::~World()
    {
        dSpaceDestroy(ode_space);
        dWorldDestroy(ode_world);
        dCloseODE();
    }

    void World::nearCallback(void* data, dGeomID o1, dGeomID o2)
    {
        dBodyID b1 = dGeomGetBody(o1);
        dBodyID b2 = dGeomGetBody(o2);
        if(b1 && b2 && dAreConnected(b1, b2))
            return;
        const int MAX_CONTACTS = 4;
        dContact contact[MAX_CONTACTS];
        for (int i = 0; i < MAX_CONTACTS; ++i)
        {
            contact[i].surface.mode = dContactBounce;
            contact[i].surface.mu = dInfinity;
            contact[i].surface.bounce = 0.25;
            contact[i].surface.bounce_vel = 0.1;
        }
        World* world_node = (World*)(data);
        // Por cada colisión...
        int numc = dCollide(o1, o2, MAX_CONTACTS, &contact[0].geom, sizeof(dContact));
        for(int i = 0; i < numc; ++i)
        {
            // ...añadir al Grupo de uniones de contacto una Unión
            dJointID c = dJointCreateContact
                (
                world_node -> ode_world,
                world_node -> contact_group,
                contact + i
                );
            dJointAttach(c, b1, b2);
        }
    }

}
