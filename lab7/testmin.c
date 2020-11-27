#include<stdio.h>
#include <stdlib.h>
#include"min.h"

int main ()
{
	int nb_val;
	int  min;
	int tab[5]={2,5,7,2,9};

	printf("Nombre d\'elements ? "); 
	scanf ("%d", &nb_val);

	chercher_min(tab, nb_val, &min);
	printf ("Min = %d\n", min);

	return 0;
}
