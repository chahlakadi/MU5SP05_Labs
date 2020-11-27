# Lab9: Création et utilisation des bibliothèques dynamique 


1. Copier tout les fichiers du lab7 vers lab9:

yasma@Yasma:~$ **cp /home/yasma/Bureau/chahla/lab7/max.c /home/yasma/Bureau/chahla/lab7/max.h /home/yasma/Bureau/chahla/lab7/min.c /home/yasma/Bureau/chahla/lab7/min.h /home/yasma/Bureau/chahla/lab7/var.c /home/yasma/Bureau/chahla/lab7/var.h /home/yasma/Bureau/chahla/lab9/**

2. 
`yasma@Yasma:~/Bureau/chahla/lab9$ gcc -c -fPIC max.c min.c var.c`

3. 

`yasma@Yasma:~/Bureau/chahla/lab9$ gcc -shared -o libpartager.so max.o min.o var.o`

4. 
```
yasma@Yasma:~$ sudo mv /home/yasma/Bureau/chahla/lab9/libpartager.so /opt/lib
yasma@Yasma:~$ cd /opt/lib
yasma@Yasma:/opt/lib$ ls
liboutils.a  libpartager.so  var.o
```
5. 

`yasma@Yasma:~/Bureau/chahla/lab9$ gcc main.c -L/opt/lib -lpartager -o exemain`


6. En executant avec la commande **./exemain** on a:

./exemain: error while loading shared libraries: libpartager.so: cannot open shared object file: No such file or directory

- c'est à dire il ne peut pas ouvrir les fichiers partagés car ils les trouves pas.

7. 
yasma@Yasma:~/Bureau/chahla/lab9$ **echo $LD_LIBRARY_PATH**

- le chemin est vide 

8. 
yasma@Yasma:~/Bureau/chahla/lab9$ **export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/lib/**

9. 

```
yasma@Yasma:~/Bureau/chahla/lab9$ gcc main.c -L/opt/lib -lpartager -o exemain
yasma@Yasma:~/Bureau/chahla/lab9$ ./exemain

```

- Le programme s'execute car on a rajouter le chemin des bibliothèques mais quand on ferme et on lance le terminal à nouveau l'excution ne se fait pas!

10. En rajoutant la commande suivante dans le .bashrc l'execution peut se faire même quand on ferme et on réouvre le terminal. 

11. 

yasma@Yasma:~$ **locate libm.so**

/lib/x86_64-linux-gnu/libm.so.6
/snap/core/10185/lib/i386-linux-gnu/libm.so.6
/snap/core/10185/lib/x86_64-linux-gnu/libm.so.6
/snap/core/9993/lib/i386-linux-gnu/libm.so.6
/snap/core/9993/lib/x86_64-linux-gnu/libm.so.6
/snap/core18/1885/lib/i386-linux-gnu/libm.so.6
/snap/core18/1885/lib/x86_64-linux-gnu/6
/snap/core18/1932/lib/x86_64-linux-gnu/libm.so.libm.so.6
/snap/core18/1932/lib/i386-linux-gnu/libm.so.6
/snap/gnome-3-34-1804/60/usr/lib/x86_64-linux-gnu/libm.so
/usr/lib/x86_64-linux-gnu/libm.so

12. Lors de l'exécution, le chargeur dynamique cherche libtruc.so.1. C'est un lien symbolique plutôt qu'un réel fichier pour que les bibliothèques puissent être mise à jour sans avoir à casser les applications qui utilisent la bibliothèque. 

- Chaque bibliothèque possède un nom propre (soname). Lorsque l'éditeur de liens en trouve un qui correspond à un nom cherché, il enregistre le nom de la bibliothèque dans le code binaire au lieu d'y mettre le nom du fichier de la bibliothèque. Lors de l'exécution, le chargeur dynamique va alors chercher un fichier ayant pour nom le nom propre de la bibliothèque, et pas le nom du fichier de la bibliothèque. 


- Le soname de la bibliothèque math est: libm.so.6

- Le réel name de la bibliothèque on peut l'avoir en utilisant la commande :
yasma@Yasma:~$ **locate libm-**
/lib/x86_64-linux-gnu/libm-2.27.so
/snap/core/10185/lib/i386-linux-gnu/libm-2.23.so
/snap/core/10185/lib/x86_64-linux-gnu/libm-2.23.so
/snap/core/9993/lib/i386-linux-gnu/libm-2.23.so
/snap/core/9993/lib/x86_64-linux-gnu/libm-2.23.so
/snap/core18/1885/lib/i386-linux-gnu/libm-2.27.so
/snap/core18/1885/lib/x86_64-linux-gnu/libm-2.27.so
/snap/core18/1932/lib/i386-linux-gnu/libm-2.27.so
/snap/core18/1932/lib/x86_64-linux-gnu/libm-2.27.so
/usr/include/x86_64-linux-gnu/bits/libm-simd-decl-stubs.h
/usr/lib/debug/lib/x86_64-linux-gnu/libm-2.27.so
/usr/lib/x86_64-linux-gnu/libm-2.27.a



- donc on obtient le réel name comme suit :
 libm-2.27.so


13. 

yasma@Yasma:~$ **sudo cp /opt/lib/libpartager.so /usr/lib**

yasma@Yasma:~$ **cd /usr/lib**

yasma@Yasma:/usr/lib$ **find -name libpartager.so**
./libpartager.so

- Pour donner les droit d'execution en mode lecture seulement: 

yasma@Yasma:/usr/lib$ **sudo chmod 444 libpartager.so**


14. La cache est une mémoire proche de processeur l'ordinateur(cpu) l'utilise !
Une mémoire cache ou antémémoire est, en informatique, une mémoire qui enregistre temporairement des copies de données provenant d'une source, afin de diminuer le temps d'un accès ultérieur d'un matériel informatique à ces données.

yasma@Yasma:/usr/lib$ **sudo ldconfig**

15. 
yasma@Yasma:/usr/lib$ **ldconfig -p | grep libpartager**
	libpartager.so (libc6,x86-64) => /usr/lib/libpartager.so

16. 

yasma@Yasma:/usr/lib$ **ldd libpartager.so**
	linux-vdso.so.1 (0x00007fff20df1000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fd9318b9000)
	/lib64/ld-linux-x86-64.so.2 (0x00007fd931eac000)

17. 
yasma@Yasma:~$ **vim .bashrc**

- On supprime dedans la variable d'environnement rajouter dans la question 10

18. 
yasma@Yasma:~/Bureau/chahla/lab9$ **gcc main.c -lpartager**


19. 
on execute et notre main fonctionne bien !!
































 

