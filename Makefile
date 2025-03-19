all:
	g++ main.cpp -L src/lib -I src/include -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main