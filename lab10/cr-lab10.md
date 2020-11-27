# Lab. 10 : Le Makefile


1. On copie les fichiers max.c, min.c, var.c, max.h, min,h, var.h et test de la partie 7 avec la commande suivante:

yasma@Yasma:~$ **cp /home/yasma/Bureau/chahla/lab7/max.c /home/yasma/Bureau/chahla/lab7/max.h /home/yasma/Bureau/chahla/lab7/min.c /home/yasma/Bureau/chahla/lab7/min.h /home/yasma/Bureau/chahla/lab7/var.c /home/yasma/Bureau/chahla/lab7/var.h /home/yasma/Bureau/chahla/lab7/test.c /home/yasma/Bureau/chahla/lab10/**

- On verifie qu'ils sont bien copier dans le lab10

yasma@Yasma:~$ **cd Bureau/chahla/lab10/**
yasma@Yasma:~/Bureau/chahla/lab10$ **ls**
lab10.txt  max.c  max.h  min.c  min.h  test.c  var.c  var.h

2. Pour créer un makefile on utilise la commande suivante:

yasma@Yasma:~/Bureau/chahla/lab10$ **touch Makefile**

- dans le Makefile on écrit les commandes suivantes:

```
install: My_binaire	
	mv My_binaire /home/yasma 
My_binaire:	test.o max.o min.o var.o
	gcc -Wall test.o max.o min.o var.o -o My_binaire
max.o:	max.c
	gcc -Wall -c max.c -o max.o 
min.o:	min.c
	gcc -Wall -c min.c -o min.o
var.o:	var.c
	gcc -Wall -c var.c -o var.o
test.o:	test.c
	gcc -Wall -c test.c -o test.o
clean: 
	rm max.o min.o var.o
```

3. Exécution avec les différentes commandes (make, make install, make min.o, make clean)

yasma@Yasma:~/Bureau/chahla/lab10$ **make**
gcc -Wall -c max.c -o max.o 
gcc -Wall -c min.c -o min.o
gcc -Wall -c var.c -o var.o
gcc -Wall test.o max.o min.o var.o -o My_binaire

yasma@Yasma:~/Bureau/chahla/lab10$ **make install**
mv My_binaire /home/yasma 
yasma@Yasma:~/Bureau/chahla/lab10$ **make min.o**
make: « min.o » est à jour.
yasma@Yasma:~/Bureau/chahla/lab10$ **make clean** 
rm max.o min.o var.o


- On remarque que lorsqu'on execute la commande make dans le terminal y a toutes la liste de compilation dans le makefile qui s'excute (car y a une dépendance entre eux) 

4. 

```
# Définition de variable 
	CC=gcc 
	OBJ= max.o min.o var.o test.o
	CC_OPTIONS=
install: My_binaire	
	mv My_binaire /home/yasma 
My_binaire:	 ${OBJ}

	${CC} -Wall ${OBJ} -o My_binaire
max.o:	max.c
	${CC} -Wall -c max.c -o max.o 
min.o:	min.c
	${CC} -Wall -c min.c -o min.o
var.o:	var.c
	${CC} -Wall -c var.c -o var.o
test.o:	test.c
	${CC}- Wall -c test.c -o test.o
clean: 
	rm ${OBJ}
```

- Après cimpilation 
yasma@Yasma:~/Bureau/chahla/lab10$ **make** 
gcc  -Wall -c max.c -o max.o 
gcc  -Wall -c min.c -o min.o
gcc -Wall -c var.c -o var.o
gcc  -Wall test.o max.o min.o var.o -o My_binaire

5. 

```
# Définition de variable 
	CC=gcc 
	OBJ= max.o min.o var.o
	CC_OPTIONS= -g -Wall

install: My_binaire
	mv My_binaire /home/yasma 
My_binaire:	${OBJ}

	${CC} ${CC_OPTIONS} ${OBJ} -o My_binaire
max.o:	max.c
	${CC} ${CC_OPTIONS}  -c max.c -o max.o 
min.o:	min.c
	${CC} ${CC_OPTIONS}  -c min.c -o min.o
var.o:	var.c
	${CC} ${CC_OPTIONS} -c var.c -o var.o
test.o:	test.c
	${CC} ${CC_OPTIONS}  -c test.c -o test.o
clean: 
	rm ${OBJ}
```

- Après compilation:
yasma@Yasma:~/Bureau/chahla/lab10$ **make** 
gcc  -g -Wall  -c max.c -o max.o 
gcc  -g -Wall  -c min.c -o min.o
gcc  -g -Wall -c var.c -o var.o
gcc  -g -Wall test.o max.o min.o var.o -o My_binaire

6. 

```
# Définition de variable 
	CC=gcc 
	OBJ= max.o min.o var.o
	CC_OPTIONS= -g -Wall
install: My_binaire
	mv My_binaire /home/yasma 
My_binaire:	${OBJ}

	${CC} ${CC_OPTIONS} ${OBJ} -o $@
max.o:	max.c
	${CC} ${CC_OPTIONS} -c $< -o $@
min.o:	min.c
	${CC} ${CC_OPTIONS} -c $< -o $@
var.o:	var.c
	${CC} ${CC_OPTIONS} -c $< -o $@
test.o:	test.c
	${CC} ${CC_OPTIONS} -c $^ -o $@

clean: 
	rm ${OBJ}
```

- Après compilation:
yasma@Yasma:~/Bureau/chahla/lab10$ **make**
gcc  -g -Wall  -c max.c -o max.o
gcc  -g -Wall  -c min.c -o min.o
gcc  -g -Wall -c var.c -o var.o
gcc  -g -Wall test.o max.o min.o var.o -o My_binaire

7. 

```
# Définition de variable 
	CC=gcc 
	OBJ= max.o min.o var.o test.o
	ifeq ($(DEBUG),yes)
		CC_OPTIONS= -g -Wall
	else
		CC_OPTIONS=
	endif
	 
install: My_binaire	
	mv My_binaire /home/yasma 	
My_binaire:	${OBJ}
	${CC} ${CC_OPTIONS} ${OBJ} -o $@
max.o:	max.c
	${CC} ${CC_OPTIONS} -c $< -o $@
min.o:	min.c
	${CC} ${CC_OPTIONS} -c $< -o $@
var.o:	var.c
	${CC} ${CC_OPTIONS} -c $< -o $@
test.o:	test.c
	${CC} ${CC_OPTIONS} -c $^ -o $@
	
clean: 
	rm ${OBJ}
```

8. 

yasma@Yasma:~/Bureau/chahla/lab10$ **make clean**
rm max.o min.o var.o test.o
yasma@Yasma:~/Bureau/chahla/lab10$ **make DEBUG=No**
gcc   -c max.c -o max.o
gcc   -c min.c -o min.o
gcc   -c var.c -o var.o
gcc   -c test.c -o test.o
gcc   max.o min.o var.o test.o -o My_binaire
mv My_binaire /home/yasma 
yasma@Yasma:~/Bureau/chahla/lab10$ make clean 
rm max.o min.o var.o test.o
yasma@Yasma:~/Bureau/chahla/lab10$ **make DEBUG=yes**
gcc  -g -Wall -c max.c -o max.o
gcc  -g -Wall -c min.c -o min.o
gcc  -g -Wall -c var.c -o var.o
gcc  -g -Wall -c test.c -o test.o
gcc  -g -Wall max.o min.o var.o test.o -o My_binaire
mv My_binaire /home/yasma 
	

9. 

```
# Définition de variable 
	CC=gcc 
	OBJ= max.o min.o var.o test.o
	ifeq ($(DEBUG),yes)
		CC_OPTIONS= -g -Wall
	else
		CC_OPTIONS=
	endif
	 
install: My_binaire	
	mv My_binaire /home/yasma 
My_binaire:	${OBJ}
	${CC} ${CC_OPTIONS} ${OBJ} -o $@
ifeq	($(DEBUG),No)

	@echo "Génération en mode Release"
else
	
	@echo "Génération en mode Debug"

endif	

max.o:	max.c
	${CC} ${CC_OPTIONS} -c $< -o $@
min.o:	min.c
	${CC} ${CC_OPTIONS} -c $< -o $@
var.o:	var.c
	${CC} ${CC_OPTIONS} -c $< -o $@
test.o:	test.c
	${CC} ${CC_OPTIONS} -c $^ -o $@
	
clean: 
	rm ${OBJ}
```
yasma@Yasma:~/Bureau/chahla/lab10$ **make clean**
rm max.o min.o var.o test.o
yasma@Yasma:~/Bureau/chahla/lab10$ **make DEBUG=yes**
gcc  -g -Wall -c max.c -o max.o
gcc  -g -Wall -c min.c -o min.o
gcc  -g -Wall -c var.c -o var.o
gcc  -g -Wall -c test.c -o test.o
gcc  -g -Wall max.o min.o var.o test.o -o My_binaire
Génération en mode Debug
mv My_binaire /home/yasma 

yasma@Yasma:~/Bureau/chahla/lab10$ **make clean** 
rm max.o min.o var.o test.o
yasma@Yasma:~/Bureau/chahla/lab10$ **make DEBUG=No**
gcc   -c max.c -o max.o
gcc   -c min.c -o min.o
gcc   -c var.c -o var.o
gcc   -c test.c -o test.o
gcc   max.o min.o var.o test.o -o My_binaire
Génération en mode Release
mv My_binaire /home/yasma 
