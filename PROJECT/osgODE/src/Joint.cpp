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

#include <osgOde/Joint>

namespace osgOde{

    void Joint::destroy()
    {
        dJointDestroy(ode_joint);
    }

    void Joint::setData(void* data)
    {
        dJointSetData(ode_joint, data);
    }

    void* Joint::getData() const
    {
        return dJointGetData(ode_joint);
    }

    void Joint::attach(Body* b1, Body* b2 = 0)
    {
        dJointAttach(ode_joint, b1 -> ode_body, b2 ? b2 -> ode_body : 0);
    }

    int Joint::getType() const
    {
        return dJointGetType(ode_joint);
    }

    bool Joint::areConnected(Body* b1, Body* b2) const
    {
        return (dAreConnected(b1 -> ode_body, b2 -> ode_body) == 1);
    }

    bool Joint::areConnectedExcluding(Body* b1, Body* b2, int type) const
    {
        return (dAreConnectedExcluding(b1 -> ode_body, b2 -> ode_body, type) == 1);
    }

    BallJoint::BallJoint(World* w)
    {
        ode_joint = dJointCreateBall(w -> ode_world, 0);
    };

    void BallJoint::setAnchor(double x, double y, double z)
    {
        dJointSetBallAnchor(ode_joint, x, y, z);
    }

    HingeJoint::HingeJoint(World* w)
    {
        ode_joint = dJointCreateHinge(w -> ode_world, 0);
    };

    void HingeJoint::setAnchor(double x, double y, double z)
    {
        dJointSetHingeAnchor(ode_joint, x, y, z);
    }

    void HingeJoint::setAxis(double x, double y, double z)
    {
        dJointSetHingeAxis(ode_joint, x, y, z);
    }

    void HingeJoint::setLimits(double lo, double hi)
    {
        dJointSetHingeParam(ode_joint, dParamLoStop, lo);
        dJointSetHingeParam(ode_joint, dParamHiStop, hi);
    }

    void HingeJoint::setBounciness(double b)
    {
        dJointSetHingeParam(ode_joint, dParamBounce, b);
    }

    void HingeJoint::setCFM(double cfm)
    {
        dJointSetHingeParam(ode_joint, dParamCFM, cfm);
    }

    void HingeJoint::setSoftness(double erp, double cfm)
    {
        dJointSetHingeParam(ode_joint, dParamStopERP, erp);
        dJointSetHingeParam(ode_joint, dParamStopCFM, cfm);
    }

    void HingeJoint::setTorque(double f)
    {
        dJointAddHingeTorque(ode_joint, f);
    }

    SliderJoint::SliderJoint(World* w)
    {
        ode_joint = dJointCreateSlider(w -> ode_world, 0);
    };

    void SliderJoint::setAxis(double x, double y, double z)
    {
        dJointSetSliderAxis(ode_joint, x, y, z);
    }

    void SliderJoint::setLimits(double lo, double hi)
    {
        dJointSetSliderParam(ode_joint, dParamLoStop, lo);
        dJointSetSliderParam(ode_joint, dParamHiStop, hi);
    }

    void SliderJoint::setBounciness(double b)
    {
        dJointSetSliderParam(ode_joint, dParamBounce, b);
    }

    void SliderJoint::setCFM(double cfm)
    {
        dJointSetSliderParam(ode_joint, dParamCFM, cfm);
    }

    void SliderJoint::setSoftness(double erp, double cfm)
    {
        dJointSetSliderParam(ode_joint, dParamStopERP, erp);
        dJointSetSliderParam(ode_joint, dParamStopCFM, cfm);
    }

    void SliderJoint::setForce(double f)
    {
        dJointAddSliderForce(ode_joint, f);
    }

    UniversalJoint::UniversalJoint(World* w)
    {
        ode_joint = dJointCreateUniversal(w -> ode_world, 0);
    };

    void UniversalJoint::setAnchor(double x, double y, double z)
    {
        dJointSetUniversalAnchor(ode_joint, x, y, z);
    }

    void UniversalJoint::setAxis1(double x, double y, double z)
    {
        dJointSetUniversalAxis1(ode_joint, x, y, z);
    }

    void UniversalJoint::setAxis2(double x, double y, double z)
    {
        dJointSetUniversalAxis2(ode_joint, x, y, z);
    }

    void UniversalJoint::setLimits(double lo, double hi, double lo2 = -dInfinity, double hi2  = dInfinity)
    {
        dJointSetUniversalParam(ode_joint, dParamLoStop, lo);
        dJointSetUniversalParam(ode_joint, dParamHiStop, hi);
        dJointSetUniversalParam(ode_joint, dParamLoStop2, lo2);
        dJointSetUniversalParam(ode_joint, dParamHiStop2, hi2);
    }

