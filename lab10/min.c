#include<stdio.h>
#include <stdlib.h>
#include"min.h"


void chercher_min (int t[], int n, int *min)
{
	int val_min;
	int i;
	val_min = t[0];
	for (i=0; i<n; i++)
	{
		if (t[i] < val_min)
		{
			val_min = t[i];
		}
	}
	
	*min = val_min;
}


