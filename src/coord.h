#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#define DIM 2 					  // The amount of dimensions. This is pretty much here as 2 
						  // unil I rewrite the program to handle the coordinate 
						  // array differently to support multiple dimensions.

void grid(int a, int point[][DIM], int x, int y); // Receives coordinate input and displays the graph and coordinates.
void get_gridsize(int * x, int * y); 		  // Assigns input to make the graph of a certain size.
void get_int(int * a);
void get_yn(char * ans);			  // Handling input when asking the user if they want to graph another grid of coordinates.
void get_coord(int a, int point[a][DIM]);	  // Gets coordinate values from user
void function(int a, int point[a][DIM]);	  //uses pre-defined function
void sleepms(int ms);
void pcoord(int a,  int point[a][DIM]);
