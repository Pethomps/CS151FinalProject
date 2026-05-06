CFLAGS = g++ -Wall -std=c++17 -pedantic-errors 
#obj/game.o obj/button.o obj/target.o obj/weapon.o obj/welcome.o obj/play.o obj/results.o obj/states.o obj/background.o
game: obj/main.o obj/background.o obj/button.o obj/GameOver.o \
      obj/game.o obj/weapon.o obj/target.o obj/welcome.o \
      obj/play.o obj/results.o obj/states.o obj/Music.o \
	  obj/Sound.o obj/rules.o
	$(CFLAGS) $^ -o game -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	./game

obj/main.o: src/main.cpp header/game.h | obj
	$(CFLAGS) -c src/main.cpp -o obj/main.o

obj/game.o: src/game.cpp header/game.h | obj
	$(CFLAGS) -c src/game.cpp -o obj/game.o

obj/button.o: src/button.cpp header/button.h | obj
	$(CFLAGS) -c src/button.cpp -o obj/button.o

obj/target.o: src/target.cpp header/target.h | obj
	$(CFLAGS) -c src/target.cpp -o obj/target.o

obj/weapon.o: src/weapon.cpp header/weapon.h | obj
	$(CFLAGS) -c src/weapon.cpp -o obj/weapon.o

obj/welcome.o: src/welcome.cpp header/welcome.h | obj
	$(CFLAGS) -c src/welcome.cpp -o obj/welcome.o

obj/play.o: src/play.cpp header/play.h | obj
	$(CFLAGS) -c src/play.cpp -o obj/play.o

obj/results.o: src/results.cpp header/results.h | obj
	$(CFLAGS) -c src/results.cpp -o obj/results.o

obj/states.o: src/states.cpp header/states.h | obj
	$(CFLAGS) -c src/states.cpp -o obj/states.o

obj/background.o: src/background.cpp header/background.h | obj
	$(CFLAGS) -c src/background.cpp -o obj/background.o

obj/GameOver.o: src/GameOver.cpp header/GameOver.h | obj
	$(CFLAGS) -c src/GameOver.cpp -o obj/GameOver.o

obj/rules.o: src/rules.cpp header/rules.h | obj
	$(CFLAGS) -c src/rules.cpp -o obj/rules.o

obj/Sound.o: src/Sound.cpp header/Sound.h | obj
	$(CFLAGS) -c src/Sound.cpp -o obj/Sound.o

obj/Music.o: src/Music.cpp header/Music.h | obj
	$(CFLAGS) -c src/Music.cpp -o obj/Music.o


TESTS/test: TESTS/test.o TESTS/catch_amalgamated.o obj/button.o obj/background.o obj/GameOver.o obj/target.o
	$(CFLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

TESTS/test.o: TESTS/test.cpp TESTS/catch_amalgamated.hpp src/button.cpp src/background.cpp src/GameOver.cpp
	$(CFLAGS) -c $< -o $@

TESTS/catch_amalgamated.o: TESTS/catch_amalgamated.cpp TESTS/catch_amalgamated.hpp
	$(CFLAGS) -c $< -o $@

obj:
	mkdir -p $@
clean: 
	rm -r obj/*.o game 


################################################
#             Mac OS Compatible                #
################################################
# CFLAGS = g++ -Wall -std=c++17 -pedantic-errors

# SFML_INCLUDE = -I$(shell brew --prefix sfml)/include
# SFML_LIB = -L$(shell brew --prefix sfml)/lib

# game: obj/main.o obj/background.o obj/button.o obj/weapon.o obj/target.o
# 	$(CFLAGS) $(SFML_INCLUDE) $^ -o game $(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# obj/main.o: src/main.cpp header/game.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/main.cpp -o obj/main.o

# obj/game.o: src/game.cpp header/game.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/game.cpp -o obj/game.o

# obj/button.o: src/button.cpp header/button.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/button.cpp -o obj/button.o

# obj/background.o: src/background.cpp header/background.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/background.cpp -o obj/background.o
# obj/weapon.o: src/weapon.cpp header/weapon.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/weapon.cpp -o obj/weapon.o

# obj/target.o: src/target.cpp header/target.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/target.cpp -o obj/target.o

# game: obj/main.o obj/background.o obj/button.o obj/weapon.o obj/target.o
# 	$(CFLAGS) $(SFML_INCLUDE) $^ -o game $(SFML_LIB) -lsfml-graphics -lsfml-window -lsfml-system

# obj/main.o: src/main.cpp header/game.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/main.cpp -o obj/main.o

# obj/game.o: src/game.cpp header/game.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/game.cpp -o obj/game.o

# obj/button.o: src/button.cpp header/button.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/button.cpp -o obj/button.o

# obj/background.o: src/background.cpp header/background.h | obj
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/background.cpp -o obj/background.o
# obj/weapon.o: src/weapon.cpp header/weapon.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/weapon.cpp -o obj/weapon.o

# obj/target.o: src/target.cpp header/target.h
# 	$(CFLAGS) $(SFML_INCLUDE) -c src/target.cpp -o obj/target.o

# obj/GameOver.o: src/GameOver.cpp header/GameOver.h | obj
# 	$(CFLAGS) -c src/GameOver.cpp -o obj/GameOver.o

# obj/rules.o: src/rules.cpp header/rules.h | obj
# 	$(CFLAGS) -c src/rules.cpp -o obj/rules.o

# obj/Sound.o: src/Sound.cpp header/Sound.h | obj
# 	$(CFLAGS) -c src/Sound.cpp -o obj/Sound.o

# obj/Music.o: src/Music.cpp header/Music.h | obj
# 	$(CFLAGS) -c src/Music.cpp -o obj/Music.o


# TESTS/test: TESTS/test.o TESTS/catch_amalgamated.o obj/button.o obj/background.o obj/GameOver.o obj/target.o
# 	$(CFLAGS) $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

# TESTS/test.o: TESTS/test.cpp TESTS/catch_amalgamated.hpp src/button.cpp src/background.cpp src/GameOver.cpp
# 	$(CFLAGS) -c $< -o $@

# TESTS/catch_amalgamated.o: TESTS/catch_amalgamated.cpp TESTS/catch_amalgamated.hpp
# 	$(CFLAGS) -c $< -o $@

# obj:
# 	mkdir -p $@
# clean: 
# 	rm -f obj/*.o game game 
# clean: 
# 	rm -f obj/*.o game
