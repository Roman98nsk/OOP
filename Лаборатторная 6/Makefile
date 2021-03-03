all: bin/main

bin/main: obj/list.o obj/main.o
	g++ -Wall -Werror obj/main.o obj/list.o -o bin/main

obj/main.o: include/list.h src/main.cpp
	g++ -I include -c src/main.cpp -o obj/main.o

obj/list.o: include/list.h src/list.cpp
	g++ -I include -c src/list.cpp -o obj/list.o

clean:
	rm -rf obj/*.o bin/main
