#include<stdio.h>
#include <stdlib.h>
#include"var.h"
#include <math.h>


void variance (int t[], int n, float *var)
{

	int Moy, sum;
	float v;
	int i,j;
	int somme=0;
	sum = 0;
	for (j=0; j<n; j++)
	{
		sum = sum + t[j];

	}
	Moy= sum / n;

	for(i=1; i<(n+1);i++)
	{

        printf("%d\n",(t[i]-Moy)*(t[i]-Moy));
		somme= somme + (t[i]-Moy)*(t[i]-Moy);
	}

	v=somme/n;
	*var= v;
}


