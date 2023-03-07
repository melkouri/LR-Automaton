CC = g++

TARGET = main

main: main.o Automate.o lexer.o symbole.o Etat.o
	$(CC) -o main main.o Automate.o lexer.o symbole.o Etat.o -g

Automate.o: Automate.cpp Automate.h Etat.h symbole.h
	$(CC) -c Automate.cpp

lexer.o: lexer.cpp lexer.h symbole.h
	$(CC) -c lexer.cpp

main.o: main.cpp lexer.h
	$(CC) -c main.cpp

Etat.o: Etat.cpp Etat.h Automate.h
	$(CC) -c Etat.cpp

symbole.o: symbole.cpp symbole.h
	$(CC) -c symbole.cpp

clean:
	rm *.o main
