#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

/*-------------- struct matrix *new_matrix() --------------
Inputs:  int rows
         int cols 
Returns: 

Once allocated, access the matrix as follows:
m->m[r][c]=something;
if (m->lastcol)... 
*/
struct matrix *new_matrix(int rows, int cols) {
  double **tmp;
  int i;
  struct matrix *m;

  tmp = (double **)malloc(rows * sizeof(double *));
  for (i=0;i<rows;i++) {
      tmp[i]=(double *)malloc(cols * sizeof(double));
    }

  m=(struct matrix *)malloc(sizeof(struct matrix));
  m->m=tmp;
  m->rows = rows;
  m->cols = cols;
  m->lastcol = 0;

  return m;
}


/*-------------- void free_matrix() --------------
Inputs:  struct matrix *m 
Returns: 

1. free individual rows
2. free array holding row pointers
3. free actual matrix
*/
void free_matrix(struct matrix *m) {

  int i;
  for (i=0;i<m->rows;i++) {
      free(m->m[i]);
    }
  free(m->m);
  free(m);
}


/*======== void grow_matrix() ==========
Inputs:  struct matrix *m
         int newcols 
Returns: 

Reallocates the memory for m->m such that it now has
newcols number of collumns
====================*/
void grow_matrix(struct matrix *m, int newcols) {
  
  int i;
  for (i=0;i<m->rows;i++) {
      m->m[i] = realloc(m->m[i],newcols*sizeof(double));
  }
  m->cols = newcols;
}


/*-------------- void print_matrix() --------------
Inputs:  struct matrix *m 
Returns: 

print the matrix
*/
void print_matrix(struct matrix *m) {
  double stuff[ (m->lastcol * 3) + 4]; // plus 3 \n and a null
  int r,c;
  int count = 0;
  for (r=0;r<3;r++){
    for (c=0;c< (m->lastcol) ; c++){
      stuff[ count ] = m->m[r][c];
      printf("%f-%d ", stuff[count], count);
      printf("%f ", m->m[r][c]);
      count += 1;
    }
    stuff[count] = '\n';
    count += 1;
  }
  stuff[count] = '\0';
  int i = 0;
  while (stuff[i]){
    printf("%c", stuff[i]);
    i++;
  }
  printf("MATRIX START: \n%f\nMATRIX END\n", stuff);
}

/*-------------- void ident() --------------
Inputs:  struct matrix *m <-- assumes m is a square matrix
Returns: 

turns m in to an identity matrix
*/
void ident(struct matrix *m) {
  int x,y;
  for (x=0;x<4;x++){
    y = 0;
    for(y=0;y < 4; y++){      
      if (x==y){
	m->m[x][y] = 1;
	//printf("1 ");
      } else {
	m->m[x][y] = 0;
	//printf("0 ");
      }
    }
    //printf("\n");
  }
}

/*-------------- void scalar_mult() --------------
Inputs:  double x
         struct matrix *m 
Returns: 

multiply each element of m by x
*/
void scalar_mult(double x, struct matrix *m) {
  int r = 0;
  int c = 0;
  while (r<3){
    while (c < m->lastcol ){
      m->m[r][c] *= x;
      c++;
    }
    r++;
  }
}


/*-------------- void matrix_mult() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

a*b -> b
*/
void matrix_mult(struct matrix *a, struct matrix *b) {
}



/*-------------- void copy_matrix() --------------
Inputs:  struct matrix *a
         struct matrix *b 
Returns: 

copy matrix a to matrix b
*/
void copy_matrix(struct matrix *a, struct matrix *b) {

  int r, c;

  for (r=0; r < a->rows; r++) 
    for (c=0; c < a->cols; c++)  
      b->m[r][c] = a->m[r][c];  
}

/*======== struct matrix * make_translate() ==========
Inputs:  int x
         int y
         int z 
Returns: The translation matrix created using x, y and z 
as the translation offsets.
====================*/
struct matrix * make_translate(double x, double y, double z) {

  struct matrix *ad;
  ad = new_matrix(4,4);
  ident( ad );

  ad->m[0][3] = x;
  ad->m[1][3] = y;
  ad->m[2][3] = z;
  /*

  [1 0 0 a		[x		[x + a
 0 1 0 b	*	 y	=	 y + b 
 0 0 1 c			 z		 z + c
 0 0 0 1]		 1]		 1]
  */
  
}

/*======== struct matrix * make_scale() ==========
Inputs:  int x
         int y
         int z 
Returns: The translation matrix creates using x, y and z
as the scale factors
====================*/
struct matrix * make_scale(double x, double y, double z) {
}

/*======== struct matrix * make_rotX() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and X as the axis of rotation.
====================*/
struct matrix * make_rotX(double theta) {
}

/*======== struct matrix * make_rotY() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and Y as the axis of rotation.
====================*/
struct matrix * make_rotY(double theta) {
}

/*======== struct matrix * make_rotZ() ==========
Inputs:  double theta

Returns: The rotation matrix created using theta as the 
angle of rotation and Z as the axis of rotation.
====================*/
struct matrix * make_rotZ(double theta) {
}
