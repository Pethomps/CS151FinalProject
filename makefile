# CFLAGS = g++ -Wall -std=c++17 -pedantic-errors 
# SFML_INCLUDE = -I$(shell brew --prefix sfml)/include
# SFML_LIB = -L$(shell brew --prefix sfml)/lib

# #obj/game.o obj/button.o obj/target.o obj/weapon.o obj/welcome.o obj/play.o obj/results.o obj/states.o obj/background.o
# game: obj/main.o obj/background.o obj/button.o
# 	$(CFLAGS) $^ -o game -lsfml-graphics -lsfml-window -lsfml-system

# obj/main.o: src/main.cpp header/game.h
# 	$(CFLAGS) -c src/main.cpp -o obj/main.o

# obj/game.o: src/game.cpp header/game.h
# 	$(CFLAGS) -c src/game.cpp -o obj/game.o

# obj/button.o: src/button.cpp header/button.h
# 	$(CFLAGS) -c src/button.cpp -o obj/button.o

# obj/target.o: src/target.cpp header/target.h
# 	$(CFLAGS) -c src/target.cpp -o obj/target.o

# obj/weapon.o: src/weapon.cpp header/weapon.h
# 	$(CFLAGS) -c src/weapon.cpp -o obj/weapon.o

# obj/welcome.o: src/welcome.cpp header/welcome.h
# 	$(CFLAGS) -c src/welcome.cpp -o obj/welcome.o

# obj/play.o: src/play.cpp header/play.h
# 	$(CFLAGS) -c src/play.cpp -o obj/play.o

# obj/results.o: src/results.cpp header/results.h
# 	$(CFLAGS) -c src/results.cpp -o obj/results.o

# obj/states.o: src/states.cpp header/states.h
# 	$(CFLAGS) -c src/states.cpp -o obj/states.o

# obj/background.o: src/background.cpp header/background.h
# 	$(CFLAGS) -c src/background.cpp -o obj/background.o
CFLAGS = g++ -Wall -std=c++17 -pedantic-errors

SFML_INCLUDE = -I$(shell brew --prefix sfml)/include
SFML_LIB = -L$(shell brew --prefix sfml)/lib

game: obj/main.o obj/background.o obj/button.o obj/weapon.o obj/target.o
	$(CFLAGS) $(SFML_INCLUDE) $^ -o game $(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

obj/main.o: src/main.cpp header/game.h
	$(CFLAGS) $(SFML_INCLUDE) -c src/main.cpp -o obj/main.o

obj/game.o: src/game.cpp header/game.h
	$(CFLAGS) $(SFML_INCLUDE) -c src/game.cpp -o obj/game.o

obj/button.o: src/button.cpp header/button.h
	$(CFLAGS) $(SFML_INCLUDE) -c src/button.cpp -o obj/button.o

obj/background.o: src/background.cpp header/background.h
	$(CFLAGS) $(SFML_INCLUDE) -c src/background.cpp -o obj/background.o
obj/weapon.o: src/weapon.cpp header/weapon.h
	$(CFLAGS) $(SFML_INCLUDE) -c src/weapon.cpp -o obj/weapon.o

obj/target.o: src/target.cpp header/target.h
	$(CFLAGS) $(SFML_INCLUDE) -c src/target.cpp -o obj/target.o

clean: 
	rm -f obj/*.o game
