all : demo clear

Objects = demo.o word.o file.o

demo : $(Objects)
	gcc -o demo $(Objects)
	
demo.o : demo.c word.h
	gcc -c demo.c
	
word.o : word.c word.h
	gcc -c word.c
	
file.o : file.c file.h
	gcc -c file.c
	
.PHONY : clear

clear : 
	del $(Objects)