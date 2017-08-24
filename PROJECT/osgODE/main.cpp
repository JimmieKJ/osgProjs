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

#include <osg/Group>
#include <osg/NodeVisitor>
#include <osgProducer/Viewer>
#include <osgDB/ReadFile>
#include <osgGA/GUIEventHandler>
#include <osgGA/GUIEventAdapter>
#include <osgGA/GUIActionAdapter>
#include <osgOde.h>

#include <iostream>

#define MAX_SIZE (4)
#define MIN_LIM (-MAX_SIZE / 2.0)
#define MAX_FORCE (200.0);
#define NUM_BODIES (6) // Controlados por el usuario
#define NUM_JOINTS (5) // De cada tipo

class KeyboardHandler : public osgGA::GUIEventHandler
{
  public:

    KeyboardHandler()
    {
			force.set(1.0, 0.0, 0.0);
			apply_force = false;
			mode = NONE;
			f = MAX_FORCE;
			actual_body = 0;

std::cout << "Uso:" << std::endl <<
	"0         Fuerza global." << std::endl <<
	"1         Torsion global." << std::endl <<
	"2         Fuerza relativa." << std::endl <<
	"3         Torsion relativa." << std::endl <<
	"n         Siguiente cuerpo." << std::endl <<
	"g         Gravedad encendido/apagado." << std::endl <<
	"+         Aumenta fuerza/torsion." << std::endl <<
	"-         Disminuye fuerza/torsion." << std::endl <<
	".         Establece la velocidad, fuerza y torsion en 0." << std::endl <<
	"izquierda Fuerza en direccion -x." << std::endl <<
	"derecha   Fuerza en direccion x." << std::endl <<
	"arriba    Fuerza en direccion y." << std::endl <<
	"abajo     Fuerza en direccion -y." << std::endl <<
	"PageUp    Fuerza en direccion z." << std::endl <<
	"PageDown  Fuerza en direccion -z." << std::endl;
		}

    virtual bool handle (const osgGA::GUIEventAdapter&, osgGA::GUIActionAdapter&, osg::Object*, osg::NodeVisitor*);

		osgOde::Body* body;
		osgOde::Body* bodies[NUM_BODIES];


  private:
		
		enum Mode {NONE, ADD_FORCE, ADD_TORQUE, ADD_REL_FORCE, ADD_REL_TORQUE,
			ADD_FORCE_AT_POS, ADD_REL_FORCE_AT_POS, ADD_FORCE_AT_REL_POS, 
			ADD_REL_FORCE_AT_REL_POS, SET_FORCE, SET_TORQUE};

		Mode mode;

		osg::Vec3 force;

		bool apply_force;

		double f;

		int actual_body;

};

