all: bin/main

bin/main: obj/main.o obj/point.o obj/UI.o obj/gfx.o
	g++ -Wall -Werror obj/main.o obj/point.o obj/UI.o obj/gfx.o -o bin/main -lm -lX11

obj/main.o: src/main.cpp 
	g++ -I include -Wall -Werror -c src/main.cpp -o obj/main.o -lX11

obj/point.o: src/point.cpp
	g++ -I include -Wall -Werror -c src/point.cpp -o obj/point.o -lm

obj/gfx.o: src/gfx.cpp
	g++ -I include -Wall -Werror -c src/gfx.cpp -o obj/gfx.o -lm -lX11

obj/UI.o: src/UI.cpp
	g++ -I include -Wall -Werror -c src/UI.cpp -o obj/UI.o -lX11

clear:
	rm -rf obj/*.o bin/main