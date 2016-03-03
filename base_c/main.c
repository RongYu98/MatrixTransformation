#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;
  struct matrix *transform;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  ident( edges );
  ident( transform );
  scalar_mult(20, edges );
  print_matrix(edges);
  grow_matrix(edges, 5);
  print_matrix(edges);
  matrix_mult(transform, edges );
  print_matrix(transform);
  print_matrix(edges);
  
  free_matrix( transform );
  free_matrix( edges );
}  
