# Lab4: Commandes shell avancées

1. Pour récupérer les sorurces:

**git clone https://github.com/khachicha/5AS05-partie4.git**

2. Pour voir les commandes déjà tapées on utilise la commande: **history**

3. On sauvgarde ce que sort la commande *history* dans un fichier texte history.txt:

**history > history.txt**

4.  Mettre tout les fichiers du répertoire sardar/ dans le fichier sardar_power.txt:

/Desktop/5AS05-partie4/sardar$ **touch sardar_power.txt**
**cat sardar1.txt sardar2.txt sardar3.txt > sardar_power.txt**

5. Pour voir combien de lignes de mots et de caractères il y a dans ce fichier on utilise la commande:

**wc sardar_power.txt**
- Le resultat est le suivant:

1980  16783 101780 sardar_power.txt

1980 représente le nombre de lignes,
16783 le nombre de mots,
101780 le nombre d’octets(byte=8 bits)

6. Pour afficher toutes les lignes qui contiennet singh on utilise la commande:

**grep -i singh sardar_power.txt** 

- le i (insensitif) c'est pour ne pas prendre en compte les majuscules et les minuscules!

7. Pour supprimer le fichier sardar_power.txt on utilise la commande :

**rm sardar_power.txt**

8. Pour afficher le mot singh dans tout le réprtoire sardar sans prendre les majuscles et les minuscules en compte:

~/Desktop/5AS05-partie4/sardar$ grep -i singh *

9. Pour compter le nombre de lignes:

~/Desktop/5AS05-partie4/sardar$ **grep -ri singh | wc -l**

- r pour dire récurssive elle parcourt le réprtoire et les fichiers du répertoire. 
- Pour calculer le nombre de lignes on utilise  **wc -l** (résultat 123 lignes)

10. Pour compter les lignes qui contient singh et santa au même temps:

**grep -ri singh | grep -ri santa | wc -l**  (résultat 114 lignes)

11. Pour compter les lignes qui contient singh et santa mais pas banta:

**cat *.txt | grep -i singh | grep -i santa | grep -iv banta | wc -l** ( résultat 26 lignes)

12. Pour afficher tout les fichier . txt dans 5AS05-partie4:

 ~/Desktop/5AS05-partie4$ find . -name "*.txt" -print

13.  Pour copier:

**cp answering-machine.txt test-commande-locate** 
**locate test-commande-locate** (y a rien qui s'affiche)

14. sudo updatedb

**locate test-commande-locate** ( là ça affiche le chemin vers mon fichier)

15. Pour comparer 2 fichiers on utilise :

**diff noyau.v2 noyau.v1**  (ou on peut faire sudo install tkdiff pour afficher directement ce qui a été modifier)

résultat: la différence est dans la ligne 25 et 26 le fichier noyeau.v2 a un PATCHLEVEL = 02
et SUBLEVEL = -rc2 mais dans le fichier noyeau.v1 PATCHLEVEL = 01  SUBLEVEL = -rc1

aussi dans la ligne 54 le noyeau.v2 a un export	SHELL et le noyeau.v1 a export	SHELL CC GCC.

16. diff noyau.v1 noyau.v2 > update.patch
**patch noyau.v1 update.patch**
**diff noyau.v1 noyau.v2** (pour vérifier qu'ils sont bien patcher donc sont devenus identiques)






