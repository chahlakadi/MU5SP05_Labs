#include<stdio.h>
#include <stdlib.h>
#include"max.h"

int main ()
{
	int nb_val;
	int  max;
	int tab[5]={2,5,7,2,9};

	printf("Nombre d\'elements ? "); 
	scanf ("%d", &nb_val);

	chercher_max(tab, nb_val, &max);
	printf ("Max = %d\n", max);

	return 0;
}
