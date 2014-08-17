#include "support.c"

int main(void) {
	int xsize, ysize, i, j, amnt, gm;
	char v, status = 'y';

	printf("\n******************************************\n"
	         "      Welcome to Shintoo's grapher.\n"
	         "Begin by entering the range of the window.\n");
	get_gridsize(&xsize, &ysize);
	get_gm(&gm);
	switch (gm) {
		case 0: printf("Amount of coordinates to be graphed: ");
		        get_int(&amnt);
		        break;
		case 1: amnt = xsize - 1;					// The function coordinates extend to
	}									// the end of the graph
	int point[amnt][DIM];
	switch (gm) {
		case 0: get_coord(amnt, point);
			break;
		case 1: function(amnt, point);
	}
	grid(amnt, point, xsize, ysize);
//	pcoord(amnt, point);

	return 0;
}
