#include "sphere.h"
#include <math.h>

Sphere::Sphere(int nbcircles, int nbvertices)
  : TriMesh()
{
  _name = "Sphere";

  const int nbcercle = nbcircles;
  const int nbvertex = nbvertices;
  const int nbtriangle = nbcercle*nbvertex - 2;

  // vertex coordinates
  const GLfloat v[nbcercle*nbvertex][3] = {
    //{0,0,0}, //centre du disque
    /*{-1,1,-1},{1,1,-1},{1,-1,-1},
    {-1,-1, 1},{-1,1, 1},{1,1, 1},{1,-1, 1}*/
  };

  // triangles vertex indices
  const GLint t[nbtriangle][3] = {
    /*{1,2,0},{3,0,2},  // bottom triangles
    {1,5,6},{2,1,6},{2,6,3},{3,6,7},{3,7,0},{0,7,4},{0,4,1},{1,4,5},    // side triangles
    {4,7,5},{7,6,5}   // top triangles*/
  };

  // triangle normals
  const GLint nt[nbtriangle][3] = {
    {0,0,-1},{0,0,-1}, // bottom triangle normals
    {0,1,0},{0,1,0},{1,0,0},{1,0,0},{0,-1,0},{0,-1,0},{-1,0,0},{-1,0,0}, // side triangle normals
    {0,0,1},{0,0,1}    // top triangle normals
  };

  // triangle vertex normals
  const GLint nv[nbcercle*nbvertex*3][3] = {
    {0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1}, // bottom triangle vertex normals

    {0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},       // side triangle vertex normals
    {1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
    {0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
    {-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},

    {0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}        // top triangle vertex normals
  };


  //--- Fill vertices and triangles vectors

  // Fill vertices vector

  // Fill triangles vector

  Vertex current;

  this->addVertex(0,0,1); // Point du haut

  float pas_vertex = 2*M_PI/nbvertex;
  float pas_cercle = M_PI/(nbcercle); // Nb cercles

  float angle_vertex, angle_cercle;

  int j=0;
  int i=0;

  for(i=0; i<=nbcercle-1; i++){
        angle_cercle = (M_PI/2) - (i * pas_cercle); // Calcul de la hauteur du cercle ( coordonée z )
        current.z = sin(angle_cercle);
        for(j=0; j<nbvertex; j++){
                angle_vertex = pas_vertex * j;
                current.x = cos(angle_vertex)*cos(angle_cercle); // Calcul de x
                current.y = sin(angle_vertex)*cos(angle_cercle); // Calcul de y
                this->addVertex(current);
        }
  }

  this->addVertex(0,0,-1); // Point du bas

  for(i=0; i<=nbcercle; i++){
      if( i == 0 ){
            for(j=0; j<nbvertex-1; j++){
                this->addTriangle( (i*nbvertex), (i*nbvertex)+j+1, (i*nbvertex)+j+2 );
            }
            this->addTriangle( (i*nbvertex), (i*nbvertex)+j+1, (i*nbvertex)+1 );
      }
      else if( i == nbcercle ){
           for(j=0; j<nbvertex-1; j++){
                 this->addTriangle( ((i-1)*nbvertex)+j+1, (i*nbvertex)+1, ((i-1)*nbvertex)+j+2 ); //(i*nbvertex)+1
            }
            this->addTriangle( ((i-1)*nbvertex)+j+1, (i*nbvertex)+1, ((i-1)*nbvertex)+1 ); //(i*nbvertex)+1
      }
      else{
            for(j=0; j<nbvertex-1; j++){
                this->addTriangle( ((i-1)*nbvertex)+j+1, (i*nbvertex)+j+1, (i*nbvertex)+j+2 );
                this->addTriangle( ((i-1)*nbvertex)+j+1, (i*nbvertex)+j+2, ((i-1)*nbvertex)+j+2 );
            }
            this->addTriangle( ((i-1)*nbvertex)+j+1, (i*nbvertex)+j+1, (i*nbvertex)+1 );
            this->addTriangle( ((i-1)*nbvertex)+j+1, (i*nbvertex)+1, ((i-1)*nbvertex)+1 );
      }
  }


  // Fill normals vectors
  bool use_computed_normals = true;

  if (use_computed_normals) {

      computeNormalsT();  // to be fixed
      computeNormalsV();  // to be fixed

    } else { // use manually defined normals

      // set triangle normals
      for (int i=0; i<12; ++i) {
          Normal nT(nt[i][0], nt[i][1], nt[i][2]);
          this->addNormalT(nT);
        }
      // set triangle vertex normals
      for (int i=0; i<36; ++i) {
          Normal nV(nv[i][0], nv[i][1], nv[i][2]);
          this->addNormalV(nV);
        }
    }

}
