all: bin/main

bin/main: obj/main.o obj/coleccion.o obj/punto.o obj/satelite.o 
	g++ -o bin/main -std=c++11 obj/main.o obj/coleccion.o obj/punto.o obj/satelite.o 
obj/main.o: src/main.cpp include/coleccion.h include/Punto.h include/satelite.h
	g++ -c -std=c++11 -Iinclude -o obj/main.o src/main.cpp 
obj/coleccion.o: src/coleccion.cpp include/coleccion.h include/Punto.h
	g++ -c -std=c++11 -Iinclude -o obj/coleccion.o src/coleccion.cpp 
obj/punto.o: src/Punto.cpp include/Punto.h
	g++ -c -std=c++11 -Iinclude -o obj/punto.o src/Punto.cpp 
obj/satelite.o: src/satelite.cpp include/satelite.h
	g++ -c -std=c++11 -Iinclude -o obj/satelite.o src/satelite.cpp 
clean:
	rm -f obj/*
mrproper: clean 
	rm -f bin/*