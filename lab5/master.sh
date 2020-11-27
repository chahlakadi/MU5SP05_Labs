#!/bin/bash

# write a comment here
# 1st script shell
ls /home/yasma/Bureau/chahla/lab4 # pour lister les fichiers se trouvant dans le répertoire utilisé dans la partie4 et le chemin d'accès au répertoire
master_syscom="Hello Embedded Linux" # création d'une variable dans laquelle on a stocké une chaine de caractère attention à ne pas laisser d'espace avant et après =
chmod +x master.sh # cette commande sert à rajouter le droit d'exécution 
# pour pouvoir exécuter le script on fait ./le nomduscript càd: ./master.sh

#2nd script shell
read -p "first number:" nb1
read -p "second number:" nb2
# pour la comparaison des entiers on a eq por dire egal gt pour dire greater then et lt pour less then et si on veut utiliser les symboles mathematique on utilise (( )) au lieu des  [] 
#pour string comparaison on = , != >,<  entre [[]]
if [ $nb1 -lt $nb2 ]
	then 
		echo "$nb1 est inférieur à $nb2 "

elif [ $nb1 -gt $nb2 ]
	then
		echo "$nb1 est supérieur à $nb2 "
else
		echo "$nb1 egal à $nb2 "
fi

#3rd script shell
for files in /home/yasma/Bureau/chahla/lab4/*
do 
	if [ -d $files ]  		# -d $file  vérifie si un fichier existe dans un répertoire
	then 
		ls $files		# pour afficher les fichiers trouvés 
	fi
done

#4th script shell
for files in cd '/home/yasma/Bureau/chahla/lab4/sardar '
do 
   if [ -d $files ]
   then 
     ls $files
   fi
done

#5th script

for files in cd '/home/yasma/Bureau/chahla/lab4/sardar '
do 

   if [ -d $files ]
   then 
     ls $files
   else
	echo " le répertoire n'est pas valide"
   fi
done

#6th script 

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
#for i in {1..10..1}
#do
#wget view-source:https://xkcd.com/1/
#wget https://imgs.xkcd.com/comics/barrel_cropped_(1).jpg
#wget http://imgs.xkcd.com


#wget view-source:https://xkcd.com/2/

#wget https://imgs.xkcd.com/comics/tree_cropped_(1).jpg

#wget http://imgs.xkcd.com/2

#done



