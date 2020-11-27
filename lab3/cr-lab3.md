# Lab3: Commandes shell fondamentales 

1. Ouverture da la session sur ubuntu

2. démarrer un terminal (ctrl+Alt+T)

3. Pour  récupérer le dossier du lab3 3 (envoyé sur slack) on fait appel à la commande :

**git clone https://github.com/khachicha/5AS05-partie3.git**

4. Pour afficher la liste des fichiers on utilise la commande:

**ls -lrt**

- Il y a 3 fichiers
le secteur le plus petit est de taille 4096 !

5. La taille du fichier sardar n'est pas correcte, avec **ls -lrt** linux considère un répertoire comme un fichier.

6. la taille du fichier Microsoft en utilisant la commande **du** c'est 36k (*du* donne la taille sur le disque).
-  la taille du fichier Microsoft en utilisant la commande **ls** n'est pas la même qu'avec la commande **du** (*ls* donne la taille du fichier en vrai).

7. Pour afficher les informations correspondantes au fichier Microsoft on utilise la commande:

**stat Microsoft**
- Chaque fichier a un inod, en affichant le inod de Microsoft on trouve toutes les infos du fichier!

8. Pour voir les fichiers cachés on utilise la commande:
**ls -a**

- les fichiers cachés sont :

.git  .lightbulb 

9. pour afficher les fichiers les plus anciens en premier on utilise la commande:

**ls -lart** (plus recent → plus ancien)

#### un peu de clarification 

-l     use a long listing format
-a, --all
       do not ignore entries starting with .
-r, --reverse
       reverse order while sorting
-t     sort by modification time, newest first

-pour afficher les fichiers les plus anciens en premier on utilise la commande:

**ls -lat**

10. pour afficher les fichiers dans le sens décroissant on utilise la commande:

**ls -lS**

-pour afficher les fichiers dans le sens croissant on utilise la commande:

**ls -lSr**

11. Pour afficher le contenu du fichier answering-machine.txt on utilise la commande:

**cat answering-machine.txt**

12. Pour afficher le contenu du fichier answering-machine.txt  avec l'appuie sur une touche à la fin de chaque page on utilise la commande:

**less answering-machine.txt**

13. Installation de l'éditeur vim avec la commande:

**sudo apt install vim**

14. Pour rajouter un texte à la fin du fichier:

**vim answering-machine.txt**

- à la fin en clique sur I “pour dire insert” , puis on écrit welcome systemes communicants !

15. Pour supprimer le mot on utilise **dw**

16.  Pour sauvegarder **ZZ**

17. Pour passer directement à la partie du texte contenant le mot planet on utilise **/** , pour aller à la seconde occurence grâce à la commande **n**

19. Pour chercher en arrière la dernière occurence du mot BEEP on utilise **?**

20. Pour afficher les 20 dernières lignes du fichier sardar3.txt on utilise la commande:

**tail -20 sardar3.txt**

21. Pour chercher le mot trsut dans Microsoft on utilise la commande:

**grep trust Microsoft**

22. Pour chercher le mot money dans tout les fichiers du répertoire y compris dans les sous répertoires on utilise la commande:

**grep -r money**

23. Pour ne pas retaper la commande en entier pour chercher le mot Money on rajoute l'option -i dans grep (permet d'ignorer si on est en majuscule ou minuscule)

24. Pour modifier le nom du fichier pour qu'il ne soit plus caché on utilise :

**mv .lightbulb lightbulb**

25. on rentre dans le répertoire sardar utilisant la commande :

**cd sardar** et **pwd** pour vérifier qu'on est dans le bon répertoire 

26. Pour déplacer sardar on utilise la commande:

**mv sardar3.txt lab3**

27. Pour retourner dans le répertoire parent on utilise la commande:

**cd Desktop/5AS05-partie3/**

28. Pour supprimer Microsoft on utilise la commande:

**rm Microsoft**

29. Pour créer un répertoire archive et copier tout les fichiers dans le répertoire courant vers ce répertoire on utilise:

**cd Desktop/**
**tar -cvf lab3arch.tar 5AS05-partie3**

30. Pour créer des liens symboliques :

**ln -s 5AS05-partie3 sardar**

31. Pour afficher la liste des fichiers dans le répertoire courant on utilise la commande:

**ls -l**
 
- oui les liens symboliques sont faciles à identifier 

32. Pour supprimer le fichier sardar/ardar2.txt on utilise la commande:

**rm sardar2.txt**

- Avec la commande *ls-lrt* on voit qu'il est en rouge.

33. on ne peut pas écrire car on a pas les droits d'accès!

34. Pour afficher les droits d’accès on utilise la commande: 

**ls -l**

#### un peu de clarification 

Le premier symbole peut être « - », « d », soit « l ». Il indique la nature du fichier : 
    • - : fichier classique
    • d : répertoire
    • l : lien symbolique
Suivent ensuite 3 groupes de 3 symboles chacun, indiquant si le fichier (ou répertoire) est autorisé en lecture, écriture ou exécution. Les 3 groupes correspondent, dans cet ordre, aux droits du propriétaire, du groupe puis du reste des utilisateurs. Dans le paragraphe introductif, vous aurez remarqué des lettres en gras dans les termes anglais. Ce sont ces lettres qui sont utilisées pour symboliser lesdites permissions. Si la permission n'est pas accordée, la lettre en question est remplacé par « - ». Si l'on reprend les lettres données pour lecture/écriture/exécution (read/write/execute), nous obtenons : rwx. 

36. Pour créer une archive compresser on utilise la commande:

**tar jcvf 5AS05-partie3.tar.bz2 5AS05-partie3**

37.  Pour lister les fichiers et répertoires sans décompresser le répertoire :

**tar jtvf 5AS05-partie3.tar.bz2**
