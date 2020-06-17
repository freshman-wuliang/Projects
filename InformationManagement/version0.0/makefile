all : main clean

main : data_operation.o main.o menu.o part7.o
	gcc -o main data_operation.o main.o menu.o part7.o

main.o : main.c menu.h part7.h
	gcc -c main.c

menu.o : menu.c menu.h
	gcc -c menu.c

part7.o : part7.c part7.h
	gcc -c part7.c

data_operation.o : data_operation.c data_operation.h
	gcc -c data_operation.c

.PHONY : clean

clean :
	rm data_operation.o main.o menu.o part7.o
