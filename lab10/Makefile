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
