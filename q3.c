//endsem question 3
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "mylib.h"

int main()
{
	double n = 12;
	double t[12], av[12], t2[12], av2[12], tav[12], lnav[12];
	printf("Please enter the values of X sequentially\n");

	for (int i = 0; i < 12; i++)
	{
		scanf("%lf", &t[i]);
	}
	printf("Please enter the values of Y sequentially\n");

	for (int i = 0; i < 12; i++)
	{
		scanf("%lf", &av[i]);
	}
	for (int i = 0; i < 12; i++)
	{
		lnav[i]=log(av[i]);
	}
	double sy=0, sx=0, sxy=0, sx2=0, sy2=0;
	//for linear fit
	for (int i = 0; i < 12; i++)
	{
		t2[i] = t[i] * t[i];
		av2[i] = av[i] * av[i];
		tav[i] = t[i] * av[i];

		sx += t[i];
		sy += av[i];
		sxy += tav[i];
		sx2 += t2[i];
		sy2 += av2[i];
	}
	double xavg = sx / n;
	double yavg = sy / n;

	double a = (((yavg * sx2) - (xavg * sxy)) / (sx2 - n * xavg * xavg));
	double b = ((sxy - n * xavg * yavg) / (sx2 - n * xavg * xavg));

	double sxx = 0, syy = 0, ssxy = 0;
	for (int i = 0; i < 12; i++)
	{
		sxx += (t[i]-xavg)* (t[i] - xavg);
		syy += (av[i] - yavg) * (av[i] - yavg);
		ssxy += (t[i] - xavg) * (av[i] - yavg);
	}

	double r = sqrt((ssxy * ssxy) / (sxx * syy));
	printf("For linear fit in (i) the values are:\nW0 = %lf\n W_c = %lf\n", b, a);
	printf("Quality of fit:%lf\n\n", r);

	//for exponential curve fit
	sy = 0, sx = 0, sxy = 0, sx2 = 0, sy2 = 0;
	for (int i = 0; i < 12; i++)
	{
		t2[i] = t[i] * t[i];
		av2[i] = lnav[i] * lnav[i];
		tav[i] = t[i] * lnav[i];

		sx += t[i];
		sy += lnav[i];
		sxy += tav[i];
		sx2 += t2[i];
		sy2 += av2[i];
	}
	xavg = sx / n;
	yavg = sy / n;

	a = (((yavg * sx2) - (xavg * sxy)) / (sx2 - n * xavg * xavg));
	b = ((sxy - n * xavg * yavg) / (sx2 - n * xavg * xavg));

	sxx = 0, syy = 0, ssxy = 0;
	for (int i = 0; i < 12; i++)
	{
		sxx += (t[i] - xavg) * (t[i] - xavg);
		syy += (lnav[i] - yavg) * (av[i] - yavg);
		ssxy += (t[i] - xavg) * (lnav[i] - yavg);
	}

	r = sqrt((ssxy * ssxy) / (sxx * syy));
	printf("For exponential fit in (ii) the values are:\nW0 = e^(%lf)\n W_c = %lf\n", b, a);
	printf("Quality of fit:%lf\n\n", r);
}











/***************************OUTPUT*********************************
Please enter the values of X sequentially
0
.3
.6
.9
1.2
1.5
1.8
2.1
2.4
2.7
3
3.3
Please enter the values of Y sequentially
2.2
1.96
1.72
1.53
1.36
1.22
1.1
1
.86
.75
.65
.6
For linear fit in (i) the values are:
W0 = -0.474709
 W_c = 2.029103
Quality of fit:0.985156

For exponential fit in (ii) the values are:
W0 = e^(-0.395596)
 W_c = 0.790278
Quality of fit:0.913349
*****************************************************************************/
