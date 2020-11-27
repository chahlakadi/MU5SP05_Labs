# Lab2: Git 

## Installation des git packages avec la commande :

*sudo apt install git kit-email*

## Git configuration 

**git config --global user.name " Kadi_chahla "**
**git config --global user.email " k.chahla@yahoo.com "**

1. Création d'un répertoire que j'ai appelé lab2 avec la commande suivante:

**mkdir lab2**

2. Dans le répertoire *lab2*  on crée un fichier nom de famille et on écrit dedans hello M2 syscom avec les commandes suivantes:

**cd lab2**
**touch Kadi.txt**
**echo " hello M2 syscom " > Kadi.txt**

3. On mentionne que ce répertoire est un git repository avec la commande:

**git init**

4. Pour voir l'état du fichier on utilise la commande:

**git status**

5. pour rajouter le fichier on utilise la commande:

**git add .**

- maintenant on retappe la commande *git status* pour vérifier si le fichier a bien été rajouter à l'index ou pas!

6. utilisation de la commande:

**git commit -m "lab2"**

7. Créeation d'un compte sur le site git hub et un nouveau repository.

8. Connection du local repository au remote repository avec la commande :

**git remote add origin https://github.com/chahlakadi/lab2.git**
**git push -u origin master**

9. création d'un README.md sur le compte git hub et mettre un message dedans 

10. Pour mettre à jour le répertoire locale on utilise la commande:

**git pull**

11. Dans $HOME création d'un clone du répertoire qu'on a déjà créé avec la commande: 

**git clone https://github.com/chahlakadi/lab2.git**


