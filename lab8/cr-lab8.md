# Lab8: Création et utilisation des bibliothèques statiques 


1. Dans un premier temps on copie les fichiers max.c testmax.c max.h et min.c testmin.c min.h dans le répertoire dont on travaille:
/home/yasma/Bureau/chahla/lab8

2. Compilation de deux fichiers max.c et min.c sans édition des liens: 

yasma@Yasma:~/Bureau/chahla/lab8$ **gcc -c max.c min.c** 

3. Création de la bibliothèque et l'ajout des fichiers.o:

yasma@Yasma:~/Bureau/chahla/lab8$ **ar -cr liboutils.a max.o min.o**

4. L'option ar -t consiste à lister le nom des fichiers objets dans la bibliothèque:

yasma@Yasma:~/Bureau/chahla/lab8$ **ar -t liboutils.a**
max.o
min.o

5. L’outil ranlib permet de créer un index des ressources présentes dans une bibliothèque statique et d’incorporer cet index à l’intérieur de la bibliothèque pour permettre d’accélérer substantiellement la phase d’édition des liens.

yasma@Yasma:~/Bureau/chahla/lab8$ **ranlib liboutils.a**

6. 

```c
#include<stdio.h>
#include <stdlib.h>
#include"max.h"
#include"min.h"


int main ()
{
	int nb_val;
	int max;
	int min;

	int tab[7]={13,12,5,1,19,13,17};

	printf("Nombre d\'elements ? "); 
	scanf ("%d", &nb_val);

		
	chercher_max(tab, nb_val, &max);
	printf ("Max = %d\n", max);

	chercher_min(tab, nb_val, &min);
	printf ("Min = %d\n", min);

	return 0;
}
```
- Pour la compilation:

yasma@Yasma:~/Bureau/chahla/lab8$ **gcc main.c min.c max.c -o main**

yasma@Yasma:~/Bureau/chahla/lab8$ ./main

Nombre d'elements ? 7
Max = 19
Min = 1

7. Créer deux répertoire include et lib dans opt:


cd /opt
yasma@Yasma:/opt$ **sudo mkdir include**

yasma@Yasma:/opt$ **sudo mkdir lib**

8. Deplacer les fichiers max.h et min.h dans include:


yasma@Yasma:~$ **sudo mv Bureau/chahla/lab8/max.h /opt/include**

yasma@Yasma:~$ **sudo mv Bureau/chahla/lab8/min.h /opt/include**

yasma@Yasma:~$ **cd /opt/include/**

yasma@Yasma:/opt/include$ **ls**

max.h  min.h

- Déplacer la bibliothèque statique liboutils.a dans lib:


yasma@Yasma:~$ **sudo mv Bureau/chahla/lab8/liboutils.a /opt/lib**

yasma@Yasma:~$ **cd /opt/lib/**

yasma@Yasma:/opt/lib$ **ls**
liboutils.a

9. Revenir au réprtoire courant :

yasma@Yasma:~$ **cd Bureau/chahla/lab8/**

- On supprime tout les fichiers .o:

yasma@Yasma:~/Bureau/chahla/lab8$ **rm *.o**

- On supprime les deux fichiers max.c min.c:

yasma@Yasma:~/Bureau/chahla/lab8$ **rm max.c min.c** 

- Compiler le fichier main:
yasma@Yasma:~/Bureau/chahla/lab8$ **gcc main.c -L/opt/lib/ -I/opt/include -loutils -o mainexecute**


10. Le bon fonctionnement du programme:

yasma@Yasma:~/Bureau/chahla/lab8$ **./mainexecute**
Nombre d'elements ? 7
Max = 19
Min = 1

11. On copie var.c dans notre répertoire courant avec la commande cp
- On compile le var.c
yasma@Yasma:~/Bureau/chahla/lab8$ **gcc -c var.c**

- On copie d'abord var.o dans notre reprtoire lib (le meme répertoire que la bibliothèque) 

- On rajoute le var.o à la bibliothèque liboutils

yasma@Yasma:~/Bureau/chahla/lab8$ **sudo cp var.o /opt/lib**

yasma@Yasma:/opt/lib$ **ar -r liboutils.a var.o**

12. Vérifier que le var.o est bien présent dans la bibliothèque:

yasma@Yasma:/opt/lib$ **ar -t liboutils.a**
max.o
min.o
var.o

13. 
yasma@Yasma:/opt/lib$ **sudo ranlib liboutils.a**

- Vérifier l'existance du binaire des fonctions max et min 

###### l'option -s,
      --print-armap      Inclure un index pour les symboles à partir des membres de l'archive
      --size-sort        Trier les symboles par leur taille
      --special-syms     Inclure les symboles spéciaux sur la sortie
      --synthetic        Afficher aussi les symboles synthétiques

yasma@Yasma:/opt/lib$ **nm -s liboutils.a**


14. 

```c
#include<stdio.h>
#include <stdlib.h>
#include"max.h"
#include"min.h"


int main ()
{
	int nb_val;
	int max;
	int min;
	float  var;

	int tab[7]={13,12,5,1,19,13,17};

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
```

- Pour compiler: 
/Bureau/chahla/lab8$ **gcc main.c -L/opt/lib/liboutils.a -I/opt/include /opt/lib/liboutils.a -o mainexecute**

- Pour vérifier le bon fonctionnement: 
**./mainexecute**


15. 

```c
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
	printf( "L'arrondi inférieur vaut : %g\n", floorf (var) );
	printf( "L'arrondi supérieur vaut : %g\n", ceilf ( var) );
    



	return 0;
}
```
- Pour compiler 
**gcc  main.c -L/opt/lib/liboutils.a -I/opt/include /opt/lib/liboutils.a -o mainexecute -lm**

- L'option -lm pour la bibiliothèque math, on rajoute cette option dans la commande pour que les fonction floorf et ceilf seront reconnu lors de l'édition des liens 

16. Pour executer 

**./mainexecute**




