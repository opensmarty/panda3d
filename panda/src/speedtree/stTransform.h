// Filename: stTransform.h
// Created by:  drose (06Oct10)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#ifndef STTRANSFORM_H
#define STTRANSFORM_H

#include "pandabase.h"
#include "transformState.h"
#include "speedtree_api.h"
#include "deg_2_rad.h"

////////////////////////////////////////////////////////////////////
//       Class : STTransform
// Description : Represents a transform that may be applied to a
//               particular instance of a tree when added to the
//               SpeedTreeNode.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDASPEEDTREE STTransform {
PUBLISHED:
  INLINE STTransform();
  STTransform(const TransformState *trans);
  INLINE STTransform(const LPoint3f &pos, float rotate = 0.0f, float scale = 1.0f);
  INLINE STTransform(float x, float y, float z, float rotate, float scale);
  INLINE STTransform(const STTransform &copy);
  INLINE void operator = (const STTransform &copy);

public:
  INLINE STTransform(const SpeedTree::CInstance &instance);
  INLINE operator SpeedTree::CInstance () const;
  INLINE operator CPT(TransformState) () const;

PUBLISHED:
  INLINE static const STTransform &ident_mat();

  INLINE void set_pos(const LPoint3f &pos);
  INLINE const LPoint3f &get_pos() const;
  INLINE void set_rotate(float rotate);
  INLINE float get_rotate() const;
  INLINE void set_scale(float scale);
  INLINE float get_scale() const;

  INLINE void operator *= (const STTransform &other);
  INLINE STTransform operator * (const STTransform &other) const;

  void output(ostream &out) const;

public:
  void write_datagram(BamWriter *manager, Datagram &dg);
  void fillin(DatagramIterator &scan, BamReader *manager);

public:
  LPoint3f _pos;
  float _rotate;
  float _scale;

  static STTransform _ident_mat;
};

INLINE ostream &operator << (ostream &out, const STTransform &transform) {
  transform.output(out);
  return out;
}

#include "stTransform.I"

#endif