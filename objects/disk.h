/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Disk
 *
 */
#ifndef  _Disk_H_
#define  _Disk_H_

#include "triMesh.h"
#include <iostream>

/**
 * Disk Object
 *
 */
class Disk : public TriMesh {
public:
  Disk(int nbvertices);
  virtual ~Disk(){};

};

#endif
