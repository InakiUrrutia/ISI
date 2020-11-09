#include "cylinder.h"

Cylinder::Cylinder(int nbcircles, int nbvertices)
  : TriMesh()
{
  _name = "Cylinder";

  const int nbcercle = nbcircles;
  const int nbvertex = nbvertices*nbcircles;
  const int nbtriangle = nbvertex - 2;

  // vertex coordinates
  const GLfloat v[nbvertex][3] = {
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
  const GLint nv[nbvertex*3][3] = {
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

  float angle;

  float pas = 2.0/(nbcercle - 1);
  int j=0;
  int i=0;

  for(j=0; j<nbcercle; j++){

         current.z = 1.0-(j*pas);

         this->addVertex(0,0,current.z); //centre
         this->addVertex(1,0,current.z);
         for(i=1; i<(nbvertex/nbcercle); i++){ //generation d'un cercle
            angle = 2*M_PI*i/(nbvertex/nbcercle);
            current.x = cos(angle);
            current.y = sin(angle);
            this->addVertex(current);
            if( j == 0 ){
                this->addTriangle(j*(nbvertex/nbcercle)+j, j*(nbvertex/nbcercle)+j+i, j*(nbvertex/nbcercle)+j+i+1);
            }
            else if( j==nbcercle-1){
                 this->addTriangle(j*(nbvertex/nbcercle)+j+i, j*(nbvertex/nbcercle)+j, j*(nbvertex/nbcercle)+j+i+1);
            }
         }
         if( j==0 ){
            this->addTriangle(j*(nbvertex/nbcercle)+j+1, j*(nbvertex/nbcercle)+j, j*(nbvertex/nbcercle)+(nbvertex/nbcercle)+j);
         }
         else if(j==nbcercle-1){
             this->addTriangle(j*(nbvertex/nbcercle)+j, j*(nbvertex/nbcercle)+j+1, j*(nbvertex/nbcercle)+(nbvertex/nbcercle)+j);
         }
  }

  i=0;

  for(j=0; j<nbcercle-1; j++){
      for(i=1; i<(nbvertex/nbcercle); i++){
            this->addTriangle(j*(nbvertex/nbcercle)+j+i, (j+1)*(nbvertex/nbcercle)+j+i+1, (j+1)*(nbvertex/nbcercle)+j+i+2);
            this->addTriangle(j*(nbvertex/nbcercle)+j+i+1, j*(nbvertex/nbcercle)+j+i, (j+1)*(nbvertex/nbcercle)+j+i+2);
      }
      this->addTriangle((j+1)*(nbvertex/nbcercle)+j+2 ,j*(nbvertex/nbcercle)+j+1 , (j+1)*(nbvertex/nbcercle)+j+i+1);
      this->addTriangle(j*(nbvertex/nbcercle)+j+1 ,j*(nbvertex/nbcercle)+j+i , (j+1)*(nbvertex/nbcercle)+j+i+1);
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
