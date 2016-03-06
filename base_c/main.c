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
  /*
  scalar_mult(20, edges );
  print_matrix(edges);
  grow_matrix(edges, 5);
  print_matrix(edges);
  matrix_mult(transform, edges );
  print_matrix(transform);
  print_matrix(edges);
  */
  color c;
  c.red = 0;
  c.green = 45;
  c.blue = 200;
  int x, y, x1, y1, i;
  /*
  for (i = 0; i<10; i++ ){
    x = 9*sin(i)*sin(i) + 9*sin(i);
    y = 9*sin(i)*sin(i) + 9*sin(i);
    x1 = 9*cos(i+1)*cos(i+1) + 9*cos(i+1);
    y1 = 9*cos(i+1)*cos(i+1) + 9*cos(i+1);
    add_edge( edges, x,y,1, x1,y1,1);
  }
  */
  i = 1;
  for (x = 0; x<4; x++){
    for (y = 0; y<4; y++){
      edges->m[x][y] = i;
      transform->m[x][y] = i+3;
      i++;
    }
  }
  
  print_matrix(edges);
  print_matrix(transform);
  /*
  matrix_mult(edges, transform);
  print_matrix(transform);
  */
  
  draw_lines(edges, s, c);

  //save_ppm( s, "pic.ppm" );
  save_extension(s, "lines.png");
  free_matrix( transform );
  free_matrix( edges );
}