int main (int argc, char* argv[])
{
// Crear un mundo
	osgOde::World* world = new osgOde::World();
	world -> setGravity(0.0, 0.0, -9.8);

// Crear geometrías y Cuerpos
	osgOde::PlaneGeometry* plane = new osgOde::PlaneGeometry(world, 0.0, 0.0, 1.0, 0.0);
	plane -> setBox(MAX_SIZE * 10.0 + 10.0, MAX_SIZE * 10.0 + 10.0, 0.1);
  osgOde::setTexture(plane, "data/cement.tga");

	osgOde::BoxGeometry* box = new osgOde::BoxGeometry(world, 2.0, 0.5, 3.0);
  osgOde::setTexture(box, "data/Ixtli_logo.jpg");

	osgOde::BoxGeometry* wall1 = new osgOde::BoxGeometry(world, MAX_SIZE * 10.0, 0.5, 4.0);
	wall1 -> setPosition(-8.0, 8.0, 2.0);
	wall1 -> setQuaternion(0.0, 0.0, 1.0, osg::PI_4);
  osgOde::setTexture(wall1, "data/cement.tga");

	osgOde::BoxGeometry* wall2 = new osgOde::BoxGeometry(world, MAX_SIZE * 4.0, MAX_SIZE * 4.0, 0.5);
	wall2 -> setPosition(MAX_SIZE * 4.0, 0.0, MAX_SIZE);
	wall2 -> setQuaternion(0.0, 1.0, 0.0, -osg::PI_4);
  osgOde::setTexture(wall2, "data/cement.tga");

	osgOde::Body* body1 = new osgOde::Body(world);
	body1 -> setGeometry(box);
	body1 -> setMass(1.0, box -> getClass(), 2.0, 0.5, 3.0);
	body1 -> setPosition(0.0, 0.0, 1.65);

	int i;

	osgOde::SphereGeometry** spheres = new osgOde::SphereGeometry* [NUM_JOINTS + 1];
	osgOde::Body** spheres_bodies = new osgOde::Body* [NUM_JOINTS + 1];
	for(i = 0; i <= NUM_JOINTS; ++i)
	{ 
		spheres[i] = new osgOde::SphereGeometry(world, 1.0);
	  osgOde::setTexture(spheres[i], "data/metal.tga");
		spheres_bodies[i] = new osgOde::Body(world);
		spheres_bodies[i] -> setGeometry(spheres[i]);
		spheres_bodies[i] -> setMass(0.5, spheres[i] -> getClass(), 1.0);
		spheres_bodies[i] -> setPosition(-3.0, -3.0, 5.0 + 2.0 * i);
	}

	osgOde::BoxGeometry** bricks = new osgOde::BoxGeometry* [NUM_JOINTS + 1];
	osgOde::Body** bricks_bodies = new osgOde::Body* [NUM_JOINTS + 1];
	for(i = 0; i <= NUM_JOINTS; ++i)
	{ 
		bricks[i] = new osgOde::BoxGeometry(world, 1.0, 0.5, 2.0);
	        osgOde::setTexture(bricks[i], "data/brick.tga");
		bricks_bodies[i] = new osgOde::Body(world);
		bricks_bodies[i] -> setGeometry(bricks[i]);
		bricks_bodies[i] -> setMass(0.5, bricks[i] -> getClass(), 1.0, 0.5, 2.0);
		bricks_bodies[i] -> setPosition(3.0, -3.0, 10.0 + 2.0 * i);
	}

	osgOde::BoxGeometry** sticks = new osgOde::BoxGeometry* [NUM_JOINTS + 1];
	osgOde::Body** sticks_bodies = new osgOde::Body* [NUM_JOINTS + 1];
	for(i = 0; i <= NUM_JOINTS; ++i)
	{ 
		sticks[i] = new osgOde::BoxGeometry(world, 1.0 - 0.1 * i, 1.0 - 0.1 * i, 2.0);
	        osgOde::setTexture(sticks[i], "data/purple_stone.tga");
		sticks_bodies[i] = new osgOde::Body(world);
		sticks_bodies[i] -> setGeometry(sticks[i]);
		sticks_bodies[i] -> setMass(0.5, sticks[i] -> getClass(), 1.0);
		sticks_bodies[i] -> setPosition(-5.0, 5.0, 5.0 + 2.0 * i);
	}

	osgOde::CapsuleGeometry** capsules = new osgOde::CapsuleGeometry* [NUM_JOINTS + 1];
	osgOde::Body** capsules_bodies = new osgOde::Body* [NUM_JOINTS + 1];
	for(i = 0; i <= NUM_JOINTS; ++i)
	{ 
		capsules[i] = new osgOde::CapsuleGeometry(world, 1.0, 1.0);
		osgOde::setTexture(capsules[i], "data/white_stone.tga");
		capsules_bodies[i] = new osgOde::Body(world);
		capsules_bodies[i] -> setGeometry(capsules[i]);
		capsules_bodies[i] -> setMass(0.5, capsules[i] -> getClass(), 1.0);
		capsules_bodies[i] -> setPosition(5.0, 5.0, 5.0 + 3.0 * i);
	}

	osgOde::CylinderGeometry** cylinders = new osgOde::CylinderGeometry* [NUM_JOINTS + 1];
	osgOde::Body** cylinder_bodies = new osgOde::Body* [NUM_JOINTS + 1];
	for(i = 0; i <= NUM_JOINTS; ++i)
	{ 
		cylinders[i] = new osgOde::CylinderGeometry(world, 1.0, 1.0);
		osgOde::setTexture(cylinders[i], "data/wtapestry.jpg");
		cylinder_bodies[i] = new osgOde::Body(world);
		cylinder_bodies[i] -> setGeometry(cylinders[i]);
		cylinder_bodies[i] -> setMass(0.5, cylinders[i] -> getClass(), 1.0);
		cylinder_bodies[i] -> setPosition(3.0, 3.0, 3.0 + 9.0 * i);
	}
// Trimesh
        if(argc>1){
            osg::Group * trimesh_group = dynamic_cast<osg::Group * >(osgDB::readNodeFile(argv[1]));
            osg::Group * trimesh_mtransform = dynamic_cast<osg::Group * >(trimesh_group->getChild(0));
            osg::Geode * trimesh = dynamic_cast<osg::Geode * >(trimesh_mtransform->getChild(0));
            osgOde::TriangleMeshGeometry * Raro = new osgOde::TriangleMeshGeometry(world, trimesh);

/*//Debugging
            float * V = Raro->getdVertices();
            osg::notify(osg::WARN) << "Number of Vertices " << Raro->getNumdVertices() << std::endl;
            for(unsigned int i=0;i < Raro->getNumdVertices();i+=3)
                osg::notify(osg::WARN) << V[i]<<","<<V[i+1]<<","<<V[i+2] <<std::endl;

            int ** I = Raro->getdIndices();
            osg::notify(osg::WARN) << "Number of Faces " << Raro->getNumdIndices() << std::endl;
            for(unsigned int i=0;i < Raro->getNumdIndices();i++)
                osg::notify(osg::WARN) << I[i][0]<<","<<I[i][1]<<","<<I[i][2] <<std::endl;
*/
            Raro -> setQuaternion(0.0, 1.0, 0.0, osg::PI_2);
            osgOde::setTexture(Raro, "data/grass.tga");
            osgOde::Body* tribody = new osgOde::Body(world);
            tribody -> setGeometry(Raro);
            tribody -> setMass(1.0, Raro -> getClass());
            tribody -> setPosition(16.0, 0.0, 40.0);
        }
// Vehiculo
	osgOde::SphereGeometry* tire1 = new osgOde::SphereGeometry(world, 1.0);
	osgOde::setTexture(tire1, "data/black_stone.tga");
	osgOde::Body* tire1_body = new osgOde::Body(world);
	tire1_body -> setGeometry(tire1);
	tire1_body -> setMass(0.5, tire1 -> getClass(), 1.0, 2.0);
	tire1_body -> setPosition(9.0, 2.05, 10.0);

	osgOde::SphereGeometry* tire2 = new osgOde::SphereGeometry(world, 1.0);
	osgOde::setTexture(tire2, "data/black_stone.tga");
	osgOde::Body* tire2_body = new osgOde::Body(world);
	tire2_body -> setGeometry(tire2);
	tire2_body -> setMass(0.5, tire2 -> getClass(), 1.0);
	tire2_body -> setPosition(9.0, -2.0, 10.0);

	osgOde::SphereGeometry* tire3 = new osgOde::SphereGeometry(world, 1.0);
	osgOde::setTexture(tire3, "data/black_stone.tga");
	osgOde::Body* tire3_body = new osgOde::Body(world);
	tire3_body -> setGeometry(tire3);
	tire3_body -> setMass(0.5, tire3 -> getClass(), 1.0);
	tire3_body -> setPosition(15.0, 2.0, 10.0);

	osgOde::SphereGeometry* tire4 = new osgOde::SphereGeometry(world, 1.0);
	osgOde::setTexture(tire4, "data/black_stone.tga");
	osgOde::Body* tire4_body = new osgOde::Body(world);
	tire4_body -> setGeometry(tire4);
	tire4_body -> setMass(0.5, tire4 -> getClass(), 1.0);
	tire4_body -> setPosition(15.0, -2.0, 10.0);

	osgOde::BoxGeometry* chasis = new osgOde::BoxGeometry(world, 6.0, 2.0, 0.5);
	osgOde::setTexture(chasis, "data/Ixtli_logo.jpg");
	osgOde::Body* chasis_body = new osgOde::Body(world);
	chasis_body -> setGeometry(chasis);
	chasis_body -> setMass(0.5, chasis -> getClass(), 6.0, 4.0, 0.5);
	chasis_body -> setPosition(12.0, 0.0, 10.0);

	osgOde::CapsuleGeometry* axis1 = new osgOde::CapsuleGeometry(world, 0.5, 4.0);
	osgOde::setTexture(axis1, "data/metal.tga");
	osgOde::Body* axis1_body = new osgOde::Body(world);
	axis1_body -> setGeometry(axis1);
	axis1_body -> setMass(0.1, axis1 -> getClass(), 0.5, 4.0);
	axis1_body -> setQuaternion(1.0, 0.0, 0.0, osg::PI_2);
	axis1_body -> setPosition(9.0, 0.0, 10.0);

	osgOde::CapsuleGeometry* axis2 = new osgOde::CapsuleGeometry(world, 0.5, 4.0);
	osgOde::setTexture(axis2, "data/metal.tga");
	osgOde::Body* axis2_body = new osgOde::Body(world);
	axis2_body -> setGeometry(axis2);
	axis2_body -> setMass(0.1, axis2 -> getClass(), 0.5, 4.0);
	axis2_body -> setQuaternion(1.0, 0.0, 0.0, osg::PI_2);
	axis2_body -> setPosition(15.0, 0.0, 10.0);
// Fin vehiculo


// Asignar los cuerpos a las uniones
	osgOde::HingeJoint* hinge_fixed = new osgOde::HingeJoint(world);
	hinge_fixed -> attach(body1, 0);
	hinge_fixed -> setAnchor(0.0, 0.0, 0.0);
	hinge_fixed -> setAxis(0.0, 0.0, 1.0);


	osgOde::BallJoint** balls = new osgOde::BallJoint* [NUM_JOINTS];
	for(i = 0; i < NUM_JOINTS; ++i)
	{
		balls[i] = new osgOde::BallJoint(world);
		balls[i] -> attach(spheres_bodies[i], spheres_bodies[i + 1]);
		balls[i] -> setAnchor(-3.0, -3.0, 5.0 + 2.0 * i);
	}

	osgOde::HingeJoint** hinges = new osgOde::HingeJoint* [NUM_JOINTS];
	for(i = 0; i < NUM_JOINTS; ++i)
	{
		hinges[i] = new osgOde::HingeJoint(world);
		hinges[i] -> attach(bricks_bodies[i], bricks_bodies[i + 1]);
		hinges[i] -> setAnchor(3.0, -3.0, 11.0 + 2.0 * i);
		hinges[i] -> setAxis(1.0, 0.0, 0.0);
		hinges[i] -> setLimits(-osg::PI_4, osg::PI_2);
		hinges[i] -> setTorque(4.0);
	}

	osgOde::SliderJoint** sliders = new osgOde::SliderJoint* [NUM_JOINTS];
	for(i = 0; i < NUM_JOINTS; ++i)
	{
		sliders[i] = new osgOde::SliderJoint(world);
		sliders[i] -> attach(sticks_bodies[i], sticks_bodies[i + 1]);
		sliders[i] -> setAxis(0.0, 0.0, 1.0);
		sliders[i] -> setLimits(-1.0, 0.25);
		sliders[i] -> setBounciness(0.9);
		sliders[i] -> setSoftness(0.25, 0.25);
		sliders[i] -> setForce(4.0);
	}

	double l = osg::PI / 8.0;
	osgOde::UniversalJoint** universals = new osgOde::UniversalJoint* [NUM_JOINTS];
	for(i = 0; i < NUM_JOINTS; ++i)
	{
		universals[i] = new osgOde::UniversalJoint(world);
		universals[i] -> attach(capsules_bodies[i], capsules_bodies[i + 1]);
		universals[i] -> setAnchor(5.0, 5.0, 6.5 + 3.0 * i);
		universals[i] -> setAxis1(1.0, 0.0, 0.0);
		universals[i] -> setAxis2(0.5, 1.0, 0.0);
		universals[i] -> setLimits(-l, 0.0, 0.0, l);
		universals[i] -> setSoftness(0.05, 0.05, 0.95, 0.95);
	}


// Uniones del vehiculo
	osgOde::SliderJoint* slider1 = new osgOde::SliderJoint(world);
	slider1 -> attach(chasis_body, axis1_body);
	slider1 -> setAxis(0.0, 0.0, 1.0);
	slider1 -> setLimits(-0.1, 0.1);
	slider1 -> setSoftness(0.5, 0.5);

	osgOde::SliderJoint* slider2 = new osgOde::SliderJoint(world);
	slider2 -> attach(chasis_body, axis2_body);
	slider2 -> setAxis(0.0, 0.0, 1.0);
	slider2 -> setLimits(-0.1, 0.1);
	slider2 -> setSoftness(0.5, 0.5);

	osgOde::Hinge2Joint* hinget1 = new osgOde::Hinge2Joint(world);
	hinget1 -> attach(axis1_body, tire1_body);
	hinget1 -> setAnchor(9.0, 2.0, 10.0);
	hinget1 -> setAxis1(0.0, 0.0, 1.0);
	hinget1 -> setAxis2(0.0, -1.0, 0.0);
	hinget1 -> setLimits(-osg::PI_4, osg::PI_4);
//	hinget1 -> setLimits(0.0, osg::PI_2);
	hinget1 -> setSuspension(0.4, 0.6);
//	hinget1 -> setSoftness(0.05, 0.5, 0.75, 0.25);

/*	osgOde::Hinge2Joint* hinget2 = new osgOde::Hinge2Joint(world);
	hinget2 -> attach(axis1_body, tire2_body);
	hinget2 -> setAnchor(9.0, -2.0, 10.0);
	hinget2 -> setAxis1(0.0, 0.0, 1.0);
	hinget2 -> setAxis2(0.0, -1.0, 0.0);
	hinget2 -> setLimits(-osg::PI_4, osg::PI_4);
	hinget2 -> setSuspension(0.4, 0.6);
*/
/*	osgOde::HingeJoint* hinget2 = new osgOde::HingeJoint(world);
	hinget2 -> attach(tire2_body, axis1_body);
	hinget2 -> setAnchor(9.0, -2.0, 10.0);
	hinget2 -> setAxis(0.0, 1.0, 0.0);
*/
	osgOde::BallJoint* hinget2 = new osgOde::BallJoint(world);
	hinget2 -> attach(tire2_body, axis1_body);
	hinget2 -> setAnchor(9.0, -2.0, 10.0);

	osgOde::HingeJoint* hinget3 = new osgOde::HingeJoint(world);
	hinget3 -> attach(tire3_body, axis2_body);
	hinget3 -> setAnchor(15.0, 2.0, 10.0);
	hinget3 -> setAxis(0.0, 1.0, 0.0);

	osgOde::HingeJoint* hinget4 = new osgOde::HingeJoint(world);
	hinget4 -> attach(tire4_body, axis2_body);
	hinget4 -> setAnchor(15.0, -2.0, 10.0);
	hinget4 -> setAxis(0.0, 1.0, 0.0);

	osgOde::AMotorJoint* motor1 = new osgOde::AMotorJoint(world);
	motor1 -> attach(tire3_body, axis2_body);
	motor1 -> setNumAxes(1);
	motor1 -> setAxis(0.0, -1.0, 0.0, 0, 0);
	motor1 -> setVelocity(5.0);
	motor1 -> setMaxForce(10.0);
	motor1 -> setFudge(0.9);

	osgOde::AMotorJoint* motor2 = new osgOde::AMotorJoint(world);
	motor2 -> attach(tire4_body, axis2_body);
	motor2 -> setNumAxes(1);
	motor2 -> setAxis(0.0, -1.0, 0.0, 0, 0);
	motor2 -> setVelocity(5.0);
	motor2 -> setMaxForce(10.0);
	motor2 -> setFudge(0.9);
// vehiculo
	

// Añadir a escena
  osg::Group* scene_root = new osg::Group;
  scene_root -> addChild(world);
  scene_root -> addChild(plane);
  scene_root -> addChild(wall1);
  scene_root -> addChild(wall2);


	KeyboardHandler* kh = new KeyboardHandler;
	kh -> body = body1;
	kh -> bodies[0] = body1;
	kh -> bodies[1] = spheres_bodies[0];
	kh -> bodies[2] = bricks_bodies[0];
	kh -> bodies[3] = sticks_bodies[0];
	kh -> bodies[4] = capsules_bodies[0];
	kh -> bodies[5] = tire1_body;


  osgProducer::Viewer viewer;
  viewer.setUpViewer(osgProducer::Viewer::STANDARD_SETTINGS);
  viewer.setClearColor(osg::Vec4(0.0f, 0.0f, 1.0f, 0.0f));
  viewer.setSceneData(scene_root);
	viewer.getEventHandlerList().push_front(kh);
  viewer.realize();


// Comenzar simulación física y rendereo
  while( !viewer.done() )
  {
    viewer.sync();
    viewer.update();
    viewer.frame();
  }

  viewer.sync();

  return 0;
}



