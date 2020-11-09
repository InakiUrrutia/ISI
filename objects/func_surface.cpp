#include "func_surface.h"

float FuncSurface::func_expcos(float x, float y){
    return exp(-(x*x/2+y*y/2))*cos(2*x*x+2*y*y);
}

float FuncSurface::func_cosi(float x, float y){
    return cos(x)*sin(y);
}

FuncSurface::FuncSurface(int nbx, int nby, float minx, float maxx, float miny, float maxy, float(*func)(float,float))
    : TriMesh()
{
  _name = "Fonction de surface";

  float xmin = minx;
  float xmax = maxx;
  float ymin = miny;
  float ymax = maxy;
  float zmin = 0;
  float zmax = 0;

  float pas_x = (maxx-minx)/nbx;
  float pas_y = (maxy-miny)/nby;

  float x = minx;
  float y = miny;
  float z;

  int cpt = 0;
  int nbline;

  Vertex current;

  // Calcul des points

  for(int i=0; i<nbx; i++){
        x = minx + i*pas_x;
        current.x = x;
        nbline = 0;
        for(int j=0; j<nby; j++){
                y = miny + j*pas_y;
                current.y = y;
                z = (*func)(x,y);
                if(z>zmax){
                    zmax = z;
                }
                if(z<zmin){
                    zmin = z;
                }
                current.z = z;
                this->addVertex(current);
                if(x>minx && nbline != 0){
                    this->addTriangle(cpt-nby-1, cpt-1, cpt-nby);
                    this->addTriangle(cpt-1, cpt, cpt-nby);
                }
                cpt++;
                nbline++;

        }
  }

  // Ramener les points entre -1 et 1

  float decalage;

  for(int i=0; i<_vertices.size(); i++){
      decalage = (xmax + xmin)/2.0;
      _vertices[i][0] = _vertices[i][0] - decalage;
      _vertices[i][0] = _vertices[i][0] / (xmax - decalage);
      decalage = (ymax + ymin)/2.0;
      _vertices[i][1] = _vertices[i][1] - decalage;
      _vertices[i][1] = _vertices[i][1] / (ymax - decalage);
      decalage = (zmax + zmin)/2.0;
      _vertices[i][2] = _vertices[i][2] - decalage;
      _vertices[i][2] = _vertices[i][2] / (zmax - decalage);
  }

  computeNormalsT();
  computeNormalsV();

}
