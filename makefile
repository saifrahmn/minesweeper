all:
	g++ -Iinclude -Iinclude/sdl -LC:\SDL2-w64\lib -o Main src/*.cpp -lmingw32 -lSDLmain -lSDL