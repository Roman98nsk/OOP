all: bin/main

bin/main: obj/main.o obj/gfx.o obj/figure.o obj/UI.o
	g++ -Wall -Werror obj/main.o obj/gfx.o obj/figure.o obj/UI.o -o bin/main -lm -lX11

obj/main.o: src/main.cpp include/figure.h include/UI.h
	g++ -I include -Wall -Werror -c src/main.cpp -o obj/main.o -lm -lX11

obj/gfx.o: src/gfx.cpp
	g++ -I include -Wall -Werror -c src/gfx.cpp -o obj/gfx.o -lm -lX11

obj/figure.o: src/figure.cpp include/figure.h
	g++ -I include -Wall -Werror -c src/figure.cpp -o obj/figure.o -lm -lX11

obj/UI.o: src/UI.cpp include/UI.h include/figure.h
	g++ -I include -Wall -Werror -c src/UI.cpp -o obj/UI.o -lX11

clear:
	rm -rf obj/*.o bin/main