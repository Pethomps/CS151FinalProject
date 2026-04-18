CFLAGS = g++ -Wall -std=c++17 -pedantic-errors 
#obj/game.o obj/button.o obj/target.o obj/weapon.o obj/welcome.o obj/play.o obj/results.o obj/states.o obj/background.o
game: obj/main.o obj/background.o obj/button.o obj/GameOver.o
	$(CFLAGS) $^ -o game -lsfml-graphics -lsfml-window -lsfml-system

obj/main.o: src/main.cpp header/game.h
	$(CFLAGS) -c src/main.cpp -o obj/main.o

obj/game.o: src/game.cpp header/game.h
	$(CFLAGS) -c src/game.cpp -o obj/game.o

obj/button.o: src/button.cpp header/button.h
	$(CFLAGS) -c src/button.cpp -o obj/button.o

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

obj/background.o: src/background.cpp header/background.h
	$(CFLAGS) -c src/background.cpp -o obj/background.o

obj/GameOver.o: src/GameOver.cpp header/GameOver.h
	$(CFLAGS) -c src/GameOver.cpp -o obj/GameOver.o

TESTS/test: TESTS/test.o TESTS/catch_amalgamated.o obj/button.o obj/background.o obj/GameOver.o
	$(CFLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

TESTS/test.o: TESTS/test.cpp TESTS/catch_amalgamated.hpp src/button.cpp src/background.cpp src/GameOver.cpp
	$(CFLAGS) -c $< -o $@

TESTS/catch_amalgamated.o: TESTS/catch_amalgamated.cpp TESTS/catch_amalgamated.hpp
	$(CFLAGS) -c $< -o $@


clean: 
	rm -r obj/*.o
