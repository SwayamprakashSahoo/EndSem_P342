//endsem question 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mylib.h"
#define pi 3.14159265358979323846

int main()
{
	double ll, ul;
	ll = 0;
	ul = pi / 2;
	double I = simpsons(ll, ul, 10, 4);
	double L = 1;
	double g = 9.8;
	printf("Given equation is:\n\tT = 4 x sqrt(L/g) x I\n");
	printf("Using given values of L and g:\n");
	double T = 4 * sqrt(L / g) * I;
	printf("Solution for T = %lf\n", T);

}



/************************OUTPUT**************************
Given equation is:
        T = 4 x sqrt(L/g) x I
Using given values of L and g:
Solution for T = 2.087320
*******************************************************/


