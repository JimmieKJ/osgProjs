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

#include <osgOde/Geometry>

namespace osgOde{

    void Geometry::destroy()
    {
        dGeomDestroy(ode_geom);
    }

    int Geometry::getClass() const
    {
        return dGeomGetClass(ode_geom);
    }

    void Geometry::setPosition(double x, double y, double z)
    {
        dGeomSetPosition(ode_geom, x, y, z);
        PositionAttitudeTransform::setPosition(osg::Vec3(x, y, z));
    }

    void Geometry::setRotation(double a, double b, double c, double d, double e, double f, double g, double h, double i)
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
        dGeomSetRotation(ode_geom, &matrix[0]);

        osg::Matrixd* osg_matrix = new osg::Matrixd(a, b, c, 0,
                                                    d, e, f, 0,
                                                    g, h, i, 0,
                                                    0, 0, 0, 1);
        osg::Quat q;
        osg_matrix -> get(q);
        PositionAttitudeTransform::setAttitude(q);
    }


    void Geometry::setQuaternion(double x, double y, double z, double alpha)
    {
        osg::Quat quat(alpha, osg::Vec3(x, y, z));

        dReal q[4];
        q[0] = quat.w();
        q[1] = quat.x();
        q[2] = quat.y();
        q[3] = quat.z();

        dGeomSetQuaternion(ode_geom, &q[0]);
        PositionAttitudeTransform::setAttitude(quat);
    }

    void Geometry::setEnable(bool e)
    {
        if(e)
            dGeomEnable(ode_geom);
        else
            dGeomDisable(ode_geom);
    }

    bool Geometry::isEnable() const
    {
        return (dGeomIsEnabled(ode_geom) == 1);
    }

    BoxGeometry::BoxGeometry(World* world, double lx, double ly, double lz)
    {
        //  ___
        // | __|
        // | _ |
        // |___|
        //
        // 6. Crear las Geometrías del Espacio y establecer sus propiedades
        ode_geom = dCreateBox(world -> ode_space, lx, ly, lz);

        osg::Box *shape = new osg::Box(osg::Vec3(0.0, 0.0, 0.0), lx, ly, lz);
        osg::Geode* geode = new osg::Geode;
        geode -> addDrawable(new osg::ShapeDrawable(shape));
        addChild(geode);
    }

    SphereGeometry::SphereGeometry(World* world, double r)
    {
        //  ___
        // | __|
        // | _ |
        // |___|
        //
        // 6. Crear las Geometrías del Espacio y establecer sus propiedades
        ode_geom = dCreateSphere(world -> ode_space, r);

        osg::Sphere *shape = new osg::Sphere(osg::Vec3(0.0, 0.0, 0.0), r);
        osg::Geode* geode = new osg::Geode;
        geode -> addDrawable(new osg::ShapeDrawable(shape));
        addChild(geode);
    }

    CapsuleGeometry::CapsuleGeometry(World* world, double r, double h)
    {
        //  ___
        // | __|
        // | _ |
        // |___|
        //
        // 6. Crear las Geometrías del Espacio y establecer sus propiedades
        ode_geom = dCreateCapsule(world -> ode_space, r, h);
        osg::Capsule *shape = new osg::Capsule(osg::Vec3(0.0, 0.0, 0.0), r, h);
        osg::Geode* geode = new osg::Geode;
        geode -> addDrawable(new osg::ShapeDrawable(shape));
        addChild(geode);
    }

    PlaneGeometry::PlaneGeometry(World* world, double a, double b, double c, double d)
    {
        //  ___
        // | __|
        // | _ |
        // |___|
        //
        // 6. Crear las Geometrías del Espacio y establecer sus propiedades
        ode_geom = dCreatePlane(world -> ode_space, a, b, c, d);
    }

    void PlaneGeometry::setBox(double lx, double ly, double lz)
    {
        osg::Geode* geode;
        if(getNumChildren() > 0)
        {
            geode = (osg::Geode*)(getChild(0));
            //geode -> removeDrawable(0, geode -> getNumDrawables());
        }
        else
        {
            geode = new osg::Geode;
            addChild(geode);
        }
        //No funciona en OSG 1.2
        //osg::InfinitePlane * shape = new osg::InfinitePlane();
        osg::Box *shape = new osg::Box(osg::Vec3(0.0, 0.0, 0.0), lx, ly, lz);
        geode -> addDrawable(new osg::ShapeDrawable(shape));
    }

    CylinderGeometry::CylinderGeometry(World* world, double radius, double length)
    {
        ode_geom = dCreateCCylinder(world -> ode_space, radius, length);
        osg::Cylinder *shape = new osg::Cylinder(osg::Vec3(0.0, 0.0, 0.0), radius, length*3);
        osg::Geode* geode = new osg::Geode;
        geode -> addDrawable(new osg::ShapeDrawable(shape));
        addChild(geode);
    }

    void CylinderGeometry::setCylinder(double radius, double length){
        dGeomCCylinderSetParams(ode_geom,radius,length);
    }

    TriangleMeshGeometry::TriangleMeshGeometry(World * world, osg::Geode * BaseGeom){
        if(checkDrawable(BaseGeom)){
            osg::Geode* geode = BaseGeom;
            //Extract the Drawable
            osg::Drawable *BaseDrawable = geode->getDrawable(0);
            osg::Geometry *BaseGeometry = dynamic_cast<osg::Geometry *> (BaseDrawable);
            //Extract Vertices and Faces
            osg::Vec3Array * Mesh=dynamic_cast<osg::Vec3Array*>(BaseGeometry->getVertexArray());
            osg::DrawElementsUInt* faces=dynamic_cast<osg::DrawElementsUInt *>(BaseGeometry->getPrimitiveSet(0));
            //create arrays
            Vertices = new float[3*Mesh->getNumElements()];
            Indices = new int * [faces->getNumIndices()/3];
            Indices[0] = new int [faces->getNumIndices()];
            for(unsigned int ic=1;ic<faces->getNumIndices()/3;ic++)
                Indices[ic]= Indices[0]+(ic*3);
            //Capture Mesh into an array of floats
            unsigned int iv = 0;
            for(unsigned int ic=0;ic<Mesh->getNumElements();ic++){
                Vertices[iv]=(*Mesh)[ic].x();
                Vertices[iv+1]=(*Mesh)[ic].y();
                Vertices[iv+2]=(*Mesh)[ic].z();
                iv+=3;
            }
            //Capture Indices
            iv = 0;
            for(unsigned int ic = 0; ic<faces->getNumIndices()/3;ic++){
                Indices[ic][0]=faces->index(iv);
                Indices[ic][1]=faces->index(iv+1);
                Indices[ic][2]=faces->index(iv+2);
                iv+=3;
            }
            //Save Array sizes
            vsize=Mesh->getNumElements()*3;
            isize=faces->getNumIndices()/3;
            //dGeometry Creation
            ode_geomData = dGeomTriMeshDataCreate();
            //Dada que Ode esta en C, no maneja Arrays ni vectores, entonces le tenemos que pasar el apuntador al arreglo de flotantes, de cuantos bytes es cada vertice y tambien sus indices.
            dGeomTriMeshDataBuildSingle(ode_geomData, Vertices, 3 * sizeof(float), Mesh->getNumElements(),Indices[0], faces->getNumIndices(), 3 * sizeof(int));
            osg::notify(osg::WARN) << "JP"<< std::endl;
            ode_geom = dCreateTriMesh(world -> ode_space, ode_geomData, 0, 0, 0);
            dGeomSetData(ode_geom, ode_geomData);
            //Add Geometry to tree
            addChild(geode);
        }
        else
            osg::notify() << "You must use insertBaseGeom to insert a valid geode node with one Drawable and one primitive." <<std::endl;
    }

    dTriMeshDataID TriangleMeshGeometry::getOdeGeomData(){
        return ode_geomData;
    }

    float * TriangleMeshGeometry::getdVertices(){
        return Vertices;
    }

    unsigned int TriangleMeshGeometry::getNumdVertices(){
        return vsize;
    }

    int ** TriangleMeshGeometry::getdIndices(){
        return Indices;
    }

    unsigned int TriangleMeshGeometry::getNumdIndices(){
        return isize;
    }

    TriangleMeshGeometry::~TriangleMeshGeometry(){
        delete [] Vertices;
        delete [] Indices[0];
        delete [] Indices;
    }

    bool TriangleMeshGeometry::checkDrawable(osg::Geode *geode) {
        if(1<geode->getNumDrawables()){
            osg::notify(osg::WARN) << "Geode contains more than one Drawable." <<std::endl;
            return false;
        }
        else{
            osg::Drawable *drawable=geode->getDrawable(0);
            osg::Geometry *geom=dynamic_cast<osg::Geometry *> (drawable);

            for(unsigned int pc=0; pc < geom->getNumPrimitiveSets() ; pc++){
                osg::PrimitiveSet * prset = geom->getPrimitiveSet(pc);
                if(prset->getMode() == osg::PrimitiveSet::TRIANGLES){
                    osg::notify(osg::WARN) << "Primitive Set " << pc << " passed." <<std::endl;
                }
                else{
                    osg::notify(osg::WARN) << "Primitive Set " << pc << " :this is not a Triangle Primitive Set" <<std::endl;
                    return false;
                }
            }
            return true;
        }
    }

}
