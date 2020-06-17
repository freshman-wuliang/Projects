all : main clean

main :  main.o menu.o
	gcc -o main  main.o menu.o

main.o : main.c menu.h
	gcc -c main.c

menu.o : menu.c menu.h
	gcc -c menu.c

.PHONY : clean

clean :
	rm main.o menu.o
