#include "coord.h"

void grid(int a, int point[a][DIM], int x, int y) {
	int i, j, k, l, m, d, z;
	bool coord;
		
	for (d = 1; d < a + 1; d++) {						    // Animation loop
		puts("y = (x/6) * (sin(x/10)) + 30");
		for (k = y - 1; k >= 0; k--) {					    // graphing loop (including nesteds)
			for (l = 0; l <  a; l++) {
				for (m = 0; m < d; m++) {		       	    // Checks if x and y match counters, change d
					if (l == point[m][0] && k == point[m][1]) { // to a and comment out the highest loop
						coord = true;			    // to cancel animation
						break;
					} else
						coord = false;
				}
				if (coord == true)
					printf("█" );
				else
					printf("-");
			}
			putchar('\n');
		}		
		sleepms(75);
		if (d < a) {
			for (z = 0; z < y - 1; z++)
				putchar('\n');
		}
	}			

	return;
}

void function(int a, int point[a][DIM]) {
	int i;
	double x, y;

	for (i = 0; i < a; i++) {
		x = i;
		y = (x / 6)  * sin(.1 * x) + 30;			// function
		point[i][0] = x;					// horizontal axis;
		point[i][1] = floor(y);					// vertical axis
	}

	return;
}

void get_coord(int a, int point[a][DIM]) {
	int i, j;
	char v;
	bool coord;

	for (i = 0; i < a; i++) {
		for (j = 0; j < DIM; j++) {
			switch (j) {
				case 0: v = 'x';
				        break;
				case 1: v = 'y';
					break;
			}
			printf("Enter the %c value coordinate %d: ", v, i);
			get_int(&point[i][j]);
		}
		putchar('\n');
	}
	
	return;
}

void get_gridsize(int * x, int * y) {
	int i;

	printf("Range of x (integer > 0): ");
	get_int(x);
	while (*x <= 0) {
		printf("%d is not greater than 0.\nPlease enter an integer above 0,\nsuch as 10 or 21: ", *x);
		get_int(x);
	}
	printf("Range of y (integer > 0): ");
	get_int(y);
	while (*y <= 0) {
		printf("%d is not greater than 0.\nPlease enter an integer above 0,\nsuch as 10 or 21: ", *y);
		get_int(y);
	}

	return;
}

void get_gm(int * m) {
	printf("Graph coordinate points (0) of function (1)?: ");
	get_int(m);
	while (*m > 1 || *m < 0) {
		printf("Please enter 0 for coordinates or 1 for function: ");
		get_int(m);
	}

	return;
}

void get_int(int * a) {
	char ch;

	while ((scanf("%d", a)) != 1) {
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an integer.\nPlease enter an integer value, such as 10 or 21: ");
	}

	return;
}

void pcoord(int a,  int point[a][DIM]) {
	int i, j;
	char yn;

	printf("Show coordinates? [y/n]: ");
	get_yn(&yn);
	if (yn == 'y') {
		for (i = 0; i < a; i++) {
			printf(" %d: (", i);
			for (j = 0; j < DIM; j++)
				printf("%d, ", point[i][j]);
			printf("\b\b)\n");
		}
	}


	return;
}

void get_yn(char * ans) {

	while ((*ans = getchar())  != 'y' && *ans != 'n') {
		while (*ans != '\n')
			;
		printf("Please enter either a 'y' for yes, or an 'n' for no: ");
	}

	return;
}

void sleepms(int ms) {
	usleep(ms * 1000);
	return;
}
