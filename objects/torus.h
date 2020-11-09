/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Torus
 *
 */
#ifndef  _Torus_H_
#define  _Torus_H_

#include "triMesh.h"
#include <iostream>

/**
 * Torus Object
 *
 */
class Torus : public TriMesh {
public:
  Torus(int nbvertices);
  virtual ~Torus(){};

};

#endif
