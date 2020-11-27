#include<stdio.h>
#include <stdlib.h>
#include"var.h"


int main ()
{
	int nb_val;
	float  var;
	int tab[5]={2,5,7,2,9};

	printf("Nombre d\'elements ? "); 
	scanf ("%d", &nb_val);

	variance(tab, nb_val, &var);
	printf ("Var = %f\n", var);

	return 0;
}
