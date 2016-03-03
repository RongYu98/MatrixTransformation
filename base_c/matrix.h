#ifndef MATRIX_H
#define MATRIX_H

struct matrix {
  double **m;
  int rows, cols;
  int lastcol;
} matrix;

//Basic matrix manipulation routines
struct matrix *new_matrix(int rows, int cols); //dw
void free_matrix(struct matrix *m); //dw
void grow_matrix(struct matrix *m, int newcols);  //dw
void copy_matrix(struct matrix *a, struct matrix *b); //dw
void print_matrix(struct matrix *m); //done
void ident(struct matrix *m); //done //tested..... the lastcol wasn't set....
void scalar_mult(double x, struct matrix *m); //done , forgot c=0 
void matrix_mult(struct matrix *a, struct matrix *b);
struct matrix * make_translate(double x, double y, double z); //done, untested
struct matrix * make_scale(double x, double y, double z);
struct matrix * make_rotX(double theta);
struct matrix * make_rotY(double theta);
struct matrix * make_rotZ(double theta);

#endif
