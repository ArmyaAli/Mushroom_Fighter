all:
	gcc src/main.c -o main.exe -O1 -Wall -std=c99 -Wno-missing-brances -I src/include/ -I raylib/include/ -L raylib/lib/ -lraylib -lopengl32 -lgdi32 -lwinmm