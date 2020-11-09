/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Cone
 *
 */
#ifndef  _Cone_H_
#define  _Cone_H_

#include "triMesh.h"
#include <iostream>

/**
 * Cone Object
 *
 */
class Cone : public TriMesh {
public:
  Cone(int nbvertices);
  virtual ~Cone(){};

};

#endif
