
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
  i = 1;
  for (x = 0; x<4; x++){
    for (y = 0; y<4; y++){
      edges->m[x][y] = i;
      transform->m[x][y] = i+3;
      i++;
    }
  }
  */
  //print_matrix(edges);
  //print_matrix(transform);
  /*
  matrix_mult(edges, transform);
  print_matrix(transform);
  add_edge(edges, 200, 200,1, 200, 300, 1);
  add_edge(edges, 200,300,1, 300, 300,1);
  add_edge(edges, 300,300,1, 300,200,1);
  add_edge(edges, 300,200,1, 200,200,1);
  */

  add_edge(edges,200,200,1,300,300,1);
  add_edge(edges,200,300,1,300,200,1);
  add_edge(edges,200,250,1,300,250,1);
  add_edge(edges,250,200,1,250,300,1);
  draw_lines(edges, s, c);

  struct matrix *big;
  struct matrix *temp = new_matrix(4,4);
  ident(temp);
  struct matrix * rotatedZ;
  for (i=0; i<20; i++){
    rotatedZ = make_rotZ(i/10);
    //printf("1\n");
    matrix_mult(rotatedZ, edges);
    print_matrix(edges);
    printf("%d\n",i);
    //printf("2\n");
    /*
    copy_matrix(edges, temp);
    printf("2\n");
    matrix_mult(rotatedZ, temp);
    draw_lines(temp,s,c);
    big = make_scale(i%5, (i+1)%5, (i+2)%5);
    printf("3\n");
    matrix_mult(big, temp);
    draw_lines(temp,s,c);
    */
    
    //matrix_mult(rotatedZ, edges);
    draw_lines(edges,s,c);
    if (i%2 == 0){
      big = make_scale(  .7, 1.5,1 );
    } else {
      big = make_scale(1.5, .7,1 );
    }
    matrix_mult(big, edges);
    draw_lines(edges, s,c);
  }
  print_matrix(edges);
  draw_lines(edges, s, c);
  
  //save_ppm( s, "pic.ppm" );
  save_extension(s, "lines.png");
  free_matrix( transform );
  free_matrix( edges );
}

