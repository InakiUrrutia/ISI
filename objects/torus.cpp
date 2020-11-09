#include "torus.h"

Torus::Torus(int nbvertices)
  : TriMesh()
{
  _name = "Torus";

  const int nbvertex = nbvertices;
  const int nbtriangle = nbvertex*nbvertex - 2;

  // vertex coordinates
  const GLfloat v[nbvertex*nbvertex][3] = {
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
  const GLint nv[nbvertex*nbvertex*3][3] = {
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

  float pas_angle, angle1, angle2, rayon;

  rayon = 1.0/3;

  pas_angle = 2*M_PI/nbvertex;

  for(int i=0; i<nbvertex; i++){
      angle1 = i*pas_angle;
      //this->addVertex(cos(angle1),sin(angle1),0); centre de chaque cercle du torus
      for(int j=0; j<nbvertex; j++){
          angle2 = j*pas_angle;
          current.x=((1-rayon)+rayon*cos(angle2))*cos(angle1);
          current.y=((1-rayon)+rayon*cos(angle2))*sin(angle1);
          current.z=rayon*sin(angle2);
          this->addVertex(current);
          /*if(j>=2){ // Pour tester que les sommets sont bien placés
              this->addTriangle(i*nbvertex, i*nbvertex+j-1, i*nbvertex+j);
          }*/
      }
  }

  for(int i=0; i<=nbvertex-1; i++){
      if(i == nbvertex-1){
          for(int j=0; j<=nbvertex-1; j++){
              if(j == nbvertex-1){
                    this->addTriangle(i*nbvertex, i*nbvertex+j, j);
                    this->addTriangle(j, 0, i*nbvertex);
              }
              else{
                    this->addTriangle(i*nbvertex+j+1, i*nbvertex+j, j);
                    this->addTriangle(i*nbvertex+j+1, j, j+1);
              }
          }
      }
      else{
          for(int j=0; j<=nbvertex-1; j++){
              if(j == nbvertex-1){
                    this->addTriangle(i*nbvertex, i*nbvertex+j, (i+1)*nbvertex+j);
                    this->addTriangle((i+1)*nbvertex+j, (i+1)*nbvertex, i*nbvertex);
              }
              else{
                    this->addTriangle(i*nbvertex+j+1, i*nbvertex+j, (i+1)*nbvertex+j);
                    this->addTriangle(i*nbvertex+j+1, (i+1)*nbvertex+j, (i+1)*nbvertex+j+1);
              }
          }
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
