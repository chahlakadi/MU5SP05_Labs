# Lab5: Shell -Script

1. La création d'un fichier master.sh et on rajoute le type de shell qu'on utilise avec **#!/bin/bash**


### 1st script shell

- pour lister les fichiers se trouvant dans le répertoire utilisé dans la partie4 et le chemin d'accès au répertoire

ls /home/yasma/Bureau/chahla/lab4 

- création d'une variable dans laquelle on a stocké une chaine de caractère attention à ne pas laisser d'espace avant et après =

master_syscom="Hello Embedded Linux" 

- pour pouvoir exécuter le script on fait ./le nomduscript càd: ./master.sh

chmod +x master.sh # cette commande sert à rajouter le droit d'exécution 


### 2nd script shell

- pour la comparaison des entiers on a eq por dire egal gt pour dire greater then et lt pour less then et si on veut utiliser les symboles mathematique on utilise (( )) au lieu des  [] 

```bash
read -p "first number:" nb1
read -p "second number:" nb2

if [ $nb1 -lt $nb2 ]
	then 
		echo "$nb1 est inférieur à $nb2 "

elif [ $nb1 -gt $nb2 ]
	then
		echo "$nb1 est supérieur à $nb2 "
else
		echo "$nb1 egal à $nb2 "
fi
```
### 3rd script shell

```bash
for files in /home/yasma/Bureau/chahla/lab4/*
do 
	if [ -d $files ]  		#(-d $file  vérifie si un fichier existe dans un repertoire)
	then 
		ls $files		# pour afficher les fichiers trouvés 
	fi
done
```
### 4th script shell

```bash
for files in cd '/home/yasma/Bureau/chahla/lab4/sardar '
do 
   if [ -d $files ]
   then 
     ls $files
   fi
done
```
### 5th script

```bash
for files in cd '/home/yasma/Bureau/chahla/lab4/sardar '
do 

   if [ -d $files ]
   then 
     ls $files
   else
	echo " le répertoire n'est pas valide"
   fi
done
```

### 6th script 

```bash
mkdir picture
count=1
while [ $count -le $1 ]
do 
	wget "https://xkcd.com/$count"
	url=$(grep -o "http.*jpg" $count)
	wget $url > "./picture/$count"
	count=$((count+1))
done
eog ./picture

```
