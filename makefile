INCLUDE_PATH = -IC:\msys64\mingw64\include\SDL2
LIB_PATH = -LC:\msys64\mingw64\lib
LIBS = -lmingw32 -lSDL2main -lSDL2
FLAGS = -w -Wl,-subsystem,windows
SDL = $(INCLUDE_PATH) $(LIB_PATH) $(LIBS) $(FLAGS)

bin/juego : src/main.cpp
	g++ $< -o $@ $(SDL)

run : bin/juego
	./bin/juego
