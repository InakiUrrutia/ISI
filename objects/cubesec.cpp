#include "cubesec.h"

Cubesec::Cubesec()
  : TriMesh()
{
  _name = "Cubesec";

  // vertex coordinates
  static const GLfloat v[10][3] = {
      {-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},              //points du bas
      {-1,-1, 1},{-1,1, 1},/*8ème -> 7ème*/{1,-1, 1},       //points du haut
      {0,1, 1},{1,1, 0},{1,0, 1}                            //points de l'angle cassé
  };

  // triangles vertex indices
  static const GLint t[16][3] = {
    {0,1,2},{2,3,0},                                        // bottom triangles
    {3,6,0},{0,6,4},{0,4,1},{1,4,5},                        // side triangles
    {9,4,6},{7,4,9},{7,5,4},                                // top triangles
    {7,1,5},{7,8,1},{8,2,1},                                // right triangle
    {3,2,8},{8,9,3},{9,6,3},                                // front triangle
    {8,7,9}                                                 // broken angle triangle
  };

  // triangle normals
  static const GLint nt[16][3] = {
      {0,0,-1},{0,0,-1},                                    // bottom triangles
      {0,-1,0},{0,-1,0},{-1,0,0},{-1,0,0},                  // side triangles
      {0,0,1},{0,0,1},{0,0,1},                              // top triangles
      {0,1,0},{0,1,0},{0,1,0},                              // right triangle
      {1,0,0},{1,0,0},{1,0,0},                              // front triangle
      {1,1,1}                                               // broken angle triangle
  };

  // triangle vertex normals
  static const GLint nv[36][3] = {
    {0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},{0,0,-1},  // bottom triangle vertex normals

    {0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0},        // side triangle vertex normals
    {1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},{1,0,0},
    {0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},{0,-1,0},
    {-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},{-1,0,0},

    {0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1},{0,0,1}         // top triangle vertex normals
  };


  for (int i=0; i<10 ; ++i)
    this->addVertex(v[i][0], v[i][1], v[i][2]);

  for (int i=0; i<16; ++i)
    this->addTriangle(t[i][0], t[i][1], t[i][2]);

  // Fill normals vectors
  bool use_computed_normals = true;

  if (use_computed_normals) {

      computeNormalsT();                                    // to be fixed
      //computeNormalsV();                                  // to be fixed

    } else { // use manually defined normals

      // set triangle normals
      for (int i=0; i<16; ++i) {
          Normal nT(nt[i][0], nt[i][1], nt[i][2]);
          this->addNormalT(nT);
        }
      // set triangle vertex normals
      for (int i=0; i<48; ++i) {
          Normal nV(nv[i][0], nv[i][1], nv[i][2]);
          this->addNormalV(nV);
        }
    }

}
