#TO USE THE MAKEFILE IN TERMINAL, GET INTO THE RIGHT DIRECTORY AND TYPRE "make"

main: calc.o main.o
	gcc -std=c11 -Wall -Wextra calc.o main.o -o main

main.o: calc.h main.c
	gcc -std=c11 -Wall -Wextra -c main.c -o main.o

calc.o: calc.c
	gcc -std=c11 -Wall -Wextra -c calc.c -o calc.o

clean:
	rm main main.o calc.o
