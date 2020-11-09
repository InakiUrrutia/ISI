/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Cylinder
 *
 */
#ifndef  _Cylinder_H_
#define  _Cylinder_H_

#include "triMesh.h"
#include <iostream>

/**
 * Cylinder Object
 *
 */
class Cylinder : public TriMesh {
public:
  Cylinder(int nbcircles, int nbvertices);
  virtual ~Cylinder(){};

};

#endif
