/**
 * @author Bruno Jobard
 * @date   Oct 2012
 *
 *  Defines a 3D Cone
 *
 */
#ifndef  _FUNCSURFACE_H_
#define  _FUNCSURFACE_H_

#include "triMesh.h"
#include <iostream>
#include <cmath>

/**
 * Surface Function Object
 *
 */
class FuncSurface : public TriMesh {
public:
  FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float(*func)(float, float)=NULL);
  static float func_expcos(float x, float y);
  static float func_cosi(float x, float y);
  virtual ~FuncSurface(){};
};

#endif
