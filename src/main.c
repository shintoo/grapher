#include "support.c"

int main(void) {
	int xsize, ysize, i, j, amnt, gm;
	char v, status = 'y';

	printf("\n******************************************\n"
	         "      Welcome to Shintoo's grapher.\n"
	         "Begin by entering the range of the window.\n");
	get_gridsize(&xsize, &ysize);
	printf("Graph coordinate points (0) or function (1)?: ");
	get_int(&gm);
	while (gm > 1 || gm < 0) {
		printf("Please enter 0 for coordinates or 1 for function: ");
		get_int(&gm);
	}
	printf("Amount of coordinates to be graphed: ");
	get_int(&amnt);
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