    void UniversalJoint::setBounciness(double b, double b2 = 0.0)
    {
        dJointSetUniversalParam(ode_joint, dParamBounce, b);
        dJointSetUniversalParam(ode_joint, dParamBounce2, b2);
    }

    void UniversalJoint::setCFM(double cfm, double cfm2 = 0.0)
    {
        dJointSetUniversalParam(ode_joint, dParamCFM, cfm);
        dJointSetUniversalParam(ode_joint, dParamCFM2, cfm2);
    }

    void UniversalJoint::setSoftness(double erp, double cfm, double erp2 = 0.0, double cfm2 = 0.0)
    {
        dJointSetUniversalParam(ode_joint, dParamStopERP, erp);
        dJointSetUniversalParam(ode_joint, dParamStopCFM, cfm);
        dJointSetUniversalParam(ode_joint, dParamStopERP2, erp2);
        dJointSetUniversalParam(ode_joint, dParamStopCFM2, cfm2);
    }

    void UniversalJoint::setTorque(double f, double f2)
    {
        dJointAddUniversalTorques(ode_joint, f, f2);
    }

    Hinge2Joint::Hinge2Joint(World* w)
    {
        ode_joint = dJointCreateHinge2(w -> ode_world, 0);
    };

    void Hinge2Joint::setAnchor(double x, double y, double z)
    {
        dJointSetHinge2Anchor(ode_joint, x, y, z);
    }

    void Hinge2Joint::setAxis1(double x, double y, double z)
    {
        dJointSetHinge2Axis1(ode_joint, x, y, z);
    }

    void Hinge2Joint::setAxis2(double x, double y, double z)
    {
        dJointSetHinge2Axis2(ode_joint, x, y, z);
    }

    void Hinge2Joint::setLimits(double lo, double hi, double lo2, double hi2)
    {
        dJointSetHinge2Param(ode_joint, dParamLoStop, lo);
        dJointSetHinge2Param(ode_joint, dParamLoStop2, lo2);
        dJointSetHinge2Param(ode_joint, dParamHiStop, hi);
        dJointSetHinge2Param(ode_joint, dParamHiStop2, hi2);
    }

    void Hinge2Joint::setBounciness(double b, double b2 = 0.0)
    {
        dJointSetHinge2Param(ode_joint, dParamBounce, b);
        dJointSetHinge2Param(ode_joint, dParamBounce2, b2);
    }

    void Hinge2Joint::setCFM(double cfm, double cfm2 = 0.0)
    {
        dJointSetHinge2Param(ode_joint, dParamCFM, cfm);
        dJointSetHinge2Param(ode_joint, dParamCFM2, cfm2);
    }

    void Hinge2Joint::setSoftness(double erp, double cfm, double erp2, double cfm2)
    {
        dJointSetHinge2Param(ode_joint, dParamStopERP, erp);
        dJointSetHinge2Param(ode_joint, dParamStopCFM, cfm);
        dJointSetHinge2Param(ode_joint, dParamStopERP2, erp2);
        dJointSetHinge2Param(ode_joint, dParamStopCFM2, cfm2);
    }

    void Hinge2Joint::setTorque(double f, double f2 = 0.0)
    {
        dJointAddHinge2Torques(ode_joint, f, f2);
    }

    void Hinge2Joint::setSuspension(double erp, double cfm)
    {
        dJointSetHinge2Param(ode_joint, dParamSuspensionERP, erp);
        dJointSetHinge2Param(ode_joint, dParamSuspensionCFM, cfm);
    }

    AMotorJoint::AMotorJoint(World* w)
    {
        ode_joint = dJointCreateAMotor(w -> ode_world, 0);
    };

    void AMotorJoint::setNumAxes(int n)
    {
        dJointSetAMotorNumAxes(ode_joint, n);
    }

    void AMotorJoint::setAxis(double x, double y, double z, int n, int rel)
    {
        dJointSetAMotorAxis(ode_joint, n, rel, x, y, z);
    }

    void AMotorJoint::setTorque(double t1, double t2, double t3)
    {
        dJointAddAMotorTorques(ode_joint, t1, t2, t3);
    }

    void AMotorJoint::setVelocity(double v, double v2, double v3)
    {
        dJointSetAMotorParam(ode_joint, dParamVel, v);
    }

    void AMotorJoint::setMaxForce(double f, double f2, double f3)
    {
        dJointSetAMotorParam(ode_joint, dParamFMax, f);
    }

    void AMotorJoint::setFudge(double f, double f2, double f3)
    {
        dJointSetAMotorParam(ode_joint, dParamFudgeFactor, f);
    }

}
