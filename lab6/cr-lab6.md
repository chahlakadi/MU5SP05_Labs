# Lab6: Variables d'environnements

1. env 
$HOME

2. echo $PATH

3. touch lab6.sh

- la commande qui permet la liste des process en cours d'exécution: 

**ps -aux** 
./lab6.sh
 chmod +x lab6.sh 

4. Pour déplacer le script dans le répertoire opt:

**cd /opt**
- (/opt - fournit un emplacement pour des applications optionnelles pouvant y être installées)

sudo mv ~/Desktop/lab6/lab6.sh /opt/

5. La commande qui permet à l'utilisateur d'exécuter à partir de n'importe quel endroit:

 **echo $PATH**
 **export PATH=$PATH:/opt**
 **echo $PATH**

ls /opt/
 ls -lrt /opt/
 chmod u+x /opt/lab6.sh 
 ls -lrt /opt/

6. En fermant le terminal et relancer le script (lab6.sh) on obtient un script vide .

7. le fichier script qui s'exécute automatiquement lors du démarrage du nouveau terminal c'est .bashrc qui est un fichier caché.
- On lance avec vim .bashrc et on rajoute dedans la commande export PATH="/opt:$PATH" pour que le script soit accessible de manière permanente.

8. Maintenant on peut relancer le script à partir de notre répertoire $HOME directement avec : 
**lab6.sh** (sans mettre ./lab6.sh)


