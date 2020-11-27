# Lab7: Compilation sous GCC, Débogage


1. Pour faire ce lab sans avoir des problèmes de debbogage on peut procéder par l'installation de codeblocks utilisant la commande suivante:

**sudo apt install codeblocks**

- dans un premier temps on a crée des fichiers max.c dont on a écrit la fonction void chercher_max(tab, nb_val, &max); le testmax.c on a écrit le main et le max.h le header. 

### le max.c contient le programme suivant:

```c

void chercher_max (int t[], int n, int *max)
{
	int val_max; 
	int i;
	val_max = t[0];
	for (i=0; i<n; i++)
	{
		if (t[i] > val_max) 
		{
			val_max = t[i];
		}
	}
	
	*max = val_max; 
}
```
### le testmax.c :

```c
int main ()
{
	int nb_val;
	int  max;
	int tab[5]={2,5,7,2,9};

	printf("Nombre d\'elements ? "); // on fait rentrer le nombre d'éléments que notre tableau contient.
	scanf ("%d", &nb_val); // on saisie le nombre d'élément dans notre cas 5
 
	chercher_max(tab, nb_val, &max); // on fait appel à la fonction max
	printf ("Max = %d\n", max); // on affiche la valeur max

	return 0;
}
```

### le header max.h :

```c
#ifndef H_max
#define H_max

void chercher_max (int t[], int n, int *max);


#endif
```
- une fois les programme sont bien ecrits on peut les compiler utilisant la commande suivante:
gcc max.c testmax.c -o maximum (etape compilation)
vu que le programme ne renvoit pas d'erreus on peut l'executer utilisant la commande **./maximum** sur le terminal.

2. Pour faire appel au débogueur ddd on doit d'abord l'installer, donc dans le terminal on tappe la commande suivante:

**sudo apt-get install ddd**

- une fois notre ddd est bien installé on compile en mode debugger en rajouttant -g ( gcc -g max.c testmax.c -o maximum )
maintenant on peut lancer notre ddd maximum.

3. 

**gcc -E testmax.c -o testmax.i** ( cette étape c'est le Preprocessing, le compilo va purifier le code il enleve les commentaire, il inclue les fichiers .h, et traite les directives de compilation)
 
**gcc -S max.c testmax.i**  (Dans cette deuxieme étape qui s'appelle compiling ou compilation , le compilateur va reprendre le code fourni par l'etape precedente, et le transformer en code en langage assembleur "langage de plus bas niveau, tres proche du langage machine".

**gcc -c max.c testmax.s** (Dans cette 3eme étape qui est Assembling ou assemblage, le compilateur va prendre le code assembleur obtenu par l'etape precedente, et le transformer en code machine (binaire), c'est nos fameux .o. Les .o sont donc tres importants !


4. Pour lister les extensions des fichiers intermédiares on utilise la commande : 
**ls -a**

- l'action réalisée par le compilateur dans chacune de ses étapes (cf en Q3)


5. En faisant l'assemblage la fonction max sera remplacer par le binaire correspondant c'est à dire quand on rentre la commande gcc -c max.c testmax.s 

6. La fonction minimum 

### le code de min.c est le suivant:

```c

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
```
### le code de testmin.c :

```c
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
```
### le header min.h :

```c

#ifndef H_min
#define H_min

void chercher_min (int t[], int n, int *min);


#endif
```

- on compile avec la commande: 

**gcc  min.c testmin.c -o minimum**

puis on execute avec **./minimum**
et on a bien le min=2 ( le résultat attendu)

7. On écrit un code qui calcule la variance :

### Le code de var.c:

```c
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
		sum = sum + t[j]; // le calcul de la somme afin de pouvoir calculer la moyenne

	}
	Moy= sum / n; // calcul de la moyenne qu'on va utiliser pour la variance 

	for(i=1; i<(n+1);i++)
	{

        printf("%d\n",(t[i]-Moy)*(t[i]-Moy));
		somme= somme + (t[i]-Moy)*(t[i]-Moy);
	}

	v=somme/n;
	*var= v;
}
```

### le testvar.c qui est notre main:

```c
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
```

### Le header var.h:

```c
#ifndef H_var
#define H_var

void variance (int t[], int n, float *var);



#endif
```

- on compile toujours avec la commande  **gcc var.c testvar.c -o variance** puis on execute avec **./variance** 

8. le fichier test :

```c
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

		
	chercher_max(tab, nb_val, &max); // on fait appel à la fonction max pour nous afficher le max du tab[10]
	printf ("Max = %d\n", max);

	chercher_min(tab, nb_val, &min); //on fait appel à la fonction min pour nous afficher le min du tab[10]
	printf ("Min = %d\n", min);

	variance(tab, nb_val, &var); // on fait appel à la fonction var pour nous calculer la variance du tab[10]
	printf ("Var = %f\n", var);
	
	return 0;
}
```
- on compile avec la commande dans le terminal :  **gcc test.c max.c min.c var.c -o test**

et on execute avec ./test
