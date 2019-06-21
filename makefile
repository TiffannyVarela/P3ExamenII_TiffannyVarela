main.out: main.o Militar.o NodoArbol.o
	g++ main.o Militar.o NodoArbol.o -lncurses -o main.out
main.o: main.cpp Militar.cpp NodoArbol.cpp
	g++ -c main.cpp