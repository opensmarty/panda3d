// Filename: odeAMotorJoint.cxx
// Created by:  joswilso (27Dec06)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) 2001 - 2004, Disney Enterprises, Inc.  All rights reserved
//
// All use of this software is subject to the terms of the Panda 3d
// Software license.  You should have received a copy of this license
// along with this source code; you will also find a current copy of
// the license at http://etc.cmu.edu/panda3d/docs/license/ .
//
// To contact the maintainers of this program write to
// panda3d-general@lists.sourceforge.net .
//
////////////////////////////////////////////////////////////////////

#include "config_ode.h"
#include "odeAMotorJoint.h"

TypeHandle OdeAMotorJoint::_type_handle;

OdeAMotorJoint::
OdeAMotorJoint(dJointID id) : 
  OdeJoint(id) {
}

OdeAMotorJoint::
OdeAMotorJoint(OdeWorld &world) : 
  OdeJoint(dJointCreateAMotor(world.get_id(), 0)) {
}

OdeAMotorJoint::
OdeAMotorJoint(OdeWorld &world, OdeJointGroup &joint_group) : 
  OdeJoint(dJointCreateAMotor(world.get_id(), joint_group.get_id())) {
}

OdeAMotorJoint::
~OdeAMotorJoint() {
}