bool KeyboardHandler::handle(const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa, osg::Object *oo, osg::NodeVisitor *nv)
{
	if(!body -> isEnabled())
		body -> setEnable(true);

  if(ea.getEventType() == osgGA::GUIEventAdapter::KEYDOWN)
	{
		switch(ea.getKey())
		{
			case '0':
			{
				mode = ADD_FORCE;
				return true;
			}

			case '1':
			{
				mode = ADD_TORQUE;
				return true;
			}

			case '2':
			{
				mode = ADD_REL_FORCE;
				return true;
			}

			case '3':
			{
				mode = ADD_REL_TORQUE;
				return true;
			}

			case 'g':
			{
				if(body -> isGravityApplied())
					body -> setApplyGravity(false);
				else
					body -> setApplyGravity(true);
				return true;
			}

			case '-':
			{
				f -= 25;
				return true;
			}

			case '+':
			{
				f += 25;
				return true;
			}

			case '.':
			{
//				body -> setPosition(0.0, 0.0, 10.0);
				body -> setQuaternion(0.0, 0.0, 1.0, 0.0);
				body -> setForce(0.0, 0.0, 0.0);
				body -> setTorque(0.0, 0.0, 0.0);
				body -> setVelocity(0.0, 0.0, 0.0);
				body -> setAngularVelocity(0.0, 0.0, 0.0);
				return true;
			}

			case 'n':
			{
				actual_body = (actual_body + 1) % NUM_BODIES;
				body = bodies[actual_body];
				return true;
			}

			case osgGA::GUIEventAdapter::KEY_Up:
		  {
				apply_force = true;
				force.set(0.0, f, 0.0);
				break;
			}

			case osgGA::GUIEventAdapter::KEY_Down:
		  {
				apply_force = true;
				force.set(0.0, -f, 0.0);
				break;
			}

			case osgGA::GUIEventAdapter::KEY_Left:
		  {
				apply_force = true;
				force.set(-f, 0.0, 0.0);
				break;
			}

			case osgGA::GUIEventAdapter::KEY_Right:
		  {
				apply_force = true;
				force.set(f, 0.0, 0.0);
				break;
			}

			case osgGA::GUIEventAdapter::KEY_Page_Up:
		  {
				apply_force = true;
				force.set(0.0, 0.0, f);
				break;
			}

			case osgGA::GUIEventAdapter::KEY_Page_Down:
		  {
				apply_force = true;
				force.set(0.0, 0.0, -f);
				break;
			}

		}

		if(apply_force)
		{
			switch(mode)
			{
				case ADD_FORCE:
				{
					body -> addForce(force.x(), force.y(), force.z());
					return true;
				}					

				case ADD_TORQUE:
				{
					body -> addTorque(force.x(), force.y(), force.z());
					return true;
				}					

				case ADD_REL_FORCE:
				{
					body -> addRelForce(force.x(), force.y(), force.z());
					return true;
				}					

				case ADD_REL_TORQUE:
				{
					body -> addRelTorque(force.x(), force.y(), force.z());
					return true;
				}					

			}

		}

		return false;

	}
	else if(ea.getEventType() == osgGA::GUIEventAdapter::KEYUP)
	{
		apply_force = false;
std::cout << "up ";
	}

  return false;
}

