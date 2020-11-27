
#include<stdio.h>
#include <stdlib.h>
#include"max.h"
#include"min.h"
#include <math.h>

int main ()
{
	int nb_val;
	int max;
	int min;
	float  var;
	//float floorf( float var); 

	int tab[7]={13,12,5,1,19,13,17};

	printf("Nombre d\'elements ? "); 
	scanf ("%d", &nb_val);

		
	chercher_max(tab, nb_val, &max);
	printf ("Max = %d\n", max);

	chercher_min(tab, nb_val, &min);
	printf ("Min = %d\n", min);
	
	variance(tab, nb_val, &var);
	printf ("Var = %f\n", var);
	//printf( "L'arrondi inférieur vaut : %g\n", floorf (var) );
	//printf( "L'arrondi supérieur vaut : %g\n", ceilf ( var) );
    



	return 0;
}
