/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Sphere
 *
 */
#ifndef  _Sphere_H_
#define  _Sphere_H_

#include "triMesh.h"
#include <iostream>

/**
 * Sphere Object
 *
 */
class Sphere : public TriMesh {
public:
  Sphere(int nbcircles, int nbvertices);
  virtual ~Sphere(){};

};

#endif
