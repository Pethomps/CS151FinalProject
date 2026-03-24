CFLAGS = g++ -Wall -std=c++17 -pedantic-errors

game: obj/main.o obj/game.o
	$(CFLAGS) obj/main.o obj/game.o -o game
obj/main.o: src/main.cpp header/game.h
	$(CFLAGS) -c src/main.cpp -o obj/main.o
obj/game.o: src/game.cpp header/game.h
	$(CFLAGS) -c src/game.cpp -o obj/game.o
clear: 
	rm -r obj/*.o
