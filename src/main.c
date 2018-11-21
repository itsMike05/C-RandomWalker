#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
/*
		RANDOM WALKER 
1. Algorithm draws random number between 0 and 6
2. Based on the 6 draws, the direction step is defined
3. When length of the vector from start to end reaches 100, the algorithm stops

		Vector (100.0) requires about (5 - 8) seconds and (6 - 9.5) thousand iterations to find
		Vector (1000.0) requires about (2 - 4) minutes and (1.5 - 4) million iterations to find
*/
clock_t start, stop;				

int draw()									
{
	return rand()%11;				
}
void main()
{
	srand((unsigned int)time(NULL));
	int direction, count;
	double x_p, y_p, z_p, x_s, y_s, z_s, length;
	float operating_time;
	length = 0.0;					
	count = 0;						

	x_s = draw();				
	y_s = draw();				
	z_s = draw();				

	x_p = x_s;						
	y_p = y_s;						
	z_p = z_s;						
	printf("Start position = (%.1f, %.1f, %.1f)", x_s, y_s, z_s);
	getchar();

	start = clock();				

	while (length <= 100.0)			 
	{
		direction = rand()%6;		
		if (direction == 0) {
			y_p = y_p + 1.0;		
			count++;
		}
		else if (direction == 1) {
			y_p = y_p - 1.0;		
			count++;
		}
		else if (direction == 2) {
			x_p = x_p + 1.0;		
			count++;
		}
		else if (direction == 3) {
			x_p = x_p - 1.0;		
			count++;
		}
		else if (direction == 4) {
			z_p = z_p + 1.0;		
			count++;
		}
		else if (direction == 5) {
			z_p = z_p - 1.0;		
			count++;
		}
		length = sqrt(((x_p-x_s)*(x_p-x_s))+((y_p-x_s)*(y_p-x_s))+((z_p-z_s)*(z_p-z_s)));
		printf("Current iteration : %d\n", count);
	}
	stop = clock();				
	operating_time = (stop - start) / CLOCKS_PER_SEC;
	printf("\nFinished after %d iterations\n\n", count);
	printf("Operating time = %.1f seconds\n\n", operating_time);
	printf("End position = (%.1f, %.1f, %.1f)", x_p, y_p, z_p);			
	getchar();
}