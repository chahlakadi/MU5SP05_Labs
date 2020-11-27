#include<stdio.h>
#include <stdlib.h>
#include"var.h"
#include"max.h"
#include"min.h"


int main ()
{
	int nb_val;
	float  var;
	int max;
	int min;

	int tab[10]={4,9,10,11,12,15,12,9,0,30};

	printf("Nombre d\'elements ? "); 
	scanf ("%d", &nb_val);

		
	chercher_max(tab, nb_val, &max);
	printf ("Max = %d\n", max);

	chercher_min(tab, nb_val, &min);
	printf ("Min = %d\n", min);

	variance(tab, nb_val, &var);
	printf ("Var = %f\n", var);
	
	return 0;
}

