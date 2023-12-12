mapTest : main.o Map.o
	g++ main.o Map.o -o mapTest -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	g++ -c main.cpp

Map.o : Map.cpp Map.h
	g++ -c Map.cpp
