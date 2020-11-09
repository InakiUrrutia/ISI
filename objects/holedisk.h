/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Holedisk
 *
 */
#ifndef  _Holedisk_H_
#define  _Holedisk_H_

#include "triMesh.h"
#include <iostream>

/**
 * Holedisk Object
 *
 */
class Holedisk : public TriMesh {
public:
  Holedisk(int nbvertices);
  virtual ~Holedisk(){};

};

#endif
