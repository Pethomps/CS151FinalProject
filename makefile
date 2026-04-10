CFLAGS = g++ -Wall -std=c++17 -pedantic-errors

game: obj/main.o obj/game.o
	$(CFLAGS) obj/main.o obj/game.o -o game

obj/main.o: src/main.cpp header/game.h
	$(CFLAGS) -c src/main.cpp -o obj/main.o

obj/game.o: src/game.cpp header/game.h
	$(CFLAGS) -c src/game.cpp -o obj/game.o

obj/button.o: src/button.cpp header/button.h
	$(CFLAFS) -c src/button.cpp -o obj/button.o

obj/target.o: src/target.cpp header/target.h
	$(CFLAGS) -c src/target.cpp -o obj/target.o

obj/weapon.o: src/weapon.cpp header/weapon.h
	$(CFLAGS) -c src/weapon.cpp -o obj/weapon.o

obj/welcome.o: src/welcome.cpp header/welcome.h
	$(CFLAGS) -c src/welcome.cpp -o obj/welcome.o

obj/play.o: src/play.cpp header/play.h
	$(CFLAGS) -c src/play.cpp -o obj/play.o

obj/results.o: src/results.cpp header/results.h
	$(CFLAGS) -c src/results.cpp -o obj/results.o

obj/states.o: src/states.cpp header/states.h
	$(CFLAGS) -c src/states.cpp -o obj/states.o

clear: 
	rm -r obj/*.o
