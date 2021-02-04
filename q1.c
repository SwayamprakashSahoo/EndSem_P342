//end-sem question 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mylib.h"

int main()
{
	double n;
	printf("Given equation for Planck's spectrum:\n(x-5)(e^x) + 5 = 0\n\n");
	printf("\n\nFor using Newton-Raphson method:-");
	printf("\nPlease enter the value of guess 'a' :\n ");
	scanf_s("%lf", &n);
	double x = newtonRaphson(n, 3);
	printf("The root of the equation yields : %lf\n ", x);
	printf("We have :\nx = hc/bk\nUsing the given values of h, c and the calculated value of x:\n");
	double h = 6.626 * pow(10, -34);
	double k = 1.381 * pow(10, -23);
	double c = 3 * pow(10, 8);
	double b = (h * c) / (x * k);
	printf("The value of b is : %.4lf\n ", b);
}

