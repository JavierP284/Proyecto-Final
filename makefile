INCLUDE_PATH = -Iinclude -Iotralib
LIB_PATH = -LC:\msys64\mingw64\lib
LIBS = -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -w -Wl,-subsystem,windows
SDL = $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) $(FLAGS)

bin/juego : src/main.cpp
	g++ $< -o $@ $(SDL)

run : bin/juego
	./bin/juego
