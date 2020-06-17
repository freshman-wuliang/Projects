all : jisuanqi clean

jisuanqi : main.o menu.o part1.o part2.o\
	   part3.o part4.o part5.o
	gcc -o jisuanqi main.o menu.o part1.o part2.o \
		part3.o part4.o part5.o -lm

main.o : main.c menu.h part1.h part2.h \
	 part3.h part4.h part5.h
	gcc -c main.c -lm

menu.o : menu.c menu.h
	gcc -c menu.c -lm

part1.o : part1.c part1.h
	gcc -c part1.c -lm

part2.o : part2.c part2.h
	gcc -c part2.c -lm

part3.o : part3.c part3.h
	gcc -c part3.c -lm

part4.o : part4.c part4.h
	gcc -c part4.c -lm

part5.o : part5.c part5.h
	gcc -c part5.c -lm

.PHONY : clean

clean:
	rm main.o menu.o part1.o part2.o \
		part3.o part4.o part5.o
